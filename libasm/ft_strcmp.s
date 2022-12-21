section .text
global _ft_strcmp

_ft_strcmp:	mov rax, 0
			jmp start

start:		mov al, byte[rdi]
			mov bl, byte[rsi]
			cmp al, 0
			je stop
			cmp bl, 0
			je stop
			cmp al, bl
			jne stop
			inc rdi
			inc rsi
			jmp start

stop:		sub rax, rbx	
			ret