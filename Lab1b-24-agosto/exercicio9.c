#include <stdio.h>
#include <stdlib.h>

#define tamL 3
#define tamC 3

#include <stdio.h>

void substituiNegativo (int matriz[tamL][tamC]) {
    int i, j;
    
    for (i = 0; i < tamL; i++){
        for(j = 0; j < tamC; j++){
            if(matriz[i][j] < 0){
                matriz[i][j] = matriz[i][j] *(-1);
            }
        }
    }
}



int main() {
    int l, c, trans[tamC][tamL];

   int mat[tamL][tamC] ={{-10, -20, -30},
                        {-50, -60, -70},
                        {-90, -11, -22} };

    printf("\nMatriz original:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%3d ", mat[l][c]);
        }
        printf("\n");
    }
    
    substituiNegativo(mat);
    
    printf("\nMatriz sem negativo:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%3d ", mat[l][c]);
        }
        printf("\n");
    }

    return 0;
}
