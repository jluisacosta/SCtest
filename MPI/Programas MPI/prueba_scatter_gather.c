/*
	PROGRAMA: Prueba de funcionamiento de MPI_Scatterv y MPI_Gatherv.
	MATERIA: Supercomputo.
	AUTOR: Jose Luis Acosta Zamora (173025).
	FECHA: 13 Octubre 2014.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int* crea_arreglo(int n);
void imprime_arreglo(int n,int* vector);
int dame_tam_bloque(int N,int n,int numProc,int id);

main(int argc, char *argv[])
{
	int N = atoi(*(argv+1)),id,numProc,n,tam_bloque,i,p;
	int *A,*arr_desp,*arr_cuenta,*fragA;
	MPI_Status status;
	srand(time(NULL));
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProc);

	if(numProc<=N)
	{
		if(N>0)
		{
			if(id == 0)
			{
				n = N/numProc;
				A = crea_arreglo(N);
				arr_cuenta = (int*)malloc(sizeof(int)*numProc);
				arr_desp = (int*)malloc(sizeof(int)*numProc);
				
				printf("\n\"EJEMPLO DE UTILIZACION DE MPI_Scatterv y MPI_Gatherv\"\n");
				printf("\n> SE ENVIA: A = ");
				imprime_arreglo(N,A);

				for(p=0;p<numProc;p++)
				{
					*(arr_desp+p) = p*n;
					*(arr_cuenta+p) = dame_tam_bloque(N,n,numProc,p);
				}

				printf("\n> Desplazamientos (arr_desp): ");
				imprime_arreglo(numProc,arr_desp);
				printf("\n> Cuenta (arr_cuenta): ");
				imprime_arreglo(numProc,arr_cuenta);
			}
		
			MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
			tam_bloque = dame_tam_bloque(N,n,numProc,id);
			fragA = (int*)malloc(tam_bloque*sizeof(int));
			MPI_Scatterv(A,arr_cuenta,arr_desp,MPI_INT,fragA,tam_bloque,MPI_INT,0,MPI_COMM_WORLD);
			printf("\n  -Proceso %d recibe el fragmento de A : ",id);
			imprime_arreglo(tam_bloque,fragA);
		
			for(i=0;i<tam_bloque;i++)
			{
				*(fragA+i) = (*(fragA+i))+id;
			}

			MPI_Gatherv(fragA,tam_bloque,MPI_INT,A,arr_cuenta,arr_desp, MPI_INT, 0, MPI_COMM_WORLD);
		
			if(id == 0)
			{
				printf("\n> PROCESO %d REUNE EL RESULTADO: A = ",id);
				imprime_arreglo(N,A);
				printf("\n");
			}
		}
	}
	else if(id == 0)
	{
		printf("\n ERROR! -> EL NUMERO DE PROCESOS ES MAYOR AL TOTAL DE DATOS!!\n\n");
	}

	MPI_Finalize();
}

int* crea_arreglo(int n)
{
	int *a, i;

	a = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;*(a+i)=(rand()%n),i++);
	return a;
}

void imprime_arreglo(int n,int* arreglo)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(*(arreglo+i)>=0)
		{
			printf("%d ",*(arreglo+i));
		}
	}
	printf("\n");
}

int dame_tam_bloque(int N,int n,int numProc,int id)
{
	int aux = n;

	if(id == (numProc-1) && N%numProc > 0)
	{
		aux = N-(id*n);
	}

	return aux;
}
