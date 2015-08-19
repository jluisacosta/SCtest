#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main( ){  
	int j,myId,numProcs,root;
	int *sendbuf;
	int *recvbuf;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
    root=0;   
    if(myId==root){
		sendbuf=(int*)malloc(2*numProcs*sizeof(int));
		printf("\nEn el ROOT==>  ");
		for(j=0;j<2*numProcs;j++){
			sendbuf[j]=j;
			printf("%d,",sendbuf[j]);
		}
		printf("\n\nDespues del SCATTER\n");
	}
	recvbuf=(int*)malloc(2*sizeof(int));

	MPI_Scatter(sendbuf,2,MPI_INT,recvbuf,2, MPI_INT, root, MPI_COMM_WORLD);	

	printf("\n\t[rank= %d]  Valores recibidos: %d, %d \n",myId,recvbuf[0],recvbuf[1]);    
		
	MPI_Finalize();
	return 0;
}

