#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int matrizA[10][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                     {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
                     {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
                     {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
                     {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
		     {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
                     {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
                     {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
                     {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}};

int matrizB[10][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                     {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
                     {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
                     {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
                     {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
                     {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
                     {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
                     {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
                     {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}};

int matrizC[10][10];

pthread_mutex_t mutex;

void * multiplicamatrizes(void * args) {
	int * arguments = (int*) args;
	int i = arguments[0];
	int j = arguments[1];
	int n = arguments[2];

	int celula = 0;

	for(int k = 0; k < n; k++) {
		celula += matrizA[i][k] * matrizB[k][j];
	}

	pthread_mutex_lock(&mutex);
	matrizC[i][j] = celula;
	pthread_mutex_unlock(&mutex);
	free(arguments);
	return NULL;
}

void imprimematriz(int matriz[][10], int linha, int coluna) {
	for(int i = 0; i < linha; i++) {
		for(int j = 0; j < coluna; j++) {
			printf("%d ", matriz[i][j]);
		}

		printf("\n");
	}
}

int main() {
	int m = sizeof(matrizA)/sizeof(matrizA[0]);
	int n1 = sizeof(matrizA[0])/sizeof(int);
	int n2 = sizeof(matrizB)/sizeof(matrizB[0]);
	int p = sizeof(matrizB[0])/sizeof(int);

	if(n1 != n2) {
		fprintf(stderr, "A quantidade de colunas da matriz A deve ser igual à quantidade de linhas da matriz B!\n");
		return 1;
	}

	pthread_t* thread_array = malloc(m * p * sizeof(pthread_t));
	pthread_mutex_init(&mutex, NULL);

	int contador = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < p; j++) {
			int * args = (int*) malloc(3 * sizeof(int));
			args[0] = i;
			args[1] = j;
			args[2] = n1;
			pthread_create(&thread_array[contador], NULL, multiplicamatrizes, (void*)args);
			contador++;
		}
	}

	for(int i = 0; i < contador; i++) {
		pthread_join(thread_array[i], NULL);
	}

	printf("\nMatriz A:\n");
	imprimematriz(matrizA, m, n1);
	printf("\nMatriz B:\n");
	imprimematriz(matrizB, n2, p);
	printf("\nMatriz C = Matriz A x Matrix B:\n");
	imprimematriz(matrizC, m, p);

	return 0;
}
