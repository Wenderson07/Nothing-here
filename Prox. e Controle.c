#include <stdio.h>
#include <stdlib.h>
#define F 8

typedef struct{
	int dept;
}Func;

int main(){
	Func func[F];
	int *prox;
	int controle[2][11];
	int x,i,j,k;
	
	prox = (int *) calloc(F, sizeof(int));
	
	for(i=0;i<F;i++){
		printf("Funcionario %d esta no Departamento: ", i+1);
		scanf("%d", &func[i].dept);
	}
	printf("\n");
	
//Aki, primeiro, verifica-se dentro do vetor func qual o primeiro funcionario seguindo a ordem dos departamentos.
	j = 1; 
	while(j <= 10){
		for(i=0;i<F;i++){
			if(func[i].dept == j){
				x = i;
				controle[1][j] = x;
				break;
			}		
		}
		j++;
	}
	
	for(i=0;i<10;i++){
		printf("Primeiro funcionario alocado no Departamento %d eh: %d\n", i+1,controle[1][i+1]+1);
	}
	
/*Aki, identifica-se, qual o primeiro funcionario do departamento 1 por exemplo, e logo em seguida
inicia-se uma busca pelo o proximo funcionario excluindo-o da proxima procura.*/
	
	printf("\n");
	
	k=0;
	while(k<10){
		x = controle[1][k+1];
		for(j=0;j<F;j++){
			if(j != x){
				if(func[j].dept == k+1){
					prox[x] = j;
					break;
				}
			}
		}
		k++;
	}
	
	for(i=0;i<F;i++){
		if (prox[i] == 0){
			prox[i] = -1;
		}
	}
	
	printf("\n");
	for(i=0;i<4;i++){
		printf("Prox funcionario alocado no mesmo Departamento do Funcionario %d tem o INDICE: %d\n", i+1, prox[i]);
	}
	
	return 0;
}
