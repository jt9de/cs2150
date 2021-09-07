; University of Virginia
; CS 2150 post-Lab 9
; Spring 2021
; binarySearch.s
; Jinghui Tian
; 4.21.2021

	global binarySearch

	section .text


; Parameter 1 is a pointer to an int array in rdi
; Parameter 2 is an integer representing the beginning of the array in rsi
; Parameter 3 is an integer representing the end of the array in rdx
; Parameter 4 is an integer representing the target element to find in the array in rcx

; Return type is int 
; the index into the array that the target was found, or -1 if it wasn’t in rax

binarySearch:
    cmp rsi, rdx ; if l > r , go to done
    jg done


middle:
    mov r10, rsi ; r10 = middle
    add r10, rdx ; middle = (left + right) /2
    shr r10, 1

    cmp [rdi + 4*r10], ecx; if [middle] < x, return middle
    jl done2



else_if:
    cmp [rdi + 4*r10], ecx; if middle > x, go to done3
    jg done3

    jmp else

else:
    mov rax, r10
    ret

done:
    mov rax, -1
    ret

done2:
    inc r10
    mov rsi, r10
    jmp binarySearch


done3:
    dec r10
    mov rdx, r10
    jmp binarySearch
