#include <stdio.h>

//dodana wstawka w assembly

int main(void){
  int x = 0xAF03;
  int y;

  asm volatile(
    ".intel_syntax noprefix;"

    "mov eax, %1;"
    "xor ebx, ebx;"
    "shr eax;"          //przesuniecie bitowe w prawo
    "jnc skok2;"        //instrukcja warunkowa
    "skok:"
      "inc ebx;"
    "skok2:"
      "mov %0, ebx;"
    ".att_syntax prefix"
    :"=r"(y)
    :"r"(x)
    :"eax"
  );

  printf("x = %d, y = %d\n",x,y);
}
