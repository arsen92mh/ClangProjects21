section .text
global _ft_strcpy

_ft_strcpy:	mov rax, 0
			jmp start

start:		mov cl, byte[rsi + rax]
			mov byte[rdi + rax], cl
			cmp cl , 0
			je stop
			inc rax
			jmp start
			
stop:		mov rax, rdi
			ret