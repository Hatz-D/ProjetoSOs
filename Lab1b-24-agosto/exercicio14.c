#include <stdio.h>
#include<string.h>

char* adicionar(char * string, int posicao, char caracter){
	posicao -= 1;
	int count = 0;

	while(string[count] != '\0'){
		count+=1;
	}

	for(int i = count; i >= posicao; i--){
		string[i+1] = string[i];
	}


	string[posicao] = caracter;
	return string;
}

int main(){
	char string[100], aux[100];
	strcpy(string, "Paralelepipedo");
	strcpy(aux, "Paralelepipedo");
	char * p = string;
	p = adicionar(p, 5, 'Z');
	printf("A palavra %s com o caracterere 'Z' adicionado na posição 5 é: %s\n", aux, string);	
	return 0;
}
