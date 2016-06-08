section .text
	global _ft_tolower

_ft_tolower:
	cmp			rdi, 65
	jl			_notlow
	cmp			rdi, 90
	jg			_notlow
	mov			rax, rdi
	add			rax, 32
	ret

_notlow:
	mov			rax, rdi
	ret
