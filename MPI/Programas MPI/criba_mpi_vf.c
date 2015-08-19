/*
	PROGRAMA: Ciba de Eratostenes (Obtencion de numeros primos) en MPI.
	MATERIA: Supercomputo.
	AUTOR: Jose Luis Acosta Zamora (173025).
	FECHA: 25 Noviembre 2014.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

#define PRINCIPAL 0

int* crea_arreglo(int n);
void imprime_arreglo(int n,int *vector);
int dame_tam_bloque(int N,int n,int numProc,int id);
void inicializa_variables(int N,int numProc,int **primos,int **arr_cuenta,int **arr_desp);
void criba(int N,int tam_bloque,int desp,int **fragmento);

main(int argc, char *argv[])
{
	int N = atoi(*(argv+1))-1,idProc,numProc,n,desp,tam_bloque;
	int *primos,*arr_desp,*arr_cuenta,*fragmento;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &idProc);
	MPI_Comm_size(MPI_COMM_WORLD, &numProc);

	if(N>=numProc)
	{
		if(N>0)
		{
			if(idProc == PRINCIPAL)
			{
				printf("\nCRIBA DE ERATOSTENES, PROCESOS: %d",numProc);
				printf("\nObtencion de numeros primos entre 2 y %d\n",N+1);
				inicializa_variables(N,numProc,&primos,&arr_cuenta,&arr_desp);
				/*printf("\n> SE DIVIDE Y ENVIA: ");
				imprime_arreglo(N,primos);
				printf("\n> CUENTA: ");
				imprime_arreglo(numProc,arr_cuenta);
				printf("\n> DESPLAZAMIENTOS: ");
				imprime_arreglo(numProc,arr_desp);*/
			}
			else
			{
				arr_cuenta = (int*)malloc(sizeof(int)*numProc);
				arr_desp = (int*)malloc(sizeof(int)*numProc);
			}
		
			MPI_Bcast(arr_cuenta,numProc,MPI_INT,PRINCIPAL,MPI_COMM_WORLD);
			MPI_Bcast(arr_desp,numProc,MPI_INT,PRINCIPAL,MPI_COMM_WORLD);
			tam_bloque = *(arr_cuenta+idProc);
			desp = *(arr_desp+idProc);
			fragmento = (int*)malloc(tam_bloque*sizeof(int));
			MPI_Scatterv(primos,arr_cuenta,arr_desp,MPI_INT,fragmento,tam_bloque,MPI_INT,PRINCIPAL,MPI_COMM_WORLD);
			/*printf("\n -Proceso %d marcara: ",idProc);
			imprime_arreglo(tam_bloque,fragmento);*/
			criba(N,tam_bloque,desp,&fragmento);
			MPI_Gatherv(fragmento,tam_bloque,MPI_INT,primos,arr_cuenta,arr_desp,MPI_INT,PRINCIPAL,MPI_COMM_WORLD);
		
			if(idProc == PRINCIPAL)
			{
				printf("\n> RESULTADO : ");
				imprime_arreglo(N,primos);
				printf("\n");
			}
		}
		else if(idProc == PRINCIPAL)
		{
			printf("\n ERROR! -> EL ALGORITMO ANALIZA A PARTIR DE 2, CUALQUIER ENTRADA MENOR ES INVALIDA!!\n\n");
		}
	}
	else if(idProc == PRINCIPAL)
	{
		printf("\n ERROR! -> EL NUMERO DE PROCESOS ES MAYOR AL TOTAL DE DATOS A ANALIZAR!!\n");
		printf("(En este caso, %d-1=%d datos ya que el algoritmo empieza desde 2 no desde 1.)\n\n",N+1,N);
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

void inicializa_variables(int N,int numProc,int **primos,int **arr_cuenta,int **arr_desp)
{
	int p,n=N/numProc;

	*primos = crea_arreglo(N);
	*arr_desp = (int*)malloc(sizeof(int)*numProc);
	*arr_cuenta = (int*)malloc(sizeof(int)*numProc);
	
	for(p=0;p<numProc;p++)
	{
		*((*arr_desp)+p) = p*n;
		*((*arr_cuenta)+p) = dame_tam_bloque(N,n,numProc,p);
	}
}

void imprime_arreglo(int n,int *arreglo)
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

int dame_tam_bloque(int N,int n,int numProc,int idProc)
{
	int aux = n;

	if(idProc == (numProc-1) && N%numProc > 0)
	{
		aux = N-(idProc*n);
	}

	return aux;
}

void criba(int N,int tam_bloque,int desp,int **fragmento)
{
	int i,j,limite = (int)sqrt(N);

	for(i = 2 ;i <= limite; i++)
	{
		for(j = desp+2 ; j < (desp+2)+tam_bloque ; j++)
		{
			if(i!=j && j%i == 0)
			{
				*((*fragmento)+(j-desp-2))=-1;
			}
		}
	}
}
