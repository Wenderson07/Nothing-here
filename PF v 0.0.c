#include <stdio.h>
#include <string.h>
#define F 5
int i=0;
typedef struct{
	int dia,mes,ano;	
}tdata;
//
typedef struct{
	char cpf[12];
	char nome[100];
	tdata dt_adm;
	tdata dt_nasc;
	int cargo;
	int dept;
}tFuncionario;

void cadastro(){
	tFuncionario func[F];
		printf("Digite o nome do usuario: ");
		scanf(" %s", func[i].nome);
		printf("Digite o cpf do usuario: ");
		scanf(" %s", func[i].cpf);
		printf("Digite a data de nascimento(DD MM AA): ");
		scanf("%d %d %d", &func[i].dt_nasc.dia,&func[i].dt_nasc.mes,&func[i].dt_nasc.ano);
		printf("Digite a data de admissao(DD MM AA): ");
		scanf("%d %d %d", &func[i].dt_adm.dia,&func[i].dt_adm.mes,&func[i].dt_adm.ano);
		printf("Digite o numero do cargo: ");
		scanf(" %d", &func[i].cargo);
		printf("Digite o numero do Departamento: ");
		scanf(" %d", &func[i].dept);		
		printf("%s foi cadastrado com sucesso\n",func[i].nome);
		printf("\n");
		i++;
	
}

void demitir(){
	printf("O funcionario foi demitido\n");
}

void transferir(){
	printf("O usuario foi transferido\n");
}

void menu(){
	int resp;
	printf("===============\n1 - Cadastrar\n2 - Demitir\n3 - Transferir\n0 - Sair\n===============\n");
		scanf("%d", &resp);
		while(resp != 0){
			switch(resp){
				case 0:
					printf("Programa finalizado\n");
					break;
				case 1:
					cadastro();
					break;
				case 2:
					demitir();
					break;	
    			case 3:
		   			transferir();
		   			break;
				default:
					printf("Nop,para de tentar achar bug ai,vlw\n");
					break;
			};
			printf("===============\n1 - Cadastrar\n2 - Demitir\n3 - Transferir\n0 - Sair\n===============\n");
			scanf("%d", &resp);
		}
}

int main(){
	menu();
};
