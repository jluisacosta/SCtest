/* Ejemplo 3a. Se recolecta un valor entero desde cada proceso, 
 * el listado obtenido se guarda en el proceso root.
 * 
 * */
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main( ){  
	int j,myId,numProcs,errorCode;
	int sendbuf, root;
	int *recvbuf;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
    root=numProcs-1;    
    sendbuf = myId;
	if(myId==root){
		recvbuf= (int*)malloc(numProcs*sizeof(int));
		if(recvbuf==NULL){ 
			printf("NO hay memoria suficiente \n");
			errorCode=1;
			MPI_Abort(MPI_COMM_WORLD,errorCode);
		}
	}
	
	MPI_Gather(&sendbuf,1,MPI_INT,recvbuf,1, MPI_INT, root, MPI_COMM_WORLD);	

	if(myId==root) {
		for(j=0;j<numProcs;j++)
			printf(" %d, ",recvbuf[j]);    
		printf("\n");
	}	
	
	MPI_Finalize();
	return 0;
}

