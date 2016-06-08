section .text
	global _ft_strcmp

_ft_strcmp:
	xor			rax, rax

_loop:
 	mov			r8, 0
    mov         al, [rdi]
	cmp			al, [rsi]
	jne			_test
	test    	al, al
    jz          _finish
    inc         rdi
    inc         rsi
    jmp         _ft_strcmp

_test:
	mov			bl, [rsi]
	cmp			al, bl
	jg			_add
	cmp			al, bl
	jl			_sub
	cmp			al, bl			
	jmp			_diff


_add:
	inc			r8
	sub			al, 1
	jmp			_test

_sub:
	dec			r8
	add			al, 1
	jmp			_test	
	
_diff:
	mov			rax, r8
    ret         


_finish:
	mov		rax, 0
	ret