/*
	Alumno: José Luis Acosta Zamora (173025)
	Programa: Suma de dos vectores con MPI
	Fecha: 7 de Octubre del 2014
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mpi.h"

float* creaArreglo(int n);
void imprime(char *nom, float *arr, int n);

main(int argc, char *argv[])
{
	int N = atoi(argv[1]),id,numProc,n,aux,p,tag = 0,i;
	float *A,*B,*C;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProc);
	srand(time(NULL));

	if(id==0)
	{	
		n = aux = N/(numProc-1);
		A = creaArreglo(N);
		B = creaArreglo(N);
		C = (float*)malloc(sizeof(float)*N);

		for(p=1; p<numProc; p++)
		{
			if(p == (numProc-1) && N%(numProc-1) > 0)
			{
				aux = N-(p*n)+n;
			}

			MPI_Send(&aux, 1, MPI_INT, p, tag, MPI_COMM_WORLD);
			MPI_Send((A+((p-1)*n)), aux, MPI_FLOAT, p, tag, MPI_COMM_WORLD);
			MPI_Send((B+((p-1)*n)), aux, MPI_FLOAT, p, tag, MPI_COMM_WORLD);
		}
		
		aux = n;
		
		for(p=1; p<numProc; p++)
		{
			if(p == (numProc-1) && N%(numProc-1) > 0)
			{
				aux = N-(p*n)+n;
			}

			MPI_Recv((C+((p-1)*n)), aux, MPI_FLOAT, p, tag, MPI_COMM_WORLD, &status);
		}
		
		printf("\nSuma de dos vectores MPI\n\n");
		imprime("A: ", A, N);
		imprime("B: ", B, N);
		imprime("C: ", C, N);
	}
	else
	{
		MPI_Recv(&n, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
		A =(float*)malloc(sizeof(float)*n);
		B =(float*)malloc(sizeof(float)*n);
		C =(float*)malloc(sizeof(float)*n);
		MPI_Recv(A, n, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, &status);
		MPI_Recv(B, n, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, &status);

		for(i=0; i<n; i++)
		{
			*(C+i)=*(A+i)+*(B+i);
		}

		MPI_Send(C, n, MPI_FLOAT, 0, tag, MPI_COMM_WORLD);
	}	
	
	MPI_Finalize();
}

float* creaArreglo(int n)
{
	float *a;
	int i;

	a= (float*)malloc(sizeof(float)*n);
	for(i=0;i<n;*(a+i) = (float)(rand()%100)/10,i++);
	
	return a;
}

void imprime(char *nom, float *arr, int n)
{
	int i;
	
	printf(nom);
	for(i=0; i<n;printf("%.02f, ", *(arr+i)), i++);
	printf("\n");
}

