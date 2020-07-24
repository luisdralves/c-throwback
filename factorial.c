#include <stdio.h>

int factorial(int x){
  if(x<=1)
    return 1;
  return x*factorial(x-1);
}

int main(){
  int x;
  printf("x=?");
  scanf("%d",&x);
  printf("x!=%d\n",factorial(x));
  return 0;
}
