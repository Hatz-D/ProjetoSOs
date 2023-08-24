#include <stdio.h>

void soma(int p[3][3], int coluna){
	for(int j = 0; j < coluna; j++){
		p[1][j] = p[0][j] + p[1][j];
		
	}	
}

void multiplica(int p[3][3], int linha){
        for(int i = 0; i < linha; i++){
                p[1][i] = p[0][i] * p[1][i];
                
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
	printf("\nL2 = L1 + L2:\n");
	soma(vet, 3);
	imprime(3, 3, vet);
	printf("\nL2 = L1 * L2\n");
	multiplica(vet, 3);
	imprime(3, 3, vet);

	return 0;
}
