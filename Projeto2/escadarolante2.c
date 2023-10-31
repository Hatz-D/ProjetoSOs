#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
        	fprintf(stderr, "Arg1 = Quantidade de pessoas na escada rolante.\n");
        	return 1;
    }
	int N = strtol(argv[1], NULL, 10);

	srand(time(NULL));

	int* instantes = (int*) malloc(N * sizeof(int));
	int* fluxos = (int*) malloc(N * sizeof(int));
	int* computados = (int*) calloc(N, sizeof(int));
/*	
	for(int i = 0; i < N; i++){
		if(i == 0) {instantes[0] = rand() % 10;}
		else {
			int tempo_aleatorio = rand() % 12;
			if(tempo_aleatorio == 0 || tempo_aleatorio == 10) {tempo_aleatorio++;}
			instantes[i] = instantes[i-1] + tempo_aleatorio;
		}

		fluxos[i] = rand() % 2;

		printf("\n%d %d", instantes[i], fluxos[i]);
	}
*/	

	instantes[0] = 3;
	instantes[1] = 6;
	instantes[2] = 11;
	instantes[3] = 17;
	fluxos[0] = 0;
	fluxos[1] = 1;
	fluxos[2] = 0;
	fluxos[3] = 1;


	int tempo_total = 0;
	int contador = 10;
	int i = 0;
	int j = 1;

	while(i < N) {
		if(computados[i] == 0) {
			if(i == 0) {tempo_total += instantes[i] + 10;}
			else {
				if(fluxos[i] != fluxos[i-1] && tempo_total > instantes[i]) {tempo_total += 10;}
				else {tempo_total = instantes[i] + 10;}
			}
					
			computados[i] = 1;
			contador = 10;
		}

		while(j < N && contador - (instantes[j] - instantes[j-1]) > 0) {
			if(fluxos[i] == fluxos[j] && computados[j] == 0) {
				if(tempo_total > instantes[j] + 10) {tempo_total += 0;}
				else {tempo_total = instantes[j] + 10;}
			
				computados[j] = 1;
				contador = 10;
			}
		
		

			else{contador -= instantes[j] - instantes[j-1];}

			j++;
		}

		i++;
		j = i + 1;
	}

	printf("\n\nTempo final: %d\n", tempo_total);

	return 0;
}
