#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(  ){  
	int  n,j,myId,numProcs,chunk,numDatos;
	int *recvcnts,*displs;
	int *sendbuf;
	int *recvbuf;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
        
    	chunk=myId+1;		
		sendbuf=(int*)malloc(chunk*sizeof(int));
		for(j=0;j<chunk;j++)
				sendbuf[j]=myId;			
		
		if(myId==0){
			recvcnts=(int*)malloc(numProcs*sizeof(int));	
			// cuidar que exista memoria suficiente
			// ...		
			displs=(int*)malloc(numProcs*sizeof(int));	
			// cuidar que exista memoria suficiente
			// ...					
		}
		MPI_Gather(&chunk,1,MPI_INT,recvcnts,1,MPI_INT,0,MPI_COMM_WORLD);
		
		MPI_Reduce(&chunk,&numDatos,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		
		if(myId==0){
			displs[0]=0;
			for(j=1;j<numProcs;j++) displs[j]= displs[j-1]+recvcnts[j-1];
			recvbuf=(int*)malloc(numDatos*sizeof(int));
			// cuidar que exista memoria suficiente
			// ...	
		}
		MPI_Gatherv(sendbuf,chunk,MPI_INT,recvbuf,recvcnts,displs, MPI_INT, 0, MPI_COMM_WORLD);	

		if(myId==0){
			for(j=0;j<numDatos  ;j++)
				printf("%d,",recvbuf[j]);
		}
						
	MPI_Finalize();
	return 0;
}
