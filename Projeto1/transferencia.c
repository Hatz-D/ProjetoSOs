#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX 100

pthread_mutex_t mutex;

typedef struct {
    float saldo;
} conta;

void* transferencia(void* arguments) {
    conta** contas = (conta**)arguments;
    pthread_mutex_lock(&mutex);

    if ((*contas[0]).saldo < (*contas[2]).saldo) {
	pthread_mutex_unlock(&mutex);
	return NULL;
    }

    (*contas[0]).saldo -= (*contas[2]).saldo;
    (*contas[1]).saldo += (*contas[2]).saldo;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 4 || strtol(argv[1], NULL, 10) > MAX || (strtol(argv[3], NULL, 10) != 0 && strtol(argv[3], NULL, 10) != 1)) {
        fprintf(stderr, "Arg1 = Quantidade de transações. Arg2 = Valor das transações. Arg3 = 0 ou 1\n");
        return 1;
    }

    int num = strtol(argv[1], NULL, 10);
    float quantia = strtof(argv[2], NULL);
    int opcao = strtol(argv[3], NULL, 10);

    conta from, to, quantias;
    from.saldo = 100;
    to.saldo = 100;
    quantias.saldo = quantia;

    conta ** arguments = (conta**) malloc(argc * sizeof(conta*));
    arguments[opcao] = &from;
    arguments[abs(opcao - 1)] = &to;
    arguments[2] = &quantias;

    pthread_t* thread_array = malloc(num * sizeof(pthread_t));
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("O mutex falhou!");
        return 1;
    }

    for (int i = 0; i < num; i++) {
        pthread_create(&thread_array[i], NULL, transferencia, (void*)arguments);
    }

    for (int i = 0; i < num; i++) {
        pthread_join(thread_array[i], NULL);
    }

    printf("Conta from: %.2f\n", from.saldo);
    printf("Conta to: %.2f\n", to.saldo);

    pthread_mutex_destroy(&mutex);
    free(thread_array);

    return 0;
}
