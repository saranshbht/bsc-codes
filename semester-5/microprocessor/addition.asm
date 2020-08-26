.model small

.data
msg1 db 10,"Enter number:$"
msg2 db 10,"Result of addition:$"

.code
mov ax, @data
mov ds, ax
 
lea dx, msg1
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
mov cl, bl


lea dx, msg1
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
add cl, bl

lea dx, msg2
mov ah, 09h
int 21h

rol cl, 4
mov bl, cl
and bl, 0fh
add bl, 30h
mov dl, bl
mov ah, 02h
int 21h

rol cl, 4
mov bl, cl
and bl, 0fh
add bl, 30h
mov dl, bl
mov ah, 02h
int 21h

.exit
end
