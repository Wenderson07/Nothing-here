#include <stdio.h>
#include <stdlib.h>                        //para uso da função calloc
#define n 49

typedef struct modlista {
	int valor;
    struct modlista *prox;           //ponteiro para o proximo elemento
}*vetor[n], lista, *elo;                 //um vetor de ponteiro para a struct, a estrutura, ponteiro para a struct

void inicializa(vetor v){                       //Inicializa o vetor de ponteiros com os valores 0-49
    elo novo;                                      //ponteiro da struct
    int i;
    for(i=0; i<49; i++){
    	novo  = (elo) calloc(1, sizeof(lista));  //cria um novo nó
        novo->valor = i;                         //armazena o valor i (esse valor será incrementado)
        novo->prox = NULL;                       //faz o novo nó apontar pra NULL
        v[i] = novo;                             //o vetor de ponteiro v recebe o novo nó. Na verdade cada novo nó será uma lista
	}                                          //fim do for
}                                               //fim inicializa

//função para alocar elementos no vetor v
void inserir(vetor v, int a[], int resto, int p){
	elo aux, novo;                           //declaração de ponteiros da struct
    int i=0;

    while(v[i]->valor!=resto){           //para encontrar a posição no vetor de ponteiros "v" que seja igual ao resto
        i++;                                 //incrementa o i
	}
	aux = v[i];                          //aux está apontando para a chave interrompida pelo while
    while(aux->prox!=NULL){              //Vai repetir até encontrar NULL, que seria o final da lista  (inserção no final)
    	aux = aux->prox;                     //aux recebendo o proximo ate NULL
	}
	novo  = (elo) calloc(1, sizeof(lista));       //criando novo elemento
    aux->prox = novo;                             //o ponteiro auxiliar aponta para "novo"
    novo->prox = NULL;                            //novo.prox aponta para nulo
    novo->valor = a[p];                           //armazena o valor que está na posição "p" do vetor "a"
}

//Funçao para imprimir o vetor v
void imprimir(vetor v){
	int i=0;
    elo aux;                                    //aux é do tipo ponteiro da struct
    for(i=0; i<n; i++){                      //i variando de 0 a 49
    	aux=v[i];                               //aponta aux para a posição "i" da lista
        while(aux->prox!=NULL){                 //continua até aux->prox apontar pra NULL
        	printf("\n%d", aux->valor);             //imprime o elemento
            aux=aux->prox;                          //faz aux apontar para o proximo elemento
            while(aux->prox!=NULL){                 //como é um vetor de lista, verifica se possui outro elemento
            	printf("   =>  ");                      //efeito de formatação
                printf("%d", aux->valor);               //imprime o elemento
                aux = aux->prox;                          //aponta aux para o proximo elemento
            }
           printf("   =>  ");                      //efeito de formatação
           printf("%d\n", aux->valor);             //imprime o elemento
        }                                       //FIM while principal
    }                                         //FIM do for
	getchar();
    getchar();                              //para liberar a memória alocada
    free(v);
}//fim  imprimir

void mod(vetor v, int num){
	int a[] = {10,2,3,44,432,35,6576,34,12,54,56,23423,234,23};      //declaração do vetor fixo
    int p=0;                                                         //"p", vai percorrer o vetor "a"
    int resto;                                                       //o resto será armazenado aqui
    for(p=0; p<=13; p++){
    	resto = a[p]%num;               //o resto é a posição no vetor que será inserido a[p]
        inserir (v, a, resto, p);       //chamando a função inserir
	}                             //FIM do for
	imprimir(v);                    //chama a função imprimir passando como argumento "v"
}                                    //FIM mod

int main(){
	vetor v1;                            //v1 do tipo vetor
    inicializa(v1);                      //chama a função inicializa passando v1 como parametro
    int num;                             //a variável que será pedida para o usuário digitar
    printf("Digite um valor inteiro para Num: ");
    scanf("%d", &num);                   //leu num
    mod (v1, num);                       //chama mod passando o vetor e num como parametros
    
    return 0;
}                                    //fim do main
