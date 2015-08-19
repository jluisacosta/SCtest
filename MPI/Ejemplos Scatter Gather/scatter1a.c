#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main( ){  
	int j,myId,numProcs,root=0;
	int *sendbuf;
	int recvbuf;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
        
    if(myId==root){
		sendbuf=(int*)malloc(numProcs*sizeof(int));
		printf("\nEn el ROOT==>  ");
		for(j=0;j<numProcs;j++){
			sendbuf[j]=j;
			printf("%d,",sendbuf[j]);
		}
		printf("\n\nDespues del SCATTER\n");
	}
	
	MPI_Scatter(sendbuf,1,MPI_INT,&recvbuf,1, MPI_INT, root, MPI_COMM_WORLD);	
	printf("\t [myID= %d]  Valor recibido: %d\n",myId,recvbuf);    
		
	MPI_Finalize();
	return 0;
}

