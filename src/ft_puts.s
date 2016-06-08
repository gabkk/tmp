section .text
	global _ft_puts
	extern _ft_strlen

str:
	.null db "(null)", 10

_ft_puts:
	push 		rbp
	mov			rbp, rsp
	sub			rsp, 16
	cmp			rdi, 0
	je			_null
	mov			r8, rdi
	call		_ft_strlen
	jmp			_printstr

_printstr:
	mov			rdi, 1 ; std output
	mov			rsi, r8 ;adress to pas to
	mov			rdx, rax ; length of output
	mov			rax, 0x2000004 ; write
	syscall	
	jmp			_printn

_printn:
	mov			rax, 0x2000004 ; write
	mov			rdi, 1 ; std output
	lea			rsi, [rel str.null + 6] ;print /n
	mov			rdx, 1 ; length of output
	syscall
	jmp			_quit

_null:
	mov			rax, 0x2000004
	mov			rdi, 1
	lea			rsi, [rel str.null]
	mov			rdx, 7
	syscall

_quit:
	mov			rax, 0
	leave
	ret
