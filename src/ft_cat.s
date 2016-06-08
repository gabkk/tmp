
section .bss
var:
	.buffer resb 256

section .text
	global _ft_cat
	extern _ft_bzero

_ft_cat:
	push			rdi
	lea				rdi, [rel var.buffer]
	mov				rsi, 256
	call			_ft_bzero
	pop				rdi
	push			rdi
	mov				rax, 0x2000003 ; read
	lea				rsi, [rel var.buffer]
	mov				rdx, 256
	syscall
	jc				_error
	cmp				rax, 0 ; si retour read vide go end
	jle				_quit
	mov				rdx, rax
	mov				rax, 0x2000004; write
	mov				rdi, 1
	lea				rsi, [rel var.buffer]
	syscall
	jc				_error
	pop				rdi
	jmp				_ft_cat

_quit:
	pop				rdi
	mov				rdi, 0
	ret

_error:
	pop				rdi
	mov				rax, 1
	ret
