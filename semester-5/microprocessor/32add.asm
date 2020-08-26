.model small

.data 
    first dw 5678h, 1234h
    second dw 5678h, 1234h
    result dw 2 dup(0)
    temp dw ?
    msg db "Result: $", 10

.code
    .startup
    mov si, 0h
    lea dx, msg
    mov ah, 09h
    int 21h

    mov cx, 2h
    clc
    arr:
        mov dx, first[si]
        adc dx, second[si]
        mov result[si], dx
        inc si
        inc si
    loop arr

    mov cx, 2h
    jnc print2

    mov dl, 31h
    mov ah, 02h
    int 21h

    
    ; mov si, 1h
    
    print2:
        dec si
        dec si
        mov temp, cx
        mov bx, result[si]
        mov cx, 4
            print: 
                rol bx, 4
                mov dl, bl
                and dl, 0fh
                add dl, 30h
                cmp dl, 39h
                jbe print12
                add dl, 07h
                print12:
                    mov ah, 02h
                    int 21h
            loop print
        mov cx, temp
    loop print2
    .exit
end