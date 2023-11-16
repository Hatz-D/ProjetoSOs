#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int instante;
    int fluxo;
} Pessoa;

int main() {
    int N;

    printf("Quantidade de pessoas na escada rolante: ");
    scanf("%d", &N);

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

            if (contador - (pessoas[j].instante - pessoas[j - 1].instante) > 0 || tempo_total > pessoas[j].instante) {
                if (pessoas[i].fluxo == pessoas[j].fluxo) {
                    tempo_total = (tempo_total > pessoas[j].instante + 10) ? tempo_total : (tempo_total > pessoas[j].instante) ? pessoas[j].instante + 10 : tempo_total + 10;
                    contador = 10;
                    pessoas[j].instante = -1;
                } else {
                    contador -= pessoas[j].instante - pessoas[j - 1].instante;
                }
            } else {
                break;
            }
        }
    }

    printf("\n\nTempo final: %d\n", tempo_total);

    free(pessoas);

    return 0;
}
