#include<stdio.h>

int main()
{
	//int x;
	char x[] = "hgjhkjffffkutsssvjkiy";
	//printf("Podaj x: \n");
	//scanf("%i",&x);
	int y=0;
	
	asm volatile (
	".intel_syntax noprefix;"

	"mov eax,%1;" //eax-wskaźnik
	"xor ebx,ebx;" // h-największy, l-aktualny
	"xor ecx,ecx;" // h-ostatni znak, l-wzór
	"mov ch,[eax];"
	"mov cl,[eax];"
	"and ch,ch;"	
	"jz koniec;"
"petla:"
	"cmp ch,cl;"
	"jz jesli_takie_same;"//
	"mov cl,ch;"
	"mov bl,1;"
	"jmp skok;"//
"jesli_takie_same:" // jeśli flaga z  = 0
	"inc bl;"
	"cmp bh,bl;"
	"jns skok;"//
	"mov bh,bl;"
"skok:"
	"inc eax;"
	"mov ch,[eax];"
	"and ch,ch;"
 	"jnz petla;"//
	
"koniec:"	
	"movsx %0,bh;"
	".att_syntax prefix;"
	: "=r" (y)
	: "r" (x)
	: "eax","ebx","ecx"
	);
	printf("x=%s, y=%i\n",x,y);
	return 0;
}









