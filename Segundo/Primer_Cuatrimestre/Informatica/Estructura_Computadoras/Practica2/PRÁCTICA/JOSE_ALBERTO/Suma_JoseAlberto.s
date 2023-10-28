.section .data
lista:		.int 0x80000000, 0x80000000
#lista:		.int 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
longlista:	.int   (.-lista)/4
resultado:	.quad   0
  formato: 	.asciz	"suma = %lu = 0x%lx hex\n"

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
	call imprim_C
	call acabar_C	# exit()   del kernel Linux
	ret

trabajar:
	mov     $lista, %ebx
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov  %eax, resultado
	mov  %edx, resultado+4
	ret

suma:
	mov  $0, %eax # registro sobre el que se va sumando
	mov  $0, %edx # registro para acumular los acarreos
	mov  $0, %esi # índice que permite recorrer la lista
bucle:
	cmp   %esi, %ecx # si el índice llega al final de la lista, se termina el bucle
	je    fin_bucle
	add   (%ebx,%esi,4), %eax # se van sumando los elementos de la lista en eax
	jnc   no_acarreo 
	inc   %edx # si ha habido acarreo en la última suma, se suma 1 a edx 
no_acarreo:
	inc  %esi # se actualiza el contador
	jmp bucle # se vuelve al bucle para la sumar el siguiente elemento

fin_bucle:
	ret

imprim_C:			# requiere libC
	mov   $formato, %rdi
	mov   resultado,%rsi
	mov   resultado,%rdx
	mov          $0,%eax	# varargin sin xmm
	call  printf		# == printf(formato, res, res);
	ret

acabar_C:			# requiere libC
	mov   resultado, %edi
	call _exit		# ==  exit(resultado)
	ret
