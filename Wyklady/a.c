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
				"jge skok;" //jump greater equal
				"mov eax, ebx;"
				"skok:"
				"mov %0, eax;"
        ".att_syntax prefix;"
        : "=r" (z) // z - %0
        : "r" (x), "r" (y) //x - %1, y - %2
	: "eax", "ebx"
    );

    printf("x=%d, y=%d, z=%d\n", x, y, z);
	return 0;
}
