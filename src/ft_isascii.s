section .text
	global _ft_isascii

_ft_isascii:
	cmp			rdi, 0
	jl			_neg
	cmp			rdi, 128
	jge			_neg
	mov			rax, 1
	ret

_neg:
	mov			rax, 0
	ret