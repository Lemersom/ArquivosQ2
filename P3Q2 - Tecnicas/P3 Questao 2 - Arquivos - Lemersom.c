/*
Aluno: Lemersom Fernandes Filho     RA: 2410176

UTFPR - CP
AS32F - Tecnicas de Programacao - N12A
P3 - Arquivos - Questao 2
*/

#include <stdio.h>
#include <stdlib.h>

int* aloca_vetor(int);
int* realoca_vetor(int*, int, int); //vetor*, n antigo, n novo
int preenche_vetor(int*, int, int); //retorna o inteiro n, que sera a quantidade de numeros no vetor, para nao contar lixo
void gravar_vetor(int*, FILE*, int); //gravar no arquivo


int main(){
	
	FILE *arquivo;
	int n = 10, n1 = 10, *vetor;
	
	vetor = aloca_vetor(n);
	
	n = preenche_vetor(vetor, n, n1); 
	
	gravar_vetor(vetor, arquivo, n);
	
	printf("\n\tPrograma finalizado");
	
	return 0;
}


int preenche_vetor(int *vetor, int n, int n1){
	
	int i = 0, numero;
	
	while(1){
		if(i % 10 == 0){
			vetor = realoca_vetor(vetor, n, n1);
			n = n + 10;
		}
		printf("Digite o %d valor: ", i+1);
		scanf("%d", &numero);
		if(numero == 0){
			n = i; //quantidade de valores gravados para nao escrever lixo no arquivo
			return n;	
		}else{
			vetor[i] = numero; //grava no vetor
		}
		i++;
	}
}

void gravar_vetor(int *vetor, FILE *arquivo, int n){
	
	int i = 0;

	arquivo = fopen("arquivo.txt", "w");
	if(arquivo == NULL){
		printf("Erro, nao foi possivel abrir/criar o arquivo: arquivo.txt");
	}
	else{
		for(i = 0; i < n; i++){
			fprintf(arquivo, "%d\n", vetor[i]);
		}
	}
	
	fclose(arquivo);
}

int *aloca_vetor(int n){
	
	int *vetor;
	
	if(malloc(n * sizeof(int)) == NULL){
		printf("\nNao ha memoria suficiente para alocar o vetor");
		exit(0);
	}
	
	vetor = malloc(n * sizeof(int));
	
	return vetor;
}

int *realoca_vetor(int *vetor, int n, int n1){
	
	if(realloc(vetor, n * sizeof(int)) == NULL){
		printf("\nNao ha memoria suficiente para realocar o vetor");
	}
	
	vetor = realloc(vetor, (n + n1) * sizeof(int));
	
	return vetor;
}
