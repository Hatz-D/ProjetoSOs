#include <stdio.h>
#include<string.h>

char* remover(char * string, int posicao){
	posicao -= 1;
	string[posicao] = '\0';
	while(string[posicao+1] != '\0'){
		string[posicao] = string[posicao+1];
		posicao+=1;
	}

	string[posicao] = '\0';;
	return string;
}

int main(){
	char string[100], aux[100];
	strcpy(string, "Paralelepipedo");
	strcpy(aux, "Paralelepipedo");
	char * p = string;
	p = remover(p, 5);
	printf("A palavra %s com o caracterere na posição 5 removido é: %s\n", aux, string);	
	return 0;
}
