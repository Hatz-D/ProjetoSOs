#include <stdio.h>

struct pessoa {
	char nome[50];
	int idade;
	float peso;
	float altura;
};

int main(){

	struct pessoa pessoas[3] = {
		{"Junior", 20, 70.0, 1.75},
		{"Marcia", 60, 130.0, 1.60},
		{"Carlos", 15, 80.3, 1.90}};

	printf("******Dados das pessoas******\n");
	for (int i = 0; i < 3; i++) {
		printf("\nPessoa %d: ", i+1);
		printf("\nNome: %s\nIdade: %d\nPeso: %.2f\nAltura: %.2f\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].peso, pessoas[i].altura);
	}
	return 0;
}
