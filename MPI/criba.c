/* 	Programa: Criba de Eratóstenes (Secuencial ANSI-C)
	Autor: José Luis Acosta Zamora
	Materia: Supercómputo	*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void criba(int n);
int* crea_arreglo(int n);
void imprime_arreglo(int n,int* vector);

int main(int argc,char *argv[])
{
	int n = atoi(argv[1]);

	printf("\n Criba de Eratóstenes\n");
	printf("\n Números primos entre 2 y %d\n",n);
	if(n>1)
	{
		criba(n);
	}

	return 0;
}

void criba(int n)
{
	int *tabla, *primos;
	int indx_i,indx_j,i,j;

	tabla = crea_arreglo(n-1);
	primos = crea_arreglo(n-1);

	for(indx_i = 0;*(tabla+indx_i)<=(int)sqrt(n);indx_i++)
	{
		i = *(tabla+indx_i);
		
		for(indx_j = indx_i;(float)(*(tabla+indx_j))<=(float)(n/i);indx_j++)
		{
			j = *(tabla+indx_j);

			if(*(primos+((i*j)-2))>0)	//Si no ha sido marcado
			{
				*(primos+((i*j)-2))=-1; //Se marca
				printf("-%d",*(tabla+((i*j)-2)));
			}
		}
		printf("\n");
	}

	printf("\n Resultado: ");
	imprime_arreglo((n-1),primos);
}

int* crea_arreglo(int n)
{
	int *a, i;

	a = (int *)malloc(sizeof(int)*(n-1));
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
	printf("\n\n");
}

