/*
 * sin título.c
 * 
 * Copyright 2022 Mario <mario@mario-Legion-5-15ACH6H>
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>


void buscar_dir (DIR *dir, char *pathname, int *reg, int *tamanio){
	DIR *subdirect;
	char cadena[300];
	struct stat atributos;
	
	struct dirent *file;
	
	while ((file = readdir(dir)) != NULL){
		if(strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0){
			sprintf(cadena, "%s/%s", pathname, file->d_name);
			
			if (lstat(cadena, &atributos) < 0){
				printf ("ERROR AL INTENTAR ACCEDER A ATRIBUTOS\n");
				exit(-1);
			}
			
			if (S_ISREG(atributos.st_mode)){
				
				printf ("%s \t:  %ld\t\n", cadena, atributos.st_ino);
				(*reg)++;
				(*tamanio) += (int)atributos.st_size;
				
				
			} else {
				if (S_ISDIR(atributos.st_mode)){
					subdirect = opendir(cadena);
					buscar_dir(subdirect, cadena, reg, tamanio);
					
				}
			}
		}
	}
	
	
}



int main(int argc, char **argv) {
	char *pathname;
	DIR *dir;
	int reg = 0;
	int tamanio = 0;
	
	if (argc != 2){
		printf("Error\n");
		exit(-1);
	
	}
	
	pathname = argv[1];
	dir = opendir(pathname);
	
	printf ("Los nodos son: \n\n");
	buscar_dir(dir, argv[1], &reg, &tamanio);
	
	printf("Hay %d archivos regulares con permiso x para grupo y otros\n",reg);
	printf("El tamaño total que ocupan dichos archivos es de %d bytes\n",tamanio);
	
	
	
	
	return 0;
}

