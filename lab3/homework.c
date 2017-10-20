//policzyć najdłuższy ciąg jedynek (bitowo) w liczbie

#include<stdio.h>

int main(void){

	int x = 0x0000;
	int y;

	asm volatile(
	".intel_syntax noprefix;"
	
	"mov eax, %1;"	//liczba
	"xor ebx, ebx;"	//obecna dlugosc ciagu jedynek
	"xor ecx, ecx;"	//najdluzszy ciag jedynek (max)

	"loop:"		//etykieta loop
	"shr eax;"	//przesun eax w prawo o 1 bit
	"jc one;"	//jesli w fladze c jest wartosc 1 przejdz do etykiety one
	"xor ebx, ebx;"	//jesli bylo 0, wyczysc ebx
	"jmp jump;"	//przejdz do jump(omin porownania)

	"one:"		//etykieta one
	"inc ebx;"	//zwieksz ebx - dlugosc obecnego ciagu jedynek
	"cmp ebx, ecx;"	//porownaj ebx z ecx
	"js jump;"	//jesli w fladze s (sign flag) jest 1 (czyli odejmowanie dalo wynik ujemny) przejdz do jump (czyli ebx<ecx)
	"mov ecx, ebx;" //przeniesc do ecx (max) wartosc ebx

	"jump:"
	"and eax,eax;"      //porownanie eax z 0 za pomoca AND
        "jnz loop;"      //jesli flaga z nie jest zapalona przejdz do petla


	"mov %0, ecx;"
  	".att_syntax prefix"
    	:"=r"(y)
    	:"r"(x)
    	:"eax", "ebx", "ecx"
);
	 printf("x = %x, y = %d\n",x,y);
}
