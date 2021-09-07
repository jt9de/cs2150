; Filename: mathlib.s
; Author: Jinghui Tian
; Date: 4.13.2021
; int 1 (in rdi)
; int 2 (in rsi)
	global product
	global power

	section .text

product:

    xor rax, rax
    xor r10, r10

product_start:
    cmp r10, rsi
    je product_done
    add rax, rdi
    inc r10

    jmp product_start

product_done:
    ret


power:

	xor	rax, rax
    mov rax, 1

    cmp rsi, 0 ; if rsi != 0, go to power_start
    jne power_start

    mov rax, 1
    jmp power_done
    


power_start:
    
    cmp rsi, 0
    je power_done

    dec rsi

    call power


    push rsi
    mov rsi, rax
    
    call product
    pop rsi



power_done:
	ret


