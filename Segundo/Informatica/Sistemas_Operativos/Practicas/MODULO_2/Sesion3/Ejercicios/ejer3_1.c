/*
 * ejer3_1.c
 */


#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char **argv){
	if (argc != 2){
		printf("ERROR : NUMERO INCORRECTO DE ARGUMENTOS\n");
		exit(-1);
	}
	
	int num = atoi(argv[1]);
	
	pid_t pid;
	
	if((pid=fork()) < 0) {
		perror("\nError en el fork");
		exit(EXIT_FAILURE);
	
	} else {
		if (pid == 0){	// PROCESO HIJO
			printf("PROCESO HIJO\n");
			
			char *res;
			if (num%2 == 0){
				res = "PAR";
			} else {
				res = "IMPAR";
			}
			
			printf ("El numero %d es %s\n", num, res);
		
		} else {	// PROCESO PADRE
			wait(0);
			printf("PROCESO PADRE\n");
			
			char *res;
			if (num%4 == 0){
				res = "SI";
			} else {
				res = "NO";
			}
			
			printf ("El numero %d %s es divisible entre 4\n", num, res);
			
		}
	}
	
	
	return 0;
}

