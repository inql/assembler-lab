#include <stdio.h>

int main(void)
{
	int x = 777;
	int y = -1;
	int z = 0;

	// y = x*20;

    asm volatile
    (   ".intel_syntax noprefix;"

        "mov eax, %1;"
				"mov ebx, %2;"
				"cmp eax, ebx;"
				"jge skok;"
				"mov eax, ebx;"
				"skok:"
				"mov %0, eax;"
        ".att_syntax prefix;"
        : "=r" (z)
        : "r" (x), "r" (y)
	: "eax", "ebx"
    );

    printf("x=%d, y=%d, z=%d\n", x, y, z);
	return 0;
}
