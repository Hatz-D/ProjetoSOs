#include <stdio.h>

int main(void) {
  int n1 = 10, n2 = 6, n3 = 8, me = 10;
  double media = (n1 + (2*n2) + (3*n3)+ me) / 7;
  if (media >= 9){
    printf("Média A");
  }
  else if (media >= 7.5 && media < 9){
    printf("Média B");
  }
  else if (media >= 6 && media < 7.5){
    printf("Média C");
  }
  else if (media >= 4 && media < 6){
    printf("Média D");
  }
  else{
    printf("Média E");
  }

  return 0;
}
