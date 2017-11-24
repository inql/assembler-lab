.intel_syntax noprefix
.text
.globl main
 
main:
mov ecx, 1
mov eax, 5
xor edx, edx
xor ebx, ebx
push eax
call function
add esp, 4
push edx
push offset msg
call printf
add esp, 8
mov eax, 0
ret
 
function:
mov edx,0
push ebp
mov ebp, esp
push eax
push ecx
push ebx
mov eax,[ebp+8]
cmp ecx,0
jne f1
mov edx,eax
add edx,1
jmp final
 
f1:
cmp ecx,1
jne f2
mov edx, eax
jmp final
 
f2:
cmp ecx, 2
jne fnext
mov edx, eax
add edx,2
jmp final
 
fnext:
push ecx
sub ecx,1
push edx
push eax
call function
add esp, 4
pop ebx
add edx,edx
pop ecx
push ecx
sub ecx, 2
push edx
push eax
add eax,1
call function
add esp, 4
pop ebx
sub edx,ebx
sub edx,ebx
pop ecx
push ecx
sub ecx,3
push ecx
push eax
call function
add esp, 4
pop ebx
sub ebx,edx
mov edx,ebx
pop ecx
 
final:
pop ebx
pop ecx
pop eax
pop ebp
ret
 
 
.data
msg:
  .asciz "Wynik = %d\n"
  .byte 0
