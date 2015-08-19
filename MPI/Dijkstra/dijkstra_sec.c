/* 	Programa: Algoritmo de Dijkstra para todos los pares (Secuencial)
	Equipo: José Luis Acosta Zamora, Marco Antonio Govea Niño
	Materia: Supercómputo	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INFINITO 1000000

int* leeMatrizAdyacencia(char*,int*);
void imprime_matriz(int,int,int*);
int* dijkstra(int*,int,int);
int minima_distancia(int*,int*,int);
double timeval_diff(struct timeval*,struct timeval*);
int exportarAlArchivo(char*,int*,int);

int main(int argc,char *argv[])
{
	char *nom_arch = argv[1];
	int N,*matriz,*distancia,*mat_dist,s,i,n_datos;
	double t_segundos = 0;
	struct timeval inicio,fin;

	printf("\n ALGORITMO DE DIJKSTRA\n\n");
	matriz = leeMatrizAdyacencia(nom_arch,&N);
	
	if(matriz!=NULL)
	{
		n_datos = N*N;
		mat_dist = (int*)malloc(sizeof(int)*n_datos);
		gettimeofday(&inicio,NULL);		

		for(s=0;s<N;s++)
		{
			distancia = dijkstra(matriz,N,s);
			
			for(i=0;i<N;i++)
				*(mat_dist+(s*N)+i) = *(distancia+i);
		}

		gettimeofday(&fin,NULL);
		t_segundos = timeval_diff(&fin,&inicio);
		printf("\n\n [TIEMPO DE EJECUCION]\n\n  >Minutos: %.0f\n  >Segundos: %.0f",t_segundos/60,t_segundos);
		printf("\n  >*Milisegundos: %.16g\n\n",t_segundos*1000);
		/*printf("\n RESULTADO :\n");
		imprime_matriz(n_datos,N,mat_dist);*/
		exportarAlArchivo(strcat(nom_arch,"_salida_sec.txt"),mat_dist,N);
	}
	
	return 0;
}

int* leeMatrizAdyacencia(char *nom_arch, int *N)
{
	int *matriz=NULL,n_datos,i;
	FILE *f;

	f = fopen(nom_arch, "rb");

	if(f != NULL)
	{
		rewind(f);
		fread(N, sizeof(int), 1, f);
		n_datos = (*N)*(*N);
		printf(" Nodos procesados: %d", *N);
		matriz = (int*)malloc(sizeof(int)*n_datos);
		for(i = 0; i < n_datos;fread(matriz+i, sizeof(int), 1, f), i++);
		/*printf("\n Datos leidos:\n");
		imprime_matriz(n_datos,*N,matriz);*/
		fclose(f);
	}
	else
		printf(" Error al abrir el archivo!\n\n");

	return matriz;
}

void imprime_matriz(int n_datos,int N,int *vector)
{
	int i;

	for(i=0;i<n_datos;i++)
	{
		if(i%N==0)
			printf("\n");
		
		printf("[%d]\t",*(vector+i));
	}

	printf("\n\n");
}

int* dijkstra(int *mat_ady,int N,int s)
{
	int *distancia = (int*)malloc(sizeof(int)*N);
	int *visto = (int*)malloc(sizeof(int)*N);
	int w,cont_vistos,vertice,peso;

	for(w=0;w<N;w++)
	{
		*(visto+w) = 0;
		if(*(mat_ady+((s*N)+w))==0)
			*(distancia+w) = INFINITO;
		else
			*(distancia+w) = *(mat_ady+((s*N)+w));
	}

	distancia[s] = 0;
	cont_vistos = visto[s] = 1;
	
	while(cont_vistos<N)
	{
		vertice = minima_distancia(distancia,visto,N);
		*(visto+vertice) = 1;
		cont_vistos++;
		
		for(w=0;w<N;w++)
		{
			peso = *(mat_ady+((vertice*N)+w));
			if(*(visto+w)==0 && peso>0)
			{
				if(*(distancia+w) > *(distancia+vertice)+peso)
					*(distancia+w) = *(distancia+vertice)+peso;
			}
		}
	}

	return distancia;
}

int minima_distancia(int *distancia, int *visto,int N)
{
	int i,min,indice_min;

	for(i=0;*(distancia+i)==-1||*(visto+i)==1;i++);
	min = *(distancia+i);
	indice_min = i;

	for(;i<N;i++)
	{
		if(*(distancia+i)!=-1 && *(visto+i) == 0 && *(distancia+i)<min)
		{
			min = *(distancia+i);
			indice_min = i;
		}
	}

	return indice_min;
}

double timeval_diff(struct timeval *fin,struct timeval *inicio)
{
	return (double)(fin->tv_sec+(double)fin->tv_usec/1000000)-
			(double)(inicio->tv_sec+(double)inicio->tv_usec/1000000);
}

int exportarAlArchivo(char *file_name, int *matriz, int N)
{
	FILE *f;
	int i, j;

	f = fopen(file_name, "w");

	if(f != NULL){
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				fprintf(f, "%d\t", *(matriz+i+(j*N)));			
			}
			fprintf(f, "%s", "\n");
		}		
		fclose(f);
	}
}
