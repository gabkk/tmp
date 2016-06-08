section .text
	global _ft_toupper

_ft_toupper:
	cmp			rdi, 97
	jl			_notlow
	cmp			rdi, 122
	jg			_notlow
	mov			rax, rdi
	sub			rax, 32
	ret

_notlow:
	mov			rax, rdi
	ret