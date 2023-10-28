.section .data

#ifndef TEST
#define TEST 20
#endif
	
.macro linea
	
	#if TEST==1
		.int 1,2,1,2
	#elif TEST==2
		.int -1,-2,-1,-2
	#elif TEST==3
		.int 0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff
	#elif TEST==4
		.int 0x80000000,0x80000000,0x80000000,0x80000000
	#elif TEST==5
		.int 0xffffffff,0xffffffff,0xffffffff,0xffffffff
	#elif TEST==6
		.int 2000000000,2000000000,2000000000,2000000000
	#elif TEST==7
		.int 3000000000,3000000000,3000000000,3000000000
	#elif TEST==8
		.int -2000000000,-2000000000,-2000000000,-2000000000
	#elif TEST==9
		.int -3000000000,-3000000000,-3000000000,-3000000000
		
	#elif TEST>=10 && TEST<=14
		.int 1,1,1,1
	#elif TEST>=15 && TEST<=19
		.int -1,-1,-1,-1
	
	#else
		.error "Definir TEST entre 1..19"
	#endif
.endm

.macro linea0
	#if TEST>=1 && TEST <=9
		linea
	#elif TEST==10
		.int 0,2,1,1
	#elif TEST==11
		.int 1,2,1,1
	#elif TEST==12
		.int 8,2,1,1
	#elif TEST==13
		.int 15,2,1,1
	#elif TEST==14
		.int 16,2,1,1
	#elif TEST==15
		.int 0,-2,-1,-1
	#elif TEST==16
		.int -1,-2,-1,-1
	#elif TEST==17
		.int -8,-2,-1,-1
	#elif TEST==18
		.int -15,-2,-1,-1
	#elif TEST==19
		.int -16,-2,-1,-1
	#else
		.error "Definir TEST entre 1 y 19"
	#endif
.endm

lista: 	linea0
		.irpc i,123
			linea
		.endr
longlista:	.int    (.-lista)/4
cociente:	.int    0
resto:		.int	0
formato: 
	.ascii "media \t = %11d \t resto \t = %11d\n"
	.asciz "\t = 0x %08x \t\t = 0x %08x\n"
	
formatoq:
	.ascii "media \t = %11d \t resto \t = %11d   \n" 
  	.asciz  "\t = 0x %016llx \t    \t = 0x %016llx\n"
  
# opción: 1) no usar printf, 2)3) usar printf/fmt/exit, 4) usar tb main
# 1) as  suma.s -o suma.o
#    ld  suma.o -o suma					1232 B
# 2) as  suma.s -o suma.o				6520 B
#    ld  suma.o -o suma -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2
# 3) gcc suma.s -o suma -no-pie –nostartfiles		6544 B
# 4) gcc suma.s -o suma	-no-pie				8664 B

.section .text
main: .global main

	call trabajar	# subrutina de usuario
	call imprim_32	# printf()  de libC
	
	call trabajarq
	call imprim_64
	
	call acabar_C	# exit()    de libC
	ret

trabajar:
	mov     $lista, %ebx
	mov  longlista, %ecx
	call media
	mov  %eax, cociente
	mov %edx, resto
	ret

trabajarq:
	mov     $lista, %ebx
	mov  longlista, %ecx
	call mediaq
	mov  %rax, cociente
	mov %rdx, resto
	ret

suma:	# == suma(&lista, longlista);
	mov  $0, %eax # registro sobre el que se va sumando
	mov  $0, %edx # registro para acumular los acarreos
	mov  $0, %esi # índice que permite recorrer la lista
	
	mov $0, %ebp 	# registro que servira para acumular las sumas y acarreos
	mov $0, %edi	# acumulador de acarreos
	
	bucle:
		mov (%ebx, %esi, 4), %eax
		cltd				# Extendemos el signo
		add  %eax, %ebp		# Acumulamos
		
		adc %edx, %edi
		inc	%esi
		
		cmp   %esi,%ecx
		jne    bucle
	
	# Antes de retornar, guardamos lo acumulado a los registros correspondientes
	mov %ebp, %eax
	mov %edi, %edx

	ret

sumaq:
	mov  $0, %rax # registro sobre el que se va sumando
	mov  $0, %rdx # registro para acumular los acarreos
	mov  $0, %esi # índice que permite recorrer la lista
	
	mov $0, %rdi	# acumulador de acarreos
	
	bucleq:
		mov (%rbx, %rsi, 4), %rax
		cltq				# Extendemos el signo
		add  %rax, %rdi		# Acumulamos
		
		inc	%esi
		
		cmp   %esi,%ecx
		jne    bucleq
	
	# Antes de retornar, guardamos lo acumulado a los registros correspondientes
	
	mov %rdi, %rax

	ret

media:
	call suma
	idiv %ecx
	ret
	
mediaq:
	call sumaq
	cqto	# Extendemos el signo de rax a rdx:rax
	idiv %rcx
	ret

imprim_64:
	mov $formatoq, %rdi
	call imprim_C
	ret

imprim_32:			# requiere libC
	mov   $formato, %rdi
	call imprim_C
	ret
	
imprim_C:
	mov   cociente,%rsi
	mov   resto,%rdx
	mov   cociente,%rcx
	mov   resto,%r8
	mov          $0,%eax	# varargin sin xmm
	
	call  printf		# == printf(formato, res, resx, res, res);
	ret
	
acabar_C:			# requiere libC
	mov  cociente, %edi
	call _exit		# ==  exit(resultado)
	ret
