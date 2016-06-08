section .text
	global _ft_strcat


_ft_strcat:
	mov			rax, rdi
	jmp			_begin

_begin:
	cmp	byte	[rdi], 0
	je			_cat
	inc			rdi
	jmp			_begin

_cat:
	cmp	byte	[rsi], 0
	je			_quit
	mov			rcx, [rsi]
	mov			[rdi], cl
	inc			rsi
	inc			rdi
	jmp			_cat

_quit:
	mov	byte	[rdi], 0
	ret
