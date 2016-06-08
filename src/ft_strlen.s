section .text
	global _ft_strlen

_ft_strlen:
	cld					;preparefor increasing address
	mov			rcx, -1
	xor			rax, rax
	repne		scasb
	mov			rax, -2
	sub			rax, rcx
	ret
