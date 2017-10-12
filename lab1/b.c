#include<stdio.h>
int main(void){
  int x = 1;
  int y = 0;

  asm volatile (
    ".intel_syntax noprefix;"
    "mov eax,%1;"
    "add eax,eax;"
    "mov %0,eax;"
    ".att_syntax prefix;"
    :"=r" (y)
    :"r" (x)
    :"eax"
  );

  printf("x=%i, y=%i\n",x,y);
  return 0;
}
