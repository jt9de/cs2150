; optimization 1: used lea instead of imul and add in is_odd
; optimization 2: used rdi*2 + rdi instead of rdi*3
; optimization 3: used fewer instructions such as unnecessary xor rax, rax
; University of Virginia
; CS 2150 pre-lab 9
; Spring 2021
; threexplusone.s
; Jinghui Tian
; 4.19.2021

	global threexplusone

	section .text


; Parameter 1 is a positive integer in rdi

; Return type is int 

    
threexplusone:

    test rdi, 1
    jnz is_odd

    jmp is_even

is_odd:
    lea rdi, [rdi*2 +rdi +1]
    jmp next

is_even:
    shr rdi, 1
    jmp next

next:
    add DWORD [rbp-4], 1
    cmp rdi, 1
    jle done
    call threexplusone

done:
    mov rax, [rbp-4]
    ret

