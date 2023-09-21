#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t mutex;

typedef struct {
    float saldo;
} conta;

void* transferencia(void* arguments) {
    conta** contas = (conta**)arguments;
   
    int fluxo = rand() % 2;
  
    pthread_mutex_lock(&mutex);

    if ((*contas[fluxo]).saldo < ((*contas[2]).saldo)) {
	pthread_mutex_unlock(&mutex);
	return NULL;
    }

    (*contas[fluxo]).saldo -= (*contas[2]).saldo;
    (*contas[abs(fluxo-1)]).saldo += (*contas[2]).saldo;
    (*contas[3 + fluxo]).saldo += 1;

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Arg1 = Quantidade de transações. Arg2 = Valor das transações\n");
        return 1;
    }

    int num = strtol(argv[1], NULL, 10);
    float quantia = strtof(argv[2], NULL);

    conta from, to, quantias, from_to, to_from;
    from.saldo = 100;
    to.saldo = 100;
    quantias.saldo = quantia;
    from_to.saldo = 0;
    to_from.saldo = 0;

    conta ** arguments = (conta**) malloc(5 * sizeof(conta*));
  
    arguments[0] = &from;
    arguments[1] = &to;
    arguments[2] = &quantias;
    arguments[3] = &from_to;
    arguments[4] = &to_from;
   
    srand(time(NULL));

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

    printf("From -> To = %d\n", (int)from_to.saldo);
    printf("To -> From = %d\n\n", (int)to_from.saldo);

    if(from_to.saldo + to_from.saldo != num) {
	    printf("Um total de %d transações de %d falharam devido a falta de saldo!\n\n", (int)(num - from_to.saldo - to_from.saldo), num);
    }

    printf("Conta from: %.2f\n", from.saldo);
    printf("Conta to: %.2f\n", to.saldo);

    pthread_mutex_destroy(&mutex);
    free(thread_array);
    free(arguments);

    return 0;
}
