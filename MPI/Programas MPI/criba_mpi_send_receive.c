/*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int* crea_arreglo(int n);
void imprime_arreglo(int n,int* vector);

main(int argc, char *argv[])
{
	int N = atoi(argv[1])-1,id,numProc,n,aux,p,tag = 0;
	int indx_i,indx_j,i,j,desp;
	int *tabla,*primos;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProc);
	
	if(N>0)
	{
		if(id == 0)
		{
			n = aux = N/(numProc-1);
			tabla = crea_arreglo(N);
			primos = crea_arreglo(N);
			
			MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
			MPI_Bcast(tabla,N,MPI_INT,0,MPI_COMM_WORLD);
			printf("\nProceso %d envia: ",id);
			imprime_arreglo(N,tabla);

			for(p=1;p<numProc;p++)
			{
				if(p == (numProc-1) && N%(numProc-1) > 0)
				{
					aux = N-(p*n)+n;
				}
				
				MPI_Send(&aux, 1, MPI_INT, p, tag, MPI_COMM_WORLD);
				MPI_Send((primos+((p-1)*n)), aux, MPI_INT, p, tag, MPI_COMM_WORLD);
			}

			aux = n;
		
			for(p=1; p<numProc; p++)
			{
				if(p == (numProc-1) && N%(numProc-1) > 0)
				{
					aux = N-(p*n)+n;
				}

				MPI_Recv((primos +((p-1)*n)), aux, MPI_INT, p, tag, MPI_COMM_WORLD, &status);
			}
			
			printf("\nRESULADO: ");
			imprime_arreglo(N,primos);
		}
		else
		{
			tabla=(int*)malloc(sizeof(int)*(N));
			MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
			MPI_Bcast(tabla,N,MPI_INT,0,MPI_COMM_WORLD);
			printf("\nProceso %d recibe: ",id);
			imprime_arreglo(N,tabla);
			
			MPI_Recv(&aux, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
			primos=(int*)malloc(sizeof(int)*aux);
			MPI_Recv(primos, aux, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
			printf("Porcion a marcar: ");
			imprime_arreglo(aux,primos);
			desp = (id-1)*n;
			//printf("\nDESP: %d \n",desp);

			for(indx_i = 0;*(tabla+indx_i) <= (int)sqrt(N);indx_i++)
			{
				i = *(tabla+indx_i);
				//printf("\nProceso %d indx_i=%d *(tabla+indx_i)=%d.\n",id,indx_i,i);

				for(indx_j = desp;indx_j < desp+aux;indx_j++)
				{
					j = *(tabla+indx_j);
					//printf("\n    Proceso %d indx_j=%d *(tabla+indx_j)=%d desp+aux=%d.\n",id,indx_j,j,desp+aux);
					
					if(i!=j && j%i == 0)	//Si no ha sido marcado
					{
						*(primos+(indx_j-desp))=-1; //Se marca
						//printf("[%d X] ",j);
					}
				}
				//printf("\n");
			}

			printf("Primos obtenidos: ");
			imprime_arreglo(aux,primos);
			MPI_Send(primos, aux, MPI_INT, 0, tag, MPI_COMM_WORLD);
		}
	}

	MPI_Finalize();
}

int* crea_arreglo(int n)
{
	int *a, i;

	a = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;*(a+i)=(i+2),i++);
	return a;
}

void imprime_arreglo(int n,int* arreglo)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(*(arreglo+i)>0)
		{
			printf("%d ",*(arreglo+i));
		}
	}
	printf("\n");
}
