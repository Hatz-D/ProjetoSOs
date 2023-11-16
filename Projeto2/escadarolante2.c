#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int instante; // Instante em que a pessoa chegou à escada
    int fluxo;    // Direção do fluxo da pessoa 
} Pessoa;

int main() {
    int N; 

    printf("Quantidade de pessoas na escada rolante: ");
    scanf("%d", &N);

    // Alocando dinamicamente um array de estruturas Pessoa
    Pessoa* pessoas = (Pessoa*)malloc(N * sizeof(Pessoa));

    
    printf("Informe os dados para cada pessoa (instante fluxo):\n");

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pessoas[i].instante, &pessoas[i].fluxo);
    }

    int tempo_total = 0;
    int contador = 10;  

    for (int i = 0; i < N; i++) {
        if (pessoas[i].instante == -1) continue;

        tempo_total = (i == 0) ? pessoas[i].instante + 10 : (tempo_total > pessoas[i].instante) ? tempo_total + 10 : pessoas[i].instante + 10;
        contador = 10; 

        for (int j = i + 1; j < N; j++) {
            if (pessoas[j].instante == -1) continue;

            // Verificando se há espaço suficiente entre as pessoas ou se o tempo total é maior que o instante da próxima pessoa
            if (contador - (pessoas[j].instante - pessoas[j - 1].instante) > 0 || tempo_total > pessoas[j].instante) {
                // Verificando se as pessoas têm o mesmo fluxo (direção)
                if (pessoas[i].fluxo == pessoas[j].fluxo) {
                    tempo_total = (tempo_total > pessoas[j].instante + 10) ? tempo_total : (tempo_total > pessoas[j].instante) ? pessoas[j].instante + 10 : tempo_total + 10;
                    contador = 10; 
                    pessoas[j].instante = -1; 
                } else {
                    contador -= pessoas[j].instante - pessoas[j - 1].instante; // Reduzindo o contador com base no tempo entre as pessoas
                }
            } else {
                break; 
            }
        }
    }

  
    printf("\n\nTempo final: %d\n", tempo_total);

    // Liberando a memória alocada para o array de pessoas
    free(pessoas);

    return 0;
}
