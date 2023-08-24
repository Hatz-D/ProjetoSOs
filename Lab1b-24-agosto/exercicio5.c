#include <stdio.h>

void multiplicaLinha(int linha, int coluna, int p[linha][coluna], int linha_sel, int num){
        for(int j = 0; j < coluna; j++){
                p[linha_sel-1][j] *= num;
         
        }
}

void multiplicaColuna(int coluna, int linha, int p[linha][coluna], int coluna_sel, int num){
        for(int i = 0; i < linha; i++){
                p[i][coluna_sel-1] *= num;

        }

}

void imprime(int linha, int coluna, int p[linha][coluna]){
        for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                        printf("%d ", p[i][j]);
                }
        printf("\n");
        }
}

int main(){
    int tamL, tamC;
    int l, c;
    int i, j;
    printf("******Dimensao da matriz******\n");
    printf("Digite o numero de linhas\n");
    scanf("%d", &tamL);
    printf("Digite o numero de colunas\n");
    scanf("%d", &tamC);

    int mat[tamL][tamC];

    printf("\n******Digite as entradas da matriz******\n");
    for (i=0; i<tamL; i++){
        printf("Digite as entradas para a %d linha\n", i+1);
        for (j=0; j<tamC; j++)
            scanf("%d", &mat[i][j]);
    }


        printf("\nMatriz original:\n");
        imprime(tamL, tamC, mat);
        printf("\nLinha 2 da matriz multiplicada pelo número 2:\n");
        multiplicaLinha(tamL, tamC, mat, 2, 2);
        imprime(tamL, tamC, mat);
        printf("\nColuna 3 da matriz multiplicada pelo número 0:\n");
        multiplicaColuna(tamC, tamL, mat, 3, 0);
        imprime(tamL, tamC, mat);

        return 0;
}
