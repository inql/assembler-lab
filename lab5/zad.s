.intel_syntax noprefix
.text
.global main

main:
mov eax, 2
mov ecx, 4
xor ebx, ebx
xor edx, edx
push ecx
call function:
add esp, 4
push ebx
push offset msg
call printf
add esp, 8
mov ecx, 0
ret

function:
mov edx, 0
push ebp
mov ebp, esp


.data
msg:
	.asciz "Wynik = %d\n"
	.byte 0
