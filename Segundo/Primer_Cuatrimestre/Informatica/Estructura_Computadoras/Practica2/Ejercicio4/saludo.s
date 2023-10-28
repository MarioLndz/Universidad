# saludo.s:	Imprimir por pantalla
#			Hola a todos!
#			Hello, World!
# retorna:	código retorno 0, programado en la penúltima línea
#			comprobar desde linea de comandos bash con echo $?

# SECCIÓN DE DATOS (.data, variables globales inicializadas)
#	datos 	hex	octal	binario	decimal	char	string:
#			0x 	0		0b		díg<>0	‘		""
#

.section .data
saludo:		.ascii	"Hola a todos!\nHello, World!\n"
longsaludo:	.quad	.-saludo

.section .text
.global _start
_start:
	mov $1, %rax
	mov         $1, %rdi
	mov    $saludo, %rsi
	mov longsaludo, %rdx
	syscall

	mov $60, %rax
	mov  $0, %rdi
	syscall

