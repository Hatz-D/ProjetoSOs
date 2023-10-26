#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

double pi = 0;

void* calculaPi(void* arguments) {
    int* args = (int*) arguments;
    int n = args[0];
    int slice = args[1];
    
    double factor;
    double sum = 0;
    int inicio = n * slice;
    int fim = inicio + slice;
    
    if(inicio % 2 == 0) {
    	factor = 1.0;
    }

    else {
	factor = -1.0;  
    }

    for(int i = inicio; i < fim; i++, factor = -factor) {
	sum += factor/(2*i+1);
    }

    pi += sum;
    free(arguments); 
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Arg1 = Quantidade de threads. Arg2 = Quantidade de somas por thread\n");
        return 1;
    }

    int n = strtol(argv[1], NULL, 10);
    int slice = strtol(argv[2], NULL, 10);

    pthread_t* thread_array = malloc(n * sizeof(pthread_t));

    for (int i = 0; i < n; i++) {
	int * arguments = (int*) malloc(2 * sizeof(int));
	arguments[0] = i;
	arguments[1] = slice;
        pthread_create(&thread_array[i], NULL, calculaPi, (void*)arguments);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(thread_array[i], NULL);
    }

    pi = 4 * pi;
    printf("\nNúmero de threads: %d\nQuantidade de somas por thread: %d\nValor de pi: %.20lf\n", n, slice, pi);

    free(thread_array);
    return 0;
}
