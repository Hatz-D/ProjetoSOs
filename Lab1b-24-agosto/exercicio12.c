#include <stdio.h>
#include<string.h>

int achar(char string[], char caracter){
	int count = 0;
	while(string[count] != '\0'){
		if(string[count] == caracter){
			return count+1;
		}
	count = count + 1;

	}

	return -1;
}

int main(){
	char string[100];
	strcpy(string, "Paralelepipedo");
	int aux = achar(string, 'l');
	printf("O caractere 'l' se encontra na posição %d da palavra %s\n", aux, string);	
	return 0;
}
