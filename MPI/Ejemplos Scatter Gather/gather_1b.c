/*
 * Ejemplo 3b. Cada proceso contribuye con un numero de datos 
 * proporcionado por el usuario
 * a traves de la linea de comandos
 *
 * mpirun -np N arch_ejecutable numDatosLocal
 */
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main( int argc,char *argv[] ){  
	int j,myId,numProcs;
	int *sendbuf,root=0,numDatosLocal;
	int *recvbuf;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs); 
		
	numDatosLocal= atoi( argv[1]);
	sendbuf=(int*) malloc(numDatosLocal*sizeof(int));
	// cuidar que exista memoria suficiente
	// ...
	for(j=0;j<numDatosLocal;j++)
		sendbuf[j]=myId; 
	
	if(myId==root) {
		recvbuf=(int*) malloc(numDatosLocal*numProcs*sizeof(int));
		// cuidar que exista memoria suficiente
		// ...
	}	
	MPI_Gather(sendbuf,numDatosLocal,MPI_INT,recvbuf,numDatosLocal, MPI_INT, root, MPI_COMM_WORLD);	

	if(myId==root){
		for(j=0;j<numDatosLocal*numProcs;j++)
			printf(" %d, ",recvbuf[j]);    
		printf("\n");
	}
		
	//}else if(myId==0) printf("\nDebe llamarse a 5 procesos\n");

	MPI_Finalize();
	return 0;
}

