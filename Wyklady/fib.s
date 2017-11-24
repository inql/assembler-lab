.intel_syntax noprefix

.global main

.text

main:
	push ebp;
	mov ebp, esp;
//	enter 0,0;

	mov eax, [ebp+12]
	mov ebx, [eax+4]

	push ebx
	call atoi
	add esp, 4

	// zapamietujemy na stosie pobrane z linii zlecen "n"
	push eax

	mov eax, [ebp+12]
	mov ebx, [eax+8]
	push ebx
	call atoi
	add esp, 4

	pop ebx ; // "n"
	push eax ; // "m"

	call fib
	add esp, 4

	// drugi argument printf-a
	push eax	

	// pierwszy argument printf-a
	mov eax, offset komunikat
	push eax	

	call printf
	add esp, 8

	mov eax, 0 ; // return 0

	mov esp, ebp
	pop ebp;
//	leave;

	ret

fib:
	push ebp
	mov ebp, esp
	sub esp,12

	mov [ebp-4], ebx

	cmp dword ptr [ebp-4], 2
	jae skok

	mov eax, [ebp+8]
	jmp fib_koniec

skok:
	dec dword ptr [ebp-4]
	push [ebp+8]
	mov ebx, [ebp-4]
	call fib
	add esp, 4
	mov [ebp-8],eax
	

	dec dword ptr [ebp-4]
	push [ebp+8]
	mov ebx, [ebp-4]
	call fib
	add esp, 4
	mov [ebp-12], eax

	mov eax, [ebp-8]
	add eax, [ebp-12]

fib_koniec:
	mov esp, ebp
	pop ebp
	ret

.data

komunikat:
.asciz "wynik=%i\n"

