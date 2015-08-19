#include <stdio.h>
#include <stdlib.h>

int escribeEnElArchivo(char *file_name, int **matriz, int N);

int main(int argc, char *argv[])
{
	int i, j, N = atoi(argv[1]), **matriz;
	char file_name[50];

	N = atoi(argv[1]);
	srand(time(NULL));

	printf("\nNombre del archivo: ");
	scanf("%s", file_name);

	matriz = (int **)malloc(sizeof(int*)*N);

	for(i = 0; i < N; i++)
		*(matriz + i) = (int *)malloc(sizeof(int)*N);

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++){
			matriz[i][j] = -1;
		}

	if(escribeEnElArchivo(file_name, matriz, N))
		printf("\n\n!El ARCHIVO SE CREO CORRECTAMENTE!\n\n");
	else
		printf("\n\n!ERROR AL ESCRIBIR EN EL ARCHIVO!\n\n");

	return 0;
}

int escribeEnElArchivo(char *file_name, int **matriz, int N){
	int i, j;	
	FILE *f;

	f = fopen(file_name, "wb");

	if(f != NULL){
		fwrite(&N, sizeof(int), 1, f);
		printf("\nDatos totales: %d\n", N*N);
		for(i = 0; i < N; i++){	
			for(j = 0; j < N; j++){	
				if(matriz[i][j] == -1){
					if(rand()%2 != 0 && i != j){
						matriz[i][j] = rand()%100;	
						matriz[j][i] = matriz[i][j];
					}
					else{
						matriz[i][j] = 0;	
						matriz[j][i] = matriz[i][j];
					}	
				}
				fwrite(&matriz[i][j], sizeof(int), 1, f);
			}
		}
		fclose(f);
		return 1;
	}
	else
		return 0;
}
