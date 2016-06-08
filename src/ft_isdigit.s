section .text
	global _ft_isdigit

_ft_isdigit:
	cmp			rdi, 48
	jl			_neg
	cmp			rdi, 57
	jg			_neg
	mov			rax, 1
	ret

_neg:
	mov			rax, 0
	ret