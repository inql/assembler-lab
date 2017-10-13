#include <stdio.h>

//dodana wstawka w assembly

int main(void){
  int x = 0xAF03;
  int y;

  asm volatile(
    ".intel_syntax noprefix;"

    "mov eax, %1;"
    "xor ebx, ebx;"     //zerowanie zmiennej za pomoca XOR'a
    "xor ecx, ecx;"
    "petla:"            //stworz etykiete petla
      "shr eax;"          //przesuniecie bitowe w prawo
      "jnc skok2;"        //instrukcja warunkowa - jesli flaga c nie jest zapalona przejdz do skok2
      "skok:"
        "inc ebx;"        //inkrementacja ebx
      "skok2:"
        "inc ecx;"
        "cmp ecx,32;"     //porownaj licznik z liczba 32
        "jnz petla;"      //jesli flaga z nie jest zapalona przejdz do petla
      "mov %0, ebx;"
    ".att_syntax prefix"
    :"=r"(y)
    :"r"(x)
    :"eax", "ebx", "ecx"
  );

  printf("x = %d, y = %d\n",x,y);
}
