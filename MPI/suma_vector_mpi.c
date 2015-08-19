
/*
	Equipo:
		José Luis Acosta Zamora
		Edith Angélica Ramos López
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mpi.h"

int * creaArreglo(int n);
void imprime(int *arr, int n, int s);

main(int argc, char *argv[])
{
	int T = atoi(argv[i]);
	int *arr;
	int numProc, id, tareas, aux, i,s;
	int tag = 0;
	int suma = 0;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProc);

	if(id==0)
	{
		tareas = T/(numProc-1);
		suma = 0;
		arr = creaArreglo(T);
		for(i=1; i<numProc; i++)
		{
			if(i == numProc-1 && T%(numProc-1) != 0)
			{
				aux = T - (i*tareas) + tareas;
				MPI_Send(&aux, 1, MPI_INT, i, tag, MPI_COMM_WORLD);
				MPI_Send((arr+((i-1)*tareas)), aux, MPI_INT, i, tag, MPI_COMM_WORLD);
			}
			else
			{
				MPI_Send(&tareas, 1, MPI_INT, i, tag, MPI_COMM_WORLD);
				MPI_Send((arr+((i-1)*tareas)), tareas, MPI_INT, i, tag, MPI_COMM_WORLD);
			}
		}
		for(i=1; i<numProc; i++)
		{
			MPI_Recv(&s, 1, MPI_INT, i, tag, MPI_COMM_WORLD, &status);
			suma += s;
		}
		imprime(arr, T, suma);
	}
	else
	{
		suma = 0;
		MPI_Recv(&tareas, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
		arr = creaArreglo(tareas);
		MPI_Recv(arr, tareas, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
		for(i=0; i<tareas; i++)
		{
			suma += arr[i];
		}
		MPI_Send(&suma, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}
	MPI_Finalize();		
}
int * creaArreglo(int n)
{
	int *a, i;
	srand(time(NULL));
	a = (int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
	{
		a[i] = rand()%100;
	}	
}
void imprime(int *arr, int n, int s)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\nEl resultado es:%d\n", s);
	free(arr);
}

