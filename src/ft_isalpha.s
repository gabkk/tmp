section .text
	global _ft_isalpha

_ft_isalpha:
	cmp			rdi, 65
	jl			_neg
	cmp			rdi, 90
	jg			_test2
	mov			rax, 1
	ret

_test2:
	cmp			rdi, 97
	jl			_neg
	cmp			rdi, 122
	jg			_neg	
	mov			rax, 1
	ret

_neg:
	xor			rax, rax
	ret
