#include <stdio.h>

void multiplicaLinha(int p[3][3], int linha_sel, int coluna, int num){
	for(int j = 0; j < coluna; j++){
		p[linha_sel-1][j] *= num;
		
	}	
}

void multiplicaColuna(int p[3][3], int linha, int coluna_sel, int num){
        for(int i = 0; i < linha; i++){
                p[i][coluna_sel-1] *= num;
                
        }
        
}

void imprime(int linha, int coluna, int p[3][3]){
	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			printf("%d ", p[i][j]);
		}
	printf("\n");
	}
}

int main(){
	int vet[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	printf("Matriz original:\n");
	imprime(3, 3, vet);
	printf("\nLinha 2 da matriz multiplicada pelo número 2:\n");
	multiplicaLinha(vet, 2, 3, 2);
	imprime(3, 3, vet);
	printf("\nColuna 3 da matriz multiplicada pelo número 0:\n");
	multiplicaColuna(vet, 3, 3, 0);
	imprime(3, 3, vet);

	return 0;
}
