#include<stdio.h>
/*
 * Po wykonaniu programu zmienna "y" powinna zawierać długość najdłuższego ciągu identycznych znaków w łańcuchu "s",
 * np. jeżeli s="AaaaBBXBBX", to y powinno wynosić 3.
 */
int main()
{
	char x[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	;
	int y=0;

	asm volatile (
	".intel_syntax noprefix;"

	"mov eax,%1;" //przenies zawartosc x do rejestru eax
	"xor ebx,ebx;" // zerowanie rejestru ebc, bedziemy korzystac z 8 bitowych rejestrow bh i bl, oznaczenia:  h-dlugosc najwiekszego ciagu, l-dlugosc aktualnego ciagu
	"xor ecx,ecx;" // h-ostatni znak, l-wzór
	"mov ch,[eax];" // przenosimy ostatni znak do ch
	"mov cl,[eax];" // ustawiamy ostatni znak jako wzor przed rozpoczeciem petli
	"and ch,ch;" // sprawdzanie czy ciag znakow nie jest pusty za pomoca AND
	"jz end;" // jezeli w fladze z (zero flag po and) jest 1, oznacza ze ciag jest pusty - wychodzimy z programu
	"loop:" // etykieta loop
		"cmp ch,cl;" //porownujemy ostatni znak ze wzorem
		"jz if_same_chars;" //sprawdzamy flage z, jesli porownanie dalo wynik 0 (czyli sa takie same), przejdz do etykiety if_same_chars
		"mov cl,ch;" //jesli nie, zmien wzor na ostatni znak
		"mov bl,1;" //dlugosc aktualnego ciagu zmien na 1(bo pierwszy znak zostal pobrany)
		"jmp jump;" //przejdz do etykiety jump
	"if_same_chars:" //etykieta if_same_chars
		"inc bl;" //jesli znaki byly takie same to zwieksz dlugosc aktualnego ciagu
		"cmp bh,bl;" //porownaj dl aktualna z najdluzsza
		"jns jump;" //jesli flaga sign nie jest zapalona przejdz do etykiety jump (czyli - gdy gdy dlugosc aktualna nie przekracza najdluzszej)
		"mov bh,bl;" //ustaw aktualny ciag jako najdluzszy
	"jump:"	//etykieta jump
		"inc eax;" //pobierz nastepny znak z tablicy
		"mov ch,[eax];" //ustaw go jako ostatni znak
		"and ch,ch;"	//sprawdz czy ciag nie jest pusty
	 	"jnz loop;" //przejdz do petli jesli nie

"end:"
	"movsx %0,bh;"
	".att_syntax prefix;"
	: "=r" (y)
	: "r" (x)
	: "eax","ebx","ecx"
	);
	printf("x=%s, y=%i\n",x,y);
	return 0;
}
