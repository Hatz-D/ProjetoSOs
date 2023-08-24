#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char nome_1[50] ="Ruan";
  char nome_2[50] = "Lucas";

  int l;
  l = strlen(nome_1);
  
    if(strncmp(nome_1,nome_2,l) < 0){
      printf("%s \n%s \n", nome_1, nome_2);
    }
    else if(strncmp(nome_1,nome_2,l) > 0){
      printf("%s \n%s \n", nome_2, nome_1);
    }
  return 0;
}
