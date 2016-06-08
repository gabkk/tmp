section .text
	global _ft_bzero

_ft_bzero:
	cmp			rsi, 0
	jle			_quit
	mov byte	[rdi], 0
	dec			rsi
	inc			rdi
	jmp 		_ft_bzero

_quit:
	ret