#include <stdio.h>
#include<string.h>

char* adicionar(char * string, int posicao, char caracter){
	posicao -= 1;
	int count = 0;
	while(string[count] != '\0'){
		count+=1;
	}





	string[posicao] = '\0';;
	return string;
}

int main(){
	char string[100], aux[100];
	strcpy(string, "Paralelepipedo");
	strcpy(aux, "Paralelepipedo");
	char * p = string;
	p = adicionar(p, 5);
	printf("A palavra %s com o caracterere 'a' adicionado na posição 5 é: %s\n", aux, string);	
	return 0;
}
