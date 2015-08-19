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
