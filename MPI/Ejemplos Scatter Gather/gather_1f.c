#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(  ){  
	int  n,j,myId,numProcs,chunk,numDatos,root=0;
	int *recvcnts,*displs;
	int *sendbuf;
	int *recvbuf;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
        
    	chunk=myId+1;	 // num de datos de cada proceso	
		sendbuf=(int*)malloc(chunk*sizeof(int));
		// cuidar que exista memoria suficiente
		// ...	
		for(j=0;j<chunk;j++)
				sendbuf[j]=myId;			
		
		if(myId==root){
			recvcnts=(int*)malloc(numProcs*sizeof(int));			
			// cuidar que exista memoria suficiente
			// ...	
		}
		// recolectando el <chunk>, para llenar el arreglo <displs>
		MPI_Gather(&chunk,1,MPI_INT,recvcnts,1,MPI_INT,root,MPI_COMM_WORLD);
		
		if(myId==root){
			// llenando el arreglo <displs>
			displs=(int*)malloc(numProcs*sizeof(int));
			// cuidar que exista memoria suficiente
			// ...	
			displs[0]=0;
			// obteniendo el num de datos total,para que el proceso root pida memoria
			numDatos=recvcnts[0];
			for(j=1;j<numProcs;j++){ 
				displs[j]= displs[j-1]+recvcnts[j-1];
				numDatos+= recvcnts[j];
			}			
			recvbuf=(int*)malloc(numDatos*sizeof(int));
			// cuidar que exista memoria suficiente
			// ...	
		}
		MPI_Gatherv(sendbuf,chunk,MPI_INT,recvbuf,recvcnts,displs, MPI_INT, root, MPI_COMM_WORLD);	

		if(myId==root){
			for(j=0;j<numDatos  ;j++)
				printf("%d,",recvbuf[j]);
			printf("\n");
		}
						
	MPI_Finalize();
	return 0;
}
