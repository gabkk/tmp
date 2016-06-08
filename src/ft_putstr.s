section .text
	global _ft_putstr
	extern _ft_strlen

_ft_putstr:
	push		rbp
	mov			rbp,rsp
	sub			rsp, 16
	push		rdi
	call		_ft_strlen
	pop			rsi
	mov			rdi, 1
	mov			rdx, rax; retour de strlen
	mov			rax, 0X2000004 ;et on balance un gros write
	syscall
	mov			rax, 0
	leave
	ret
