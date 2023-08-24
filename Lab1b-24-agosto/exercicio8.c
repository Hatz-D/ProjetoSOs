#include <stdio.h>
#include <stdlib.h>

#define tamL 3
#define tamC 3
#define LIM 25


#include <stdio.h>

void matriz_transposta (int l, int c, int matriz[l][c]) {
    int i, j, aux;
  
    for (i = 0; i < l; i++) {
        for (j = i+1; j < c; j++) {
        if (j != i) {
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
      }
    }
  }

    printf("\nMatriz transposta:\n");
    for(l = 0; l < tamC; l++){
        for(c = 0; c < tamL; c++){
            printf("%3d ", matriz[l][c]);
        }
        printf("\n");
    }
}


int main() {
    int l, c, trans[tamC][tamL];

   int mat[tamL][tamC] = {{10, 20, 30},
                        {50, 60, 70},
                        {90, 11, 22} };

    printf("\nMatriz original:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%3d ", mat[l][c]);
        }
        printf("\n");
    }
    
    matriz_transposta(tamL, tamC, mat);

    return 0;
}

