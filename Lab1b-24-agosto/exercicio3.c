#include <stdio.h>

int main(void) {
  int n = 9;
  for (int i = 0; i <= (n/2) + 1; i++){
    for (int j = i + 1; j <= n - i; j++){
      printf("%d ", j);
    }
    printf("\n");
    for (int k = 0; k < (i+1)*2; k++){
      printf(" ");
    }
  }
  return 0;
}
