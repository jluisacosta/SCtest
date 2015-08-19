#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int BLOCK_LOW (int id,int p,int n) {return (id*n)/p;}
int BLOCK_HIGH(int id,int p,int n) {return BLOCK_LOW(id+1,p,n)-1;}
int BLOCK_SIZE(int id,int p,int n) {return BLOCK_HIGH(id,p,n)-BLOCK_LOW(id,p,n)+1;}
int main( int argc, char *argv[]){  
	int n,j,myId,numProcs,chunk,resto,root=0;
	int *sizes,*displs;
	int *sendbuf;
	int *recvbuf;
	

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
	
	if(argc!=2){
		if(myId==0) 
			printf("\nArgumentos que deben incluirse en la llamada:\nEjecutable datos.dat \n\n");MPI_Finalize();	return 0;
	}
    	if(myId==root){
			FILE *fp;
			fp  = fopen(argv[1],"r");
			if(fp == NULL){	
				printf("\nNo pude encontrar el archivo con nombre << %s >> \n\n",argv[1]);
				MPI_Abort(MPI_COMM_WORLD,1); 	
				return 0;    	
			}
				fscanf(fp,"%d",&n);
				printf("n=%d\n",n);
				sendbuf=(int*)malloc(n*sizeof(int));

				for(j=0;j<n;j++) 
					fscanf(fp,"%d",&sendbuf[j]);
				printf("ROOT [%d]-->{",myId);		
				for(j=0;j<n-1;j++)printf("%d,",sendbuf[j]);
				printf("%d}\n",sendbuf[j]);		
			fclose(fp);
			
			sizes=(int*)malloc(numProcs*sizeof(int));
			displs=(int*)malloc(numProcs*sizeof(int));
		}
		MPI_Bcast(&n,1,MPI_INT,root,MPI_COMM_WORLD);
	
		chunk=BLOCK_SIZE(myId,numProcs,n);
		recvbuf=(int*)malloc(chunk*sizeof(int));		
		MPI_Gather(&chunk,1,MPI_INT,sizes,1,MPI_INT,root,MPI_COMM_WORLD);

		if(myId==root){			
			displs[0]=0;
			for(j=1;j<numProcs;j++) displs[j]= displs[j-1]+sizes[j-1];
		}

		MPI_Scatterv(sendbuf,sizes,displs,MPI_INT,recvbuf, chunk , MPI_INT, root, MPI_COMM_WORLD);	
		
		printf("[%d]-->{",myId);
		for(j=0;j<chunk-1;j++)printf("%d,",recvbuf[j]);
		printf("%d}\n",recvbuf[j]);
	MPI_Finalize();
	return 0;
}
