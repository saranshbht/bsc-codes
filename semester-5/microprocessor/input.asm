.model small

.data
msg db 10,"Enter a number:$"
msg1 db 10,"Entered number:$"

.code
mov ax, @data
mov ds, ax

lea dx, msg
mov ah, 09h
int 21h

mov ah, 01h
int 21h

sub al, 30h
mov bl, al
shl bl, 4

mov ah, 01h
int 21h

sub al, 30h
add bl, al

lea dx, msg1
mov ah, 09h
int 21h

rol bl, 4
mov cl, bl
and cl, 0fh
add cl, 30h
mov dl, cl
mov ah, 02h
int 21h

rol bl, 4
mov cl, bl
and cl, 0fh
add cl, 30h
mov dl, cl
mov ah, 02h
int 21h

.exit
end
