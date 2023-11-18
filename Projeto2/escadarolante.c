#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    int instante; // Instante em que a pessoa chegou à escada
    int fluxo;    // Direção do fluxo da pessoa 
} Pessoa;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Arg1 = Entrada manual, pseudoaleatória ou por arquivo\n");
        return 1;
    }

    int N;
    Pessoa* pessoas;
    int opcao = strtol(argv[1], NULL, 10);

    // Caso as pessoas sejam adicionadas por arquivo de testes
    if(opcao == 2) {
	char nomeArquivo[50];
	printf("\nDigite o nome do arquivo de teste: ");
	scanf("%s", nomeArquivo);

    	FILE *input_file = fopen(nomeArquivo, "r"); // Abertura do arquivo

    	if(input_file == NULL) { // Checa se o arquivo foi aberto com sucesso
        	printf("\nErro ao ler o arquivo!\n");
        	return 1;
    	}

	fscanf(input_file, "%d", &N);

	// Alocando dinamicamente um array de estruturas Pessoa
   	pessoas = (Pessoa*)malloc(N * sizeof(Pessoa));

	for(int i = 0; i < N; i++) {
		fscanf(input_file, "%d %d", &pessoas[i].instante, &pessoas[i].fluxo);	
	}

	 // Fechando o arquivo
    	fclose(input_file);
    }

    else{
	printf("\nDigite a quantidade de pessoas na escada rolante: ");
	scanf("%d", &N);

	// Alocando dinamicamente um array de estruturas Pessoa
    	pessoas = (Pessoa*)malloc(N * sizeof(Pessoa));

	// Caso as pessoas sejam adicionadas manualmente
    	if(opcao == 0) {
        	printf("Informe os dados para cada pessoa (instante fluxo):\n");

        	for (int i = 0; i < N; i++) {
               		scanf("%d %d", &pessoas[i].instante, &pessoas[i].fluxo);
        	}
   	 }	

   	 // Caso as pessoas sejam adicionadas automaticamente
   	 else {
       		 srand(time(NULL));

       		 for(int i = 0; i < N; i++){
               		 if(i == 0) {pessoas[0].instante = rand() % 10;}
               		 else {
                       		 int tempo_aleatorio = rand() % 12;
                        	if(tempo_aleatorio == 0 || tempo_aleatorio == 10) {tempo_aleatorio++;}
                        		pessoas[i].instante = pessoas[i-1].instante + tempo_aleatorio;
                        		int k = i - 1;

                        		while(pessoas[k].instante + 10 >= pessoas[i].instante && k >= 0) {
                                		if(pessoas[k].instante + 10 == pessoas[i].instante) {
                                        		pessoas[i].instante += 1;
                                        		break;
                                		}

                                		else{k--;}
                        		}
                	}

                	pessoas[i].fluxo = rand() % 2;

                	printf("\n%d %d", pessoas[i].instante, pessoas[i].fluxo);
        	}
    	}
    
    }

    int tempo_total = 0;
    int contador = 10;  

    for (int i = 0; i < N; i++) {
        if (pessoas[i].instante != -1) {
		tempo_total = (i == 0) ? pessoas[i].instante + 10 : (tempo_total > pessoas[i].instante) ? tempo_total + 10 : pessoas[i].instante + 10;
        	contador = 10;	
		pessoas[i].instante = -1;
	}

        for (int j = i + 1; j < N; j++) {
            // Verificando se há espaço suficiente entre as pessoas ou se o tempo total é maior que o instante da próxima pessoa
            if (contador - (pessoas[j].instante - pessoas[j - 1].instante) > 0 || tempo_total > pessoas[j].instante) {
                // Verificando se as pessoas têm o mesmo fluxo (direção)
                if (pessoas[i].fluxo == pessoas[j].fluxo && pessoas[j].instante != -1) {
                    tempo_total = (tempo_total > pessoas[j].instante + 10) ? tempo_total : (tempo_total > pessoas[j].instante) ? pessoas[j].instante + 10 : tempo_total + 10;
                    contador = 10; 
                    pessoas[j].instante = -1;
                } 

		else {
                    contador -= pessoas[j].instante - pessoas[j - 1].instante; // Reduzindo o contador com base no tempo entre as pessoas
                }
            } 
	    else {break;}
        }
    }

  
    printf("\n\nTempo final: %d\n", tempo_total);

    // Liberando a memória alocada para o array de pessoas
    free(pessoas);

    return 0;
}
