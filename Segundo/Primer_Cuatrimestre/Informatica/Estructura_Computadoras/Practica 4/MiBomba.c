// gcc -O2 MiBomba.c -o MiBomba -no-pie

#include <stdio.h>	// para printf(), fgets(), scanf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()
#include <sys/time.h>	// para gettimeofday(), struct timeval

#define SIZE 100
#define TLIM 10

char password[]="computador\n";	// contraseña
int  comp  = 17;			// valor a multiplicar
int	 code = 1921;			// resultado --> 1921 = 17 * 113 --> 113 es la clave


void defused(void){
	printf("\n"
		"\t                 ___             \n"
		"\t                /   \\           \n"
		"\t               |                 \n"
		"\t               |                 \n"
		"\t           ,--'#`--.             \n"
		"\t           |#######|             \n"
		"\t        _.-'#######`-._          \n"
		"\t     ,-'###############`-.       \n"
		"\t   ,'#####################`,     \n"
		"\t  /#########################\\   \n"
		"\t |###########################|   \n"
		"\t|#############################|  \n"
		"\t|#############################|  \n"
		"\t|#############################|  \n"
		"\t|#############################|  \n"
		"\t |###########################|   \n"
		"\t  \\#########################/   \n"
		"\t   `.#####################,'     \n"
		"\t     `._###############_,'       \n"
		"\t        `--..#####..--'			\n"
		"\n\t -------- BOMB DEFUSED --------\n\n");
	exit(0);
}

void bomb_started(void){
	printf("\n"
		"\t              \\|/         		\n"
		"\t            `--+--'              \n"
		"\t              /|\\               \n"
		"\t             ' | '               \n"
		"\t               |                 \n"
		"\t               |                 \n"
		"\t           ,--'#`--.             \n"
		"\t           |#######|             \n"
		"\t        _.-'#######`-._          \n"
		"\t     ,-'###############`-.       \n"
		"\t   ,'#####################`,     \n"
		"\t  /#########################\\   \n"
		"\t |###########################|   \n"
		"\t|#############################|  \n"
		"\t|#############################|  \n"
		"\t|#############################|  \n"
		"\t|#############################|  \n"
		"\t |###########################|   \n"
		"\t  \\#########################/   \n"
		"\t   `.#####################,'     \n"
		"\t     `._###############_,'       \n"
		"\t        `--..#####..--'			\n"
		"\n\t ------- BOMB STARTED -------\n\n");
	
}

void boom (){
	printf( "\n"
		"\t          ..-^~~~^-..		\n"
        "\t        .~           ~.		\n"
        "\t       (;:           :;)		\n"
        "\t        (:           :)		\n"
        "\t          ':._   _.:'		\n"
        "\t              | |			\n"
        "\t            (=====)			\n"
        "\t              | |			\n"
        "\t              | |			\n"
        "\t              | |			\n"
		"\t           ((/   \\))		\n"
		"\n\t ------- BOMB EXPLODED -------\n\n");
		
	exit(-1);
}

int main(){
	char pw[SIZE];
	int  pc, n;

	struct timeval tv1,tv2;	// gettimeofday() secs-usecs
	gettimeofday(&tv1,NULL);
	
	bomb_started();
	
	do {
		printf("\nIntroduce la contraseña: ");
	} while (fgets(pw, SIZE, stdin) == NULL );
	
	if (strncmp(pw,password,sizeof(password)) ){
	    boom();
	}
	gettimeofday(&tv2,NULL);
	if    ( tv2.tv_sec - tv1.tv_sec > TLIM ){
		boom();
	}

	do  {	
		printf("\nIntroduce el pin: ");
		
		if ((n=scanf("%i",&pc)) == 0){
			scanf("%*s") == 1;         
		}
	} while (	n!=1 );
	
	pc = pc*comp;
	
	if (pc != code){
		boom();
	}

	gettimeofday(&tv1,NULL);
	
	if    (tv1.tv_sec - tv2.tv_sec > TLIM){
	    boom();
	}

	defused();
}
