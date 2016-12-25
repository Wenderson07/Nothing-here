#include <stdio.h>
#include <string.h>
#define F 3

int i=0;

typedef struct{
	int dia,mes,ano;	
}tdata;

typedef struct{
	char cpf[12];
	char nome[100];
	tdata dt_adm;
	tdata dt_nasc;
	int cargo;
	int dept;
}tFuncionario;

tFuncionario func[F];
	
void cadastro(){
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
		printf("%d\n",i);
}


void alterar(){
	int resp,fun,cargo,cont;
	char resp2;
	
	printf("Digite o numero do funcionario que deseja alterar: ");
	scanf(" %d", &fun);
	printf("Deseja alterar:\n");
	printf("1 - Nome\n2 - CPF\n3 - Data de Nascimento\n4 - Data de Admissao\n5 - Cargo\n");
	scanf(" %d", &resp);
	
	while(resp != 0){
		while((resp2 != 's') || (resp2 != 'S')){
			switch(resp){
				case 1:
				   	printf("Antigo NOME: %s\n", func[fun].nome);
				   	printf("Digite o novo nome: ");
				   	scanf(" %s", func[fun].nome);
				   	printf("Novo NOME: %s\n", func[fun].nome);
				   	break;
				case 2:
				   	printf("Antigo CPF: %s\n", func[fun].cpf);
				   	printf("Digite o novo CPF: ");
					scanf(" %s", func[fun].cpf);
				   	printf("Novo CPF: %s\n", func[fun].cpf);
				   	break;
				case 3:
					printf("Antiga Data de Nascimento: %d %d %d\n", func[fun].dt_nasc.dia,func[fun].dt_nasc.mes,func[fun].dt_nasc.ano);
					printf("Digite a nova data(DD MM AA): ");
					scanf("%d %d %d", &func[fun].dt_nasc.dia,&func[fun].dt_nasc.mes,&func[fun].dt_nasc.ano);
					printf("Nova Data de Nascimento: %d %d %d\n", func[fun].dt_nasc.dia,func[fun].dt_nasc.mes,func[fun].dt_nasc.ano);
					break;
				case 4:
					printf("Antiga Data de Admissao: %d %d %d\n", func[fun].dt_adm.dia,func[fun].dt_adm.mes,func[fun].dt_adm.ano);
					printf("Digite a nova data(DD MM AA): ");
					scanf("%d %d %d", &func[fun].dt_adm.dia,&func[fun].dt_adm.mes,&func[fun].dt_adm.ano);
					printf("Nova Data de Admissao: %d %d %d\n", func[fun].dt_adm.dia,func[fun].dt_adm.mes,func[fun].dt_adm.ano);
					break;  
				case 5:
				   	printf("Antigo Cargo: %d\n", func[fun].cargo);
				   	printf("Digite o novo cargo: ");
				   	scanf(" %d", &cargo);
				   	func[fun].cargo = cargo;
				   	printf("Novo Cargo: %d\n", func[fun].cargo);
				   	break;
				default:
				   	printf("Try again\n");
				   	break;
		  	}
		  	printf("Deseja continuar alterando os dados desse funcionario(s - sim, n - nao): ");
        	scanf(" %c", &resp2);
        	if((resp2 == 'S') || (resp2 == 's')){
				printf("1 - Nome\n2 - CPF\n3 - Data de Nascimento\n4 - Data de Admissao\n5 - Cargo\n");
	    		scanf(" %d", &resp);
			}
			else{
				cont = 1;
			}
			if(cont==1){
				break;
			}
		}
		printf("Digite o numero do funcionario que deseja alterar(para sair digite um numero negativo): ");
		scanf(" %d", &fun);
		if(fun < 0){
			break;
		}
		printf("Deseja alterar:\n");
		printf("1 - Nome\n2 - CPF\n5 - Cargo\n0 - Sair\n");
		scanf(" %d", &resp);
	}
}


void consulta(){
	char cpf[12];
	int a, j;
	printf("Digite o cpf do funcionario: ");
	scanf(" %s", cpf);
	for(j=0;j<=i;j++){
		a = strcmp(cpf,func[j].cpf);
		if (a==0)
			printf("Nome do funcionario: %s\n",func[j].nome);
	}
}


void demitir(){
	printf("O funcionario foi demitido\n");
}


void transferir(){
	printf("O usuario foi transferido\n");
}


void menu(){
	int resp;
	printf("===============\n1 - Cadastrar\n2 - Demitir\n3 - Transferir\n4 - Alterar\n5 - Consulta\n0 - Sair\n===============\n");
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
		   		case 4:
		   			alterar();
		   			break;
		   		case 5:
		   			consulta();
		   			break;
				default:
					printf("Nop,para de tentar achar bug ai,vlw\n");
					break;
			};
			printf("===============\n1 - Cadastrar\n2 - Demitir\n3 - Transferir\n4 - Alterar\n5 - Consulta\n0 - Sair\n===============\n");
			scanf("%d", &resp);
		}
}

int main(){
	menu();
	return 0;
};
