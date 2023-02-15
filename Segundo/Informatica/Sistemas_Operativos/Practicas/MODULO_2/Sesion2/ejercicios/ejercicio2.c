/*
 * ejercicio2.c
 * 
 * Copyright 2022 Mario <mario@mario-Legion-5-15ACH6H>
 * 
 * MODULO II
 * 		SESION 2
 * 		EJERCICIO 2
 * 
 * 
 */


#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR *dir;
	char *pathname;
	int permisos;
	char cadena[500];
	struct stat atributos;
	
	
	if (argc != 3){
		printf("Error\n");
		exit(-1);
		
	} else {
		printf("BIEN\n");
		
		pathname = argv[1];
		dir = opendir(pathname);
		permisos = strtol(argv[2], NULL, 8);
	}
	
	struct dirent *file;

	while ((file = readdir(dir)) != NULL){
		sprintf(cadena, "%s/%s", pathname, file->d_name);
		
		if (stat(cadena, &atributos) < 0){
			printf ("ERROR AL INTENTAR ACCEDER A ATRIBUTOS\n");
			exit(-1);
		}
		
		if (S_ISREG(atributos.st_mode)){
			printf ("%s \t:  %o\t", file->d_name, atributos.st_mode);
		
			chmod(cadena,permisos);
			if(chmod(cadena,permisos) < 0) {
				printf("Error\n");
				
			} else {
				stat(cadena,&atributos);
				printf("%o \n",atributos.st_mode);
				
			}	
		}
	}


	return 0;
}

