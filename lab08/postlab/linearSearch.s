; University of Virginia
; CS 2150 post-Lab 8
; Spring 2021
; linearSearch.s
; Jinghui Tian
; 4.15.2021

	global linearSearch

	section .text


; Parameter 1 is a pointer to the int array in rdi
; Parameter 2 is the size of the array in rsi
; Parameter 3 is an integer representing the target element to find in the array in rdx
; Return type is int 
; the index into the array that the target was found, or -1 if it wasn’t in rax

linearSearch:
    ;n = 4 rsi
    ;x = 2 rdx
    ;i = 0
	; Implement linearSearch here
    xor rax, rax
    xor r10, r10 ; int i = 0
    dec r10

loop:
    inc r10
    cmp r10, rsi ; if i >= n, go to done
    jge done

    
    cmp edx, [rdi+4*r10] ; r11 = arr[i]
    ;cmp r11, rdx ; if r11 == x, go to done
    je done
    
    

    
    jmp loop

 


done:
    cmp r10, rsi
    jge done2

    mov rax, r10
    ret
done2:
    mov rax, -1
    ret
