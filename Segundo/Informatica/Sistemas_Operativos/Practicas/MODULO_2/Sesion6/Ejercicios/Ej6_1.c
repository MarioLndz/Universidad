#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv){
	if (argc != 4){
		printf("Numero de argumentos incorrecto\n");
		exit(-1);
	}
	
	if (strcmp(argv[2], "<") && strcmp(argv[2], ">")){
		printf("ERROR\n");
		exit(-1);
		
	}
	
	char * cauce = argv[2];
	char * orden = argv[1];
	char * archivo = argv[3];
	
	if (strcmp(argv[2], "<") == 0){			// REDIRECCION DE ENTRADA
		int fd = open(archivo, O_RDONLY);
		
		close(STDIN_FILENO);
		
		fcntl(fd, F_DUPFD, STDIN_FILENO);
		
		
		
	} else {								// REDIRECCION DE SALIDA
		int fd = open (archivo, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR | S_IWUSR);
        
        close (STDOUT_FILENO);
        
        if (fcntl(fd, F_DUPFD, STDOUT_FILENO) == -1 ) perror ("fcntl falló");
		
	}
	
	execlp(orden, orden, NULL);
	
	return (0);
	
}
