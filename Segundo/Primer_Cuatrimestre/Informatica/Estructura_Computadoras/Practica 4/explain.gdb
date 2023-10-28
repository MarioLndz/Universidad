# Practica 4, Actividad 4.1: explicacion de la bomba
# CONTRASEÑA: computador
# PIN: 113

# MODIFICADA: BuenosDias
# PIN: 211

# Describiremos el proceso logico seguido
# primero: para descubrir las claves, y
# despues: para cambiarlas

# Pensado para ejecutar mediante "source explain.gdb"
# o desde linea de comandos con gdb -q -x explain.gdb

# funciona sobre la bomba original, para recompilarla
# usar la orden gcc en la primera linea de bomba.c
# gcc -O2 MiBomba.c -o MiBomba -no-pie
########################################################

### cargar el programa
	file MiBomba
### util para la sesion interactiva, no para source/gdb -q -x
# 	layout asm
# 	layout regs

### arrancar programa, notar automatizacion para teclear prueba y 10
	br main
	run < <(echo -e prueba\\n10\\n)

### Si se realiza manualmente, avanzaremos usando "ni" hasta call boom, 
### antes pide la contraseña y tecleamos hola
### si seguimos un salto nos lleva a entrar en boom y explota, teniendo que empezar de nuevo
### la decision se toma antes, justo antes del salto
### hay un jne que te salta a la bomba, y el test anterior
### activaria ZF si el retorno de strncmp produjera 0,
### es decir, si 0==strncmp(rdi,rsi,edx)
# 	0x000000000040118d <main+125>:	lea    0x2ed4(%rip),%rsi        # 0x404068 <password>
# 	0x0000000000401194 <main+132>:	mov    %rbp,%rdi
# 	0x0000000000401197 <main+135>:	call   0x4010a0 <strncmp@plt>
# 	0x000000000040119c <main+140>:	test   %eax,%eax
# 	0x000000000040119e <main+142>:	jne    0x40121c <main+268>
# 	...
# 	0x000000000040121c <main+268>:	xor    %eax,%eax
# 	0x000000000040121e <main+270>:	call   0x401380 <boom>
### avancemos hasta strncmp para consultar los valores
	br *main+135
	cont

### escribir "hola" cuando pida contraseña, automatizado ya en run
### ahora mismo estamos viendo de donde sale la contraseña
### 0x000000000040118d <main+125>:	lea    0x2ed4(%rip),%rsi        # 0x404068 <password>
### imprimir la contraseña y recordar que esta en la posicion de memoria 0x404068
	p (char*)0x404068
### Obtenemos asi la contraseña y su longitud (12B)
### dejar que strncmp salga mal y corregir eax=0 para evitar boom()
	ni
	set $eax=0
	ni
	ni

### siguiente bomba es por tiempo
#	call   0x4010c0 <gettimeofday@plt>
#	0x00000000004011ac <main+156>:	mov    0x20(%rsp),%rax
#	0x00000000004011b1 <main+161>:	sub    0x10(%rsp),%rax
#   0x00000000004011b6 <main+166>:	cmp    $0xa,%rax
#   0x00000000004011ba <main+170>:	jg     0x40121c <main+268>
#	...
#   0x000000000040121c <main+268>:	xor    %eax,%eax
#   0x000000000040121e <main+270>:	call   0x401380 <boom>
### Observamos que compara con el valor numerico "0xa = 10" por lo que sabemos que el tiempo
### limite establecido para desactivar la bomba es de 10 segundos
### avanzar hasta el cmp
	br *main+166
	cont
### falsear tiempo=0 por si acaso se ha tardado en teclear
	set $eax=0
	ni
	ni

### el programa sigue, comparando ahora el resultado de una multiplicacion de una posicion
### de memoria y scanf (orden "imul") con otra posicion de memoria
#	0x0000000000401205 <main+245>:	mov    0xc(%rsp),%eax
#   0x0000000000401209 <main+249>:	imul   0x2e54(%rip),%eax        # 0x404064 <comp>
#   0x0000000000401210 <main+256>:	cmp    0x2e4a(%rip),%eax        # 0x404060 <code>
#   0x0000000000401216 <main+262>:	mov    %eax,0xc(%rsp)
#   0x000000000040121a <main+266>:	je     0x401232 <main+290>
#   0x000000000040121c <main+268>:	xor    %eax,%eax
#   0x000000000040121e <main+270>:	call   0x401380 <boom>
### avanzar hasta cmp para consultar valores
	br *main+256
	cont
### escribir "10" cuando pida pin, resuelto ya en run
### imprimimos los valores usados en estas operaciones. El primer factor esta en 0x404064 y el resultado
### esta en 0x404060
	p* (int*)0x404064
	p* (int*)0x404060
### haciendo la operacion correspondiente tenemos que 17*X = 1921; X = 1921/17 = 113 --> Siendo 113 el pin
### corregir sobre la marcha EAX para que cmp salga bien
	set $eax=1921
	ni
	ni
	ni

### De nuevo la siguiente bomba es por tiempo
#	0x0000000000401237 <main+295>:	call   0x4010c0 <gettimeofday@plt>
#   0x000000000040123c <main+300>:	mov    0x10(%rsp),%rax
#   0x0000000000401241 <main+305>:	sub    0x20(%rsp),%rax
#   0x0000000000401246 <main+310>:	cmp    $0xa,%rax
#   0x000000000040124a <main+314>:	jg     0x40121c <main+268>
#   ...
#   0x000000000040121c <main+268>:	xor    %eax,%eax
#   0x000000000040121e <main+270>:	call   0x401380 <boom>
### avanzar hasta el cmp
	br *main+310
	cont
### falsear tiempo=0 por si acaso se ha tardado en teclear
	set $eax=0
	ni
	ni
### hemos llegado a defused, fin del programa
	ni

########################################################
### permitir escribir en el ejecutable
	set write on
### reabrir ejecutable con permisos r/w
	file MiBomba
### realizar los cambios. Primero cambiamos la contraseña
	set {char[12]}0x404068="BuenosDias\n"
### Cambiaremos la contraseña a 211. Para ello cambiamos el factor de multiplicación a 11 y el
### resultado a 2321 --> 211 * 11 = 2321. Este pin será único al ser multiplicación de numeros primos
	set {int}0x404064=11
	set {int}0x404060=2321
### comprobar las instrucciones cambiadas
	p (char*)0x404068
	p* (int*)0x404064
	p* (int*)0x404060
### salir para desbloquear el ejecutable
	quit
########################################################
