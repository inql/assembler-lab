.intel_syntax noprefix

.global main

.text

main:
    push ebp
    mov ebp, esp

    mov eax, [ebp+12]
    mov ebx, [eax+8];//pobranie drugiego argumentu ze stosu (napis)

    push ebx
    call atoi ;//zamiana 2 argumentu na liczbę
    add esp,4

    push eax ;//2 argument na stos (liczba)

    mov eax, [ebp+12]
    mov ebx, [eax+4]; //pobranie pierwszego argumentu ze stosu (napis)

    push ebx
    call atoi ;//zamiana 1 argumentu na liczbę
    add esp,4

    call funkcja
    
    push ebx
    mov eax, offset napis
    push eax
    call printf
    add esp,8
  
    mov esp, ebp
    pop ebp
    ret

funkcja:
    push ebp
    mov ebp, esp
    push eax
    push ecx
    push edx

    xor ebx, ebx
    
    cmp eax, 0
    je fzero

    cmp eax, 1
    je fjeden

    cmp eax, 2
    je fdwa
    jg fn

    jmp funk_koniec
    
fzero:
    mov ebx, [ebp+8]
    inc ebx
    jmp funk_koniec

fjeden:
    mov ebx, [ebp+8]
    inc ebx
    inc ebx
    jmp funk_koniec

fdwa:
    mov ebx, [ebp+8]
    jmp funk_koniec
fn:
    xor ecx, ecx

    dec eax
    mov ebx, [ebp+8]
    push ebx
    call funkcja
    
    add ecx, ebx

    dec eax    
    mov ebx, [ebp+8]
    inc ebx
    push ebx
    call funkcja

    add ecx, ebx

    dec eax
    mov ebx, [ebp+8]
    push ebx
    call funkcja
    
    sub ecx, ebx
    sub ecx, ebx    
    
funk_koniec: 
    pop edx
    pop ecx
    pop eax
    mov esp, ebp
    pop ebp
    ret 4

.data

napis:
.asciz "wynik: %i\n"
