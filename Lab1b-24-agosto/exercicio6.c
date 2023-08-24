#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamL, tamC;
    int l, c;
    int i, j;

    printf("******Dimensao da matriz******\n");
    printf("Digite o numero de linhas\n");
    scanf("%d", &tamL);
    printf("Digite o numero de colunas\n");
    scanf("%d", &tamC);

    int mat[tamL][tamC], trans[tamC][tamL];

    printf("\n******Digite as entradas da matriz******\n");
    for (i=0; i<tamL; i++){
        printf("Digite as entradas para a %d linha\n", i+1);
        for (j=0; j<tamC; j++)
            scanf("%d", &mat[i][j]);
            }   


    printf("\nMatriz original:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%3d ", mat[l][c]);
        }
        printf("\n");
    }

    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            trans[c][l] = mat[l][c];
        }
    }

    printf("\nMatriz transposta:\n");
    for(l = 0; l < tamC; l++){
        for(c = 0; c < tamL; c++){
            printf("%3d ", trans[l][c]);
        }
        printf("\n");
    }

    return 0;
}
