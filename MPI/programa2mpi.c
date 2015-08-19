#include <stdio.h>
#include <string.h>
#include "mpi.h"

main(int argc, char *argv[]){
	int name, p, source, dest, tag=0;
	int i, j, numero;

	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &name);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	if(name==0){
		numero=2324;
		printf("Hola soy el proceso %d de %d\n",name,p);
		printf("Y voy a enviar un entero a cada uno de los procesos\n");
		for(i=0;i<p;i++){
			printf("Enviando al proceso %d\n",i);
			dest = i;
			MPI_Send(&numero, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
		}
	}
	else{
		printf("Inicia proceso %d de %d\n",name,p);
		source = 0;
		MPI_Recv(&numero,1,MPI_INT, source, tag, MPI_COMM_WORLD, &status);
		printf("Proceso %d, Recibe el numero %d\n",name,numero);
	}

	MPI_Finalize();
}