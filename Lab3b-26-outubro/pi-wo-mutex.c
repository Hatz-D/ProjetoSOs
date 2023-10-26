#include <stdio.h>
#include <pthread.h>

int pi = 0;

void* calculaPi() {
	
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Arg1 = Quantidade de threads.\n");
        return 1;
    }

    int n = strtol(argv[1], NULL, 10);

    pthread_t* thread_array = malloc(n * sizeof(pthread_t));

    for (int i = 0; i < n; i++) {
        pthread_create(&thread_array[i], NULL, calculaPi, NULL);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(thread_array[i], NULL);
    }
}
