/*
	PROGRAMA: Criba de Eratostenes (Obtencion de numeros primos) en CUDA.
	MATERIA: Supercomputo.
	AUTOR: Jose Luis Acosta Zamora (173025).
	FECHA: 25 Noviembre 2014.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cuda_runtime.h>

int* crea_arreglo(int n);
void imprime_arreglo(int n,int *vector);

__global__ void criba(int N,int tam_bloque,int desp,int **fragmento)
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

main(int argc, char *argv[])
{
	int N = atoi(*(argv+1))-1;
	int* h_lista;
	int* d_lista;
	int* h_primos;

	if(N>0)
	{
		printf("\nCRIBA DE ERATOSTENES\nObtencion de numeros primos entre 2 y %d\n",N+1);
		h_lista = crea_arreglo(N);
		h_primos = (int *)malloc(sizeof(int)*N); 

		criba<<<1,N>>>(d_A,d_B,d_C,N);
	
		printf("\n> RESULTADO : ");
		imprime_arreglo(N,primos);
		printf("\n");
	}
}

int* crea_arreglo(int n)
{
	int *a, i;

	a = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;*(a+i)=(i+2),i++);
	return a;
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


#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

__global__ void VecAdd(float* A,float* B, float* C, int N)
{
	int i = threadIdx.x;
	C[i]=A[i]+B[i];
}

int main()
{
	int N = 10;
	size_t size = N * sizeof(float);
	float* h_A = (float*)malloc(size);
	float* h_B = (float*)malloc(size);
	float* h_C = (float*)malloc(size);
	float* d_A;
	float* d_B;
	float* d_C;

	srand(time(NULL));
	
	for(i=0;i<N;i++)
	{
		h_A[i] = (float)(rand()%100)/10;
		h_B[i] = (float)(rand()%100)/10;
	}
	
	cudaMalloc(&d_A,size);
	cudaMalloc(&d_B,size);
	cudaMalloc(&d_C,size);

	cudaMemcpy(d_A,h_A,size,cudaMemcpyHostToDevice);
	cudaMemcpy(d_B,h_B,size,cudaMemcpyHostToDevice);

	VecAdd<<<1,N>>>(d_A,d_B,d_C,N);

	cudaMemcpy(h_C,d_C,size,cudaMemcpyDeviceToHost);

	for(i=0;i<N;i++)
	{
		printf("%f",h_C[i]);
	}

	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);

	return 0;
}
