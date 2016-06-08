section .text
	global _ft_memset

_ft_memset:
	mov			rcx, rdx ;we mov len in rcx for the repetor
	mov			rax, rsi
	rep			stosb
	xor			rax, rax
	mov			rax, rdi
	ret

