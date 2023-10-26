#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

double pi = 0;

void* calculaPi(void* arguments) {
    int* args = (int*) arguments;
    int n = args[0];
    
    if(n % 2 == 0) {
    	pi += 1.0/(2 * n + 1);
    }

    else {
	pi += -1 * (1.0/(2 * n + 1));    
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Arg1 = Quantidade de threads.\n");
        return 1;
    }

    int n = strtol(argv[1], NULL, 10);

    pthread_t* thread_array = malloc(n * sizeof(pthread_t));

    for (int i = 0; i < n; i++) {
	int * arguments = (int*) malloc(sizeof(int));
	arguments[0] = i;
        pthread_create(&thread_array[i], NULL, calculaPi, (void*)arguments);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(thread_array[i], NULL);
    }

    pi = 4 * pi;
    printf("\nNúmero de threads: %d\nValor de pi: %lf\n", n, pi);
}
