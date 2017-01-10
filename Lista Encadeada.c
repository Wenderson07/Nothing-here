#include <stdio.h>
#include <stdlib.h>

//Vai ser mais ou menos desse jeito aki as partes de prox. e controle la do trabalho, mas so q com vetores.

struct Tipo_Lista{
	int cod;
	struct Tipo_Lista *prox;
};

struct Tipo_Lista *first;
struct Tipo_Lista *last;

void FlVazia(){
	struct Tipo_Lista *aux;
	aux = (struct Tipo_Lista *)malloc(sizeof(struct Tipo_Lista));
	first = aux;
	last = first;
}

void Insere(int x){
	struct Tipo_Lista *aux;
	aux = (struct Tipo_Lista *)malloc(sizeof(struct Tipo_Lista));
	aux->cod = x;
	last->prox = aux;
	last = last->prox;
	aux->prox = NULL;	
}

void Imprime(){
	struct Tipo_Lista *aux;
	aux = first->prox;
	while(aux!=NULL){
		printf("Item = %d\n", aux->cod);
		aux = aux->prox;
	}
}

void Pesquisa(int x){
	struct Tipo_Lista *aux;
	int flag = 0;
	aux = first->prox;
	while(aux != NULL){
		if(aux->cod==x){
			printf("Achou Item %d\n", x);
			flag = 1;
			aux = NULL;
		}
		else{
			aux = aux->prox;
		}
	}
	if(flag==0)
		printf("Item %d nao se encontra nesta Lista!!!\n", x);		
}

void Remove(int x){
	struct Tipo_Lista *aux;
	struct Tipo_Lista *sentinela;	
	int flag = 0;
	aux = first->prox;
	sentinela = first;
	while(aux != NULL){
		if(aux->cod==x){
			printf("Removeu o Item %d\n", x);
			sentinela->prox = aux->prox;
			flag = 1;
			aux = NULL;
		}
		else{
			aux = aux->prox;
			sentinela = sentinela->prox;
		}
	}
	if(flag==0)
		printf("Item %d nao se encontra nesta Lista!!!\n", x);		
}

int main(){
	char op = '2';
	int codigo;
	FlVazia();
	while(op!='0'){
		printf("Entre com o codigo: ");
		scanf("%d", &codigo);
		Insere(codigo);
		printf("Continuar com o Cadastro? 1 - Sim, 0 - Nao: \n");
		op = getch();
	}
	Imprime();
	printf("\n\nEntre com um item para pesquisar: ");
	scanf("%d", &codigo);
	Pesquisa(codigo);
	printf("\n");
	printf("Item a ser removido: ");
	scanf("%d", &codigo);
	Remove(codigo);
	Imprime();
	
	return 0;
}
