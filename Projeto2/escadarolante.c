#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

int tempo = 0;

pthread_mutex_t mutex;

void* pessoaNaEscada(void* arguments) {
	int** args = (int**) arguments;

	int* instantes = args[0];
	int* fluxos = args[1];
	int N = *args[2];
	int i = *args[3];

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

	int ** arguments = (int**) malloc(4 * sizeof(int*));

	arguments[0] = malloc(N * sizeof(int));
	arguments[1] = malloc(N * sizeof(int));
	arguments[2] = malloc(sizeof(int));
	*arguments[2] = N;

	for(int i = 0; i < N; i++){
		if(i == 0) {arguments[0][0] = rand() % 10;}
		else {
			int tempo_aleatorio = rand() % 20;
			arguments[0][i] = (tempo == 10 ? tempo_aleatorio++ : tempo_aleatorio) + arguments[0][i-1];
		}

		arguments[1][i] = rand() % 2;;
	}

	pthread_t* thread_array = malloc(N * sizeof(pthread_t));

	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < N; i++) {
                arguments[3] = malloc(sizeof(int));
                *arguments[3] = i;

		pthread_create(&thread_array[i], NULL, pessoaNaEscada, (void*)arguments);
	}

	for(int i = 0; i < N; i++) {
		pthread_join(thread_array[i], NULL);
	}

	printf("\n\nTempo final: %d\n", tempo);

	return 0;
}
