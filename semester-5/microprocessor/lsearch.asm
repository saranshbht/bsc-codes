.model small

.data
    msg db 10, "Element found$", 10
    msg1 db 10, "Element not found$", 10
    msg2 db "Enter element to be searched: $"
    A db 09h, 10h, 78h, 54h, 1ah
.code
    .startup
        lea dx, msg2
        mov ah, 09h
        int 21h

        mov cx, 2h
        mov dl, 0h
        input:
            shl dl, 4
            mov ah, 01h
            int 21h
            cmp al, 39h
            jbe input2
            sub al, 07h
            input2:
                sub al, 30h
                add dl, al
        loop input



        mov si, 0h
        mov cx, 5h
        arr:
            cmp A[si], dl
            je print1
            inc si
        loop arr

        jmp print2

        print1:
            lea dx, msg
            mov ah, 09h
            int 21h
            jmp exit
        
        print2:
            lea dx, msg1
            mov ah, 09h
            int 21h
    
        exit:
    .exit
end