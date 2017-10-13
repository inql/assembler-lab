#include<stdio.h>
//liczenie zapalonych bitow - implementaca w C
int main(void){
  int x = 0xAF03;
  int y;

  int i;
  y=0;

  for(i=0; i<32; i++){
    if(x%2==1){
      y++;
    }
    x=x>>1;
  }

  printf("%d\n",y);
}
