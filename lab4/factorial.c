#include<stdio.h>

int main(){

	int x = 5;
	int y = 0;
	asm volatile (
	".intel_syntax noprefix;"
	"mov eax, 1;"
	"mov ebx, %1;"
	"cmp ebx, 0;"
	"jle end;"
	"push ebx;"
	"call factorial;"
	"jmp end;"
	"factorial:"
		"cmp ebx, 1;"
		"jne count;"
		"ret;"
	"count:"
		"push ebx;"
		"dec ebx;"
		"call factorial;"
		"pop ebx;"
		"mul ebx;"
		"ret;"
	"end:"
		"mov %0, eax;"
		".att_syntax prefix;"
		: "=r" (y)
		: "r" (x)
		: "eax", "ebx"
	);

	printf("x = %d, x! = %d \n", x,y);
	return 0;
}
