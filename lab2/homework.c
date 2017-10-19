/*
Program obliczajacy ilosc wystapien bitow 101 w liczbie
*/
#include <stdio.h>

int main(void){
  int x = 0x0555;
  int y;

  asm volatile(
    ".intel_syntax noprefix;"

    "mov eax, %1;"      //przeniesienie wartosci z argumentu %1 do rejestru eax
    "xor ebx, ebx;"     //zerowanie zmiennej za pomoca XOR'a
    "petla:"            //stworz etykiete petla
      "mov ecx, eax;"   //przenies wartosc z rejestru eax do ecx
      "shr eax;"          //przesuniecie bitowe w prawo
      "and ecx, 0x0007;"  //and ecx z 7 by zostawic 3 ostatnie bity
      "sub ecx, 0x0005;"  //odjecie 5 od 3 ostatnich bitow - jesli 3 ostatnie bity mialyby 101 wartosc odejmowania bedzie rowna 0
      "jnz skok;"         //instrukcja warunkowa - jesli flaga z(zero flag, ma wartość 1, jeśli ostatnia operacja porownania badz arytmetyczna jest rowna 0) jest 0 przejdz do skok
      "inc ebx;"          //inkrementacja ebx
      "skok:"
        "and eax,eax;"      //porownanie eax z 0 za pomoca AND
        "jnz petla;"      //jesli flaga z nie jest zapalona przejdz do petla
      "mov %0, ebx;"
    ".att_syntax prefix"
    :"=r"(y)
    :"r"(x)
    :"eax", "ebx", "ecx"
  );

  printf("x = %d, y = %d\n",x,y);
}
