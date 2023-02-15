#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
	if (argc != 3){
		printf("Error en el numero de argumentos\n");
		exit(EXIT_FAILURE);
	}
	
	int inf = atoi(argv[1]);
	int sup = atoi(argv[2]);
	
	int media = (inf+sup)/2;
	
	int fd1[2];
	int fd2[2];
	pid_t PID;

	pipe(fd1); // Llamada al sistema para crear un pipe
	pipe(fd2);

	if ( (PID = fork())<0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	if(PID == 0) { // PRIMER PROCESO HIJO
		char ini[10];
		char fin[10];
		
		sprintf(ini, "%d", inf);
		sprintf(fin, "%d", media);
		
		//Establecer la direccion del flujo de datos en el cauce cerrando
		// el descriptor de lectura de cauce en el proceso hijo
		close(fd1[0]);

		//Duplicar el descriptor de escritura en cauce en el descriptor
		//correspondiente a la salida estandr (stdout), cerrado previamente en
		//la misma operacion
		dup2(fd1[1],STDOUT_FILENO);
		
		execl("./esclavo", "esclavo", ini, fin, NULL);
		
	} else { // PROCESO PADRE. (PID != 0)

		//Establecer la dirección del flujo de datos en el cauce cerrando
		// el descriptor de escritura en el cauce del proceso padre.
		close(fd1[1]);
		
		int val1;
		int bytesLeidos;
		
		while ((bytesLeidos = read(fd1[0], &val1, sizeof(int))) > 0){
			printf("%d\t", val1);
		}
		
		close(fd1[0]);	//Cerramos el descriptor de lectura ya terminada la tarea
		printf("\n");
	
	}
	
	
	if ( (PID = fork())<0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	if (PID == 0){
		char ini[10];
		char fin[10];
		
		sprintf(ini, "%d", media);
		sprintf(fin, "%d", sup);
		
		close(fd2[0]);	//Cerramos descriptor de lectura
		
		dup2(fd2[1], STDOUT_FILENO);
		
		execl("./esclavo", "esclavo", ini, fin, NULL);
		
	} else {
		//Establecer la dirección del flujo de datos en el cauce cerrando
		// el descriptor de escritura en el cauce del proceso padre.
		close(fd2[1]);
		
		int val2;
		int bytesLeidos;
		
		while ((bytesLeidos = read(fd2[0], &val2, sizeof(int))) > 0){
			printf("%d\t", val2);
		}
		
		close(fd2[0]);	//Cerramos el descriptor de lectura ya terminada la tarea
		printf("\n");
	}
	
	
	return 0;
}

