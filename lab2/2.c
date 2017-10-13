#include <stdio.h>

//dodana wstawka w assembly

int main(void){
  int x = 0xAF03;
  int y;

  asm volatile(
    ".intel_syntax noprefix;"

    "mov eax, %1;"
    "mov ebx, 0;"
    "shr eax;"          //przesuniecie bitowe w prawo
    "jnc skok2;"        //instrukcja warunkowa
    "skok:"
      "add ebx, 1;"
    "skok2:"
      "mov %0, ebx;"
    ".att_syntax prefix"
    :"=r"(y)
    :"r"(x)
    :"eax"
  );

  printf("x = %d, y = %d\n",x,y);
}
