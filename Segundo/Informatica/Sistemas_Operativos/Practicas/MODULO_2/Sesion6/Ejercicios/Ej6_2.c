#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char * argv[]){
	
	if (argc != 4){
		printf("Numero de argumentos incorrecto\n");
		exit(-1);
	}
	
	if (strcmp(argv[2], "|")){
		printf("ERROR\n");
		exit(-1);
		
	}
	
	char * orden_inicial = argv[1];
	char * orden_final = argv[3];
	
	int fd[2];
	pid_t PID;

	pipe(fd); // Llamada al sistema para crear un pipe

	if ( (PID= fork())<0) {
		perror("\Error en fork");
		exit(EXIT_FAILURE);
	}
	
	if (PID == 0) { // ls
		//Cerrar el descriptor de lectura de cauce en el proceso hijo
		close(fd[0]);

		close(STDOUT_FILENO);
		
		fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
		
		execlp(orden_inicial,orden_inicial,NULL);
	}
	else { // sort. Proceso padre porque PID != 0.
		//Cerrar el descriptor de escritura en cauce situado en el proceso padre
		close(fd[1]);

		close(STDIN_FILENO);
		
		fcntl(fd[0], F_DUPFD, STDIN_FILENO);
		
		execlp(orden_final,orden_final,NULL);
	}
	
	return (0);
	
}
