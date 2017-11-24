#include <stdio.h>

int main(void)
{
	char s[] = "Abcdefghi07634";

    asm volatile
    (   ".intel_syntax noprefix;"
				"mov eax, %0;"

				"petla:"
					"mov bl, byte ptr [eax];"
					"cmp bl,0;"
					"je wyjscie;"



					"cmp bl,'a';"
					"jb koniec_petli;"
					"cmp bl,'z';"
					"ja koniec_petli;"

					"sub bl, 32;"
					"mov byte ptr [eax], bl;"

				"koniec_petli:"
					"inc eax;"
					"jmp petla;"

				"wyjscie:"
			        ".att_syntax prefix;"
			        :
			        : "r" (s)
				: "eax", "ebx"
    );

    printf("s=%s\n", s);
    return 0;
}
