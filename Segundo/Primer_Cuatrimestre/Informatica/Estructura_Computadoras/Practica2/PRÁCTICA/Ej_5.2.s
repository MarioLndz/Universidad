.section .data

#ifndef TEST
#define TEST 9
#endif
	.macro linea
	
	#if TEST==1		// 16 – ejemplo muy sencillo
		.int -1,-1,-1,-1
	
	#elif TEST==2	// 0x0 ffff fff0, casi acarreo
		.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
	
	#elif TEST==3          
		.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
	
	#elif TEST==4          
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
		
	#elif TEST==5         
		.int -1,-1,-1,-1
		
	#elif TEST==6      
		.int 200000000, 200000000, 200000000, 200000000
		
	#elif TEST==7         
		.int 300000000, 300000000, 300000000, 300000000
		
	#elif TEST==8	// 11 280 523 264 << 16x5e9= 80e9
		.int 5000000000,5000000000,5000000000,5000000000
		
	#else
		.error "Definir TEST entre 1..8"
#endif
.endm


lista: 	.irpc i,1234
			linea
		.endr
longlista:	.int   (.-lista)/4
resultado:	.quad   0
formato:
	.ascii "resultado \t =   %18lu (uns)\n"
	.ascii 		   "\t\t = 0x%18lx (hex)\n"
	.asciz 		   "\t\t = 0x %08x %08x \n"

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
	call imprim_C	# printf()  de libC
	call acabar_C	# exit()    de libC
	ret

trabajar:
	mov     $lista, %ebx
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov  %eax, resultado
	mov %edx, resultado+4
	ret

suma:
	mov  $0, %eax # registro sobre el que se va sumando
	mov  $0, %edx # registro para acumular los acarreos
	mov  $0, %esi # índice que permite recorrer la lista
	
bucle:
	add  (%ebx,%esi,4), %eax
	adc $0, %edx
	inc	%esi
	
	cmp   %esi,%ecx
	jne    bucle

	ret

imprim_C:			# requiere libC
	mov   $formato, %rdi
	mov   resultado,%rsi
	mov   resultado,%rdx
	mov   resultado+4,%rcx
	mov   resultado,%r8
	mov          $0,%eax	# varargin sin xmm
	
	call  printf		# == printf(formato, res, resx, res, res);
	ret

acabar_C:			# requiere libC
	mov  resultado, %edi
	call _exit		# ==  exit(resultado)
	ret
