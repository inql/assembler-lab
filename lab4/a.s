.intel_syntax noprefix

.global main

.text

main:
	mov ebx, 8
	push ebx
	call suma
	ret
suma:
	mov ebx, [esp+4]
	cmp ebx, 1
	jne skok
	mov eax, 1
	ret 4
skok:
	push ebx
	dec ebx
	push ebx
	call suma
	pop ebx
	add eax,ebx
	ret 4
