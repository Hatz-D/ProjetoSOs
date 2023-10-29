#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

int tempo = 0;

pthread_mutex_t mutex;

typedef struct {
	int* instantes;
	int* fluxos;
	int i;
} thread_arguments;

void* pessoaNaEscada(void* arguments) {
	thread_arguments* args = (thread_arguments*) arguments;

	int* instantes = (*args).instantes;
	int* fluxos = (*args).fluxos;
	int i = (*args).i;

	if(i == 0) {
		pthread_mutex_lock(&mutex);
		tempo += instantes[0] + 10;
		pthread_mutex_unlock(&mutex);
	}

	else{
		if(fluxos[i] == fluxos[i-1]) {
			pthread_mutex_lock(&mutex);
			tempo += instantes[i] - instantes[i-1];
			pthread_mutex_unlock(&mutex);
		}

		else {
			pthread_mutex_lock(&mutex);
			tempo += instantes[i] - instantes[i-1] > 10 ? instantes[i] - instantes[i-1] : 10 + instantes[i] - instantes[i-1];
			pthread_mutex_unlock(&mutex);

		}
	}

	printf("\n%d %d", instantes[i], fluxos[i]);

}

int main(int argc, char* argv[]) {
	if (argc != 2) {
        	fprintf(stderr, "Arg1 = Quantidade de pessoas na escada rolante.\n");
        	return 1;
    }
	int N = strtol(argv[1], NULL, 10);

	srand(time(NULL));

	int* instantes = (int*) malloc(N * sizeof(int));
	int* fluxos = (int*) malloc(N * sizeof(int));

	for(int i = 0; i < N; i++){
		if(i == 0) {instantes[0] = rand() % 10;}
		else {
			int tempo_aleatorio = rand() % 20;
			instantes[i] = instantes[i-1] + (tempo_aleatorio == 10 || tempo_aleatorio == 0) ? tempo_aleatorio++ : tempo_aleatorio;
		}

		fluxos[i] = rand() % 2;
	}

	pthread_t* thread_array = malloc(N * sizeof(pthread_t));

	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < N; i++) {
                thread_arguments* arguments = (thread_arguments*) malloc(sizeof(thread_arguments));

		(*arguments).instantes = instantes;
		(*arguments).fluxos = fluxos;
		(*arguments).i = i;

		pthread_create(&thread_array[i], NULL, pessoaNaEscada, (void*)arguments);
	}

	for(int i = 0; i < N; i++) {
		pthread_join(thread_array[i], NULL);
	}

	printf("\n\nTempo final: %d\n", tempo);

	return 0;
}
