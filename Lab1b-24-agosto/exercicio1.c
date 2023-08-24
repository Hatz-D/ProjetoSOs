#include <stdio.h>

int main(void) {
  int menor = 10;
  int linha = 0;
  int matriz[3][3] = {{1,5,6},
                      {8,9,7},
                      {2,3,4}};
  
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (matriz[i][j] < menor){
        menor = matriz[i][j];
        linha = i+1;
      }
    }
  }
  printf("elemento %d na linha %d\n", menor, linha);
  return 0;
}
