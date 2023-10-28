/*
 * ejer3_4.c
 */


#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/wait.h>

int main(){
	const int TOTAL_HIJOS = 5;
	pid_t PID;
	
	//CREAMOS HIJOS
	for (int i = 0; i < TOTAL_HIJOS; i++){
		if((PID = fork()) < 0){
			perror("Error en fork\n");
			exit(-1);
		}
		
		if(PID == 0){//Hijo imprime y muere
			printf("Soy el hijo PID = %i\n", getpid());
			exit(0);
		
		}
	}
	
	for (int i = 0; i < TOTAL_HIJOS; ++i){
		int estado;
		int PID = wait(&estado);
		
		printf("Ha finalizado mi hijo con PID = %i\n", PID);
		printf("Me quedan %i hijos vivos\n\n", TOTAL_HIJOS - i - 1);
	}
	
	return (0);
}
