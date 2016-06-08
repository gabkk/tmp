section .text
	global _ft_isprint

_ft_isprint:
	cmp			rdi, 32
	jl			_neg
	cmp			rdi, 126
	jg			_neg
	mov			rax, 1
	ret

_neg:
	mov			rax, 0
	ret