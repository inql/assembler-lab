#include <stdio.h>

/*
 * Po wykonaniu programu zmienna "y" powinna zawierać długość najdłuższego ciągu identycznych znaków w łańcuchu "s",
 * np. jeżeli s="AaaaBBXBBX", to y powinno wynosić 3.
 */

int main(void)
{
	char s[] = "Abcdefghi07634";
	int y;

    asm volatile
    (   ".intel_syntax noprefix;"




        ".att_syntax prefix;"
        : "=r" (y)
        : "r" (s)
				: "eax"
    );

    printf("s=%s, y=%i\n", s, y);
    return 0;
}
