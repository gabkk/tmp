section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit	

_ft_isalnum:
	call		_ft_isalpha
	cmp			rax, 1
	je			_pos
	call		_ft_isdigit
	cmp			rax, 1
	je			_pos
	mov			rax, 0
	ret

_pos:
	mov			rax, 1
	ret