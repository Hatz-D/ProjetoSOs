#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * multiplicamatrizes(void* arguments) {
	int *** matrizes = (int***)arguments;
	int i = matrizes[3][0][0];
	int j = matrizes[3][1][0];
	int n = matrizes[3][2][0];

	for(int k = 0; k < n; k++) {
		matrizes[2][i][j] += matrizes[0][i][k] * matrizes[1][k][j];
	}

	return NULL;
}

void imprimematriz(int matriz[][], int i, int j) {
	for(int k = 0; k < i; k++) {
		for(int l = 0; l < j; l++) {
			printf("%d ", matriz[i][j]);
		}

		printf("\n");
	}
}

int main() {
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
	
	int m = sizeof(matrizA)/sizeof(matrizA[0]);
	int n1 = sizeof(matrizA[0])/sizeof(int);
	int n2 = sizeof(matrizB)/sizeof(matrizB[0]);
	int p = sizeof(matrizB[0])/sizeof(int);

	if(n1 != n2) {
		fprintf(stderr, "A quantidade de colunas da matriz A deve ser igual à quantidade de linhas da matriz B!\n");
		return 1;
	}

	int ** matrizC = (int**) malloc(m * sizeof(int*));

	for(int i = 0; i < m; i++) {
		matrizC[i] = (int*) calloc(p, sizeof(int));
	}

	int *** matrizes = (int***) malloc(4 * sizeof(int**)); 

	matrizes[0] = matrizA;
	matrizes[1] = matrizB;
	matrizes[2] = matrizC;

	pthread_t* thread_array = malloc(m * p * sizeof(pthread_t));

	int contador = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < p; j++) {
			matrizes[3] = (int**) malloc(3 * sizeof(int*));
			matrizes[3][0] = (int*) malloc(sizeof(int));
			matrizes[3][1] = (int*) malloc(sizeof(int));
			matrizes[3][2] = (int*) malloc(sizeof(int));
			matrizes[3][0][0] = i;
			matrizes[3][1][0] = j;
			matrizes[3][2][0] = n1;

			pthread_create(&thread_array[contador], NULL, multiplicamatrizes, (void*)matrizes);
			contador++;
		}
	}


	for(int i = 0; i < contador; i++) {
		pthread_join(thread_array[i], NULL);
	}

	printf("Matriz A:\n");
	imprimematriz(matrizA, m, n1);
	printf("Matriz B:\n");
	imprimematriz(matrizB, n2, p);
	printf("Matriz C = Matriz A x Matrix B:\n");
	imprimematriz(matrizC, m, p);

	free(matrizC);
	free(matrizes);
	return 0;
}
