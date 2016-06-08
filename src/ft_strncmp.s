section .text
    global _ft_strncmp

_ft_strncmp:
    xor         rax, rax

_loop:

    mov         r8, 0
    mov         al, [rdi]
    cmp         al, [rsi]
    jne         _test
    test        al, al
    jz          _finish
    inc         rdi
    inc         rsi
    dec         rdx
    cmp         rdx, 0 ;la longueur para 3
    je          _finish
    jmp         _ft_strncmp

_test:
    xor         rdx, rdx
    mov         bl, [rsi]
    cmp         al, bl
    jg          _add
    cmp         al, bl
    jl          _sub
    cmp         al, bl          
    jmp         _diff


_add:
    inc         r8
    sub         al, 1
    jmp         _test

_sub:
    dec         r8
    add         al, 1
    jmp         _test   
    
_diff:
    mov         rax, r8
    ret         


_finish:
    mov     rax, 0
    ret