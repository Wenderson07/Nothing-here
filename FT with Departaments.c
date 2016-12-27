#include <stdio.h>
#include <string.h>
#define F 3

// Pergunta, esse define aqui em cima como variavel global?

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

typedef struct{
	char nome[100];
	int cod;
	int quant; // Contador de funcionarios dentro do departamento
}tDepartamento;

tFuncionario func[F];
int prox[F];
int controle[2][11];
tDepartamento dep[10];

/* Necessario tbm criar um variavel q conte os departamentos ja cadastrados 
Duvidas que permanecem: ordem de onde starta as porra, onde inserir a porra desses
prox e controle, acho tbm q o unico define necessario eh o de funcionario*/

//Tentei atribuir logo o numero de departamento do funcionario dentro do vetor dep

void cadastro(){
	int x;
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
	func[i].dept = x;
	dep[x].cod = x;
	printf("%s foi cadastrado com sucesso\n",func[i].nome);
	printf("\n");
	i++;
	
	printf("%d\n",i);
	printf("\n");
}


void alterar(){
	int resp,fun,cargo,cont;
	char resp2;
	
	printf("Digite o numero do funcionario que deseja alterar: ");
	scanf(" %d", &fun);
	printf("Deseja alterar:\n");
	printf("1 - Nome\n2 - CPF\n3 - Data de Nascimento\n4 - Data de Admissao\n5 - Cargo\n0 - Sair\n");
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
				printf("1 - Nome\n2 - CPF\n3 - Data de Nascimento\n4 - Data de Admissao\n5 - Cargo\n0 - Sair\n");
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

void transferir(){
	printf("O usuario foi transferido\n");
}

void demitir(){
	printf("O funcionario foi demitido\n");
}


/* Mesmo problema da função cadastrar funcionario, sobre o contador, apenas para teste
de execução do programa, coloquei um for, mas acho q o definitivo ñ pode ser assim, pq acho
q o usuario pode escolher se quer criar todos os departamentos de uma vez ou não.E
nao faz muito sentido essa parte do qual o nome do departamento, olha a pg. 13 do trabalho*/

/* Nem eu mesmo to mais conseguindo entender esse code aki, ñ seras surpresa se ñ entenderes,
por isso entra a parte q tu filtras */
void criardep(){ 
	int resp,i=0,cont=0,resp2;
	char nome[100];
	
	printf("Qual o codigo do Departamento? ");
	scanf(" %d", &resp);
	while(resp2!=0){
		for(i=0;i<F;i++){
			if(resp==func[i].dept){
				cont++;
			}
		}
		if(cont>0){
			printf("Departamento %d ja existe!\n", resp);
			printf("0 - Para retornar ao Menu Departamento\n1 - Digitar um novo codigo\n ");
			scanf("%d", &resp2);
			if(resp2==0){
				return;
			}
		}
		printf("Qual o codigo do Departamento?");
		scanf("%d", &resp);
		resp = dep[i].cod;
		printf("Departamento criado com sucesso\n");
		i++;
		printf("0 - Para retornar ao Menu Departamento\n1 - Digitar um novo codigo\n");
		scanf("%d", &resp2);
		if(resp2==1){
			printf("Qual o codigo do Departamento?");
			scanf("%d", &resp);
		}
		else{
			return;
		}
	}
	printf("Qual o nome do Departamento? ");
	scanf(" %s", nome);
	printf("Nome do Departamento %s\n", nome);
}

// Mesma coisa nesse daki de baixo.
void alterardep(){ 
	int resp,i=0,cont=0,resp2;
	char nome[100];
	
	printf("Qual o codigo do Departamento? ");
	scanf(" %d", &resp);
	while(resp2!=0){
		for(i=0;i<F;i++){
			if(resp==dep[i].cod){
				cont++;
			}
		}
		if(cont==0){
			printf("Departamento %d nao existe!\n", resp);
			printf("0 - Para retornar ao Menu Departamento\n1 - Digitar um novo codigo\n");
			scanf("%d", &resp2);
			if(resp2==0){
				return;
			}
		}
		else{
			printf("Departamento existe, e seu nome eh %s\n", dep[i].nome);
			break;
		}
		printf("Qual o codigo do Departamento?");
		scanf("%d", &resp);
		for(i=0;i<F,i++){
			if(resp==dep[i].cod){
				printf("Nome do Departamento: %s\n", dep[i])
			}
		}
		printf("Departamento criado com sucesso\n");
		printf("0 - Para retornar ao Menu Departamento\n1 - Digitar um novo codigo\n");
		scanf("%d", &resp2);
		if(resp2==1){
			printf("Qual o codigo do Departamento?");
			scanf("%d", &resp);
		}
		else{
			return;
		}
	}
	printf("Qual o novo nome do Departamento? ");
	scanf(" %s", nome);
	printf("Novo nome do Departamento %s\n", nome);
}


void menu(){
	int resp;
	printf("===============\n1 - Cadastrar\n2 - Alterar\n3 - Transferir\n4 - Demitir\n5 - Consulta\n0 - Sair\n===============\n");
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
				alterar();
				break;	
   			case 3:
	   			transferir();
	   			break;
	   		case 4:
	   			demitir();
	   			break;
	   		case 5:
	   			consulta();
	   			break;
			default:
				printf("Nop,para de tentar achar bug ai,vlw\n");
				break;
		};
		printf("===============\n1 - Cadastrar\n2 - Alterar\n3 - Transferir\n4 - Demitir\n5 - Consulta\n0 - Sair\n===============\n");
		scanf("%d", &resp);
	}
}


void menudep(){
	int resp;
	printf("===============\n1 - Criar Departamento\n2 - Alterar nome do Departamento\n3 - Consultar Departamento\n4 - Listar Departamentos\n5 - Excluir Departamento\n0 - Sair\n===============\n");
	scanf("%d", &resp);
		while(resp != 0){
			switch(resp){
				case 0:
					printf("Programa finalizado\n");
					break;
				case 1:
					criardep();
					break;
				case 2:
					alterardep();
					break;	
    			case 3:
		   			break;
		   		case 4:
		   			break;
		   		case 5:
		   			break;
				default:
					printf("Nop,para de tentar achar bug ai,vlw\n");
					break;
			};
			printf("===============\n1 - Criar Departamento\n2 - Alterar nome do Departamento\n3 - Consultar Departamento\n4 - Listar Departamentos\n5 - Excluir Departamento\n0 - Sair\n===============\n");
			scanf("%d", &resp);
		}
}

int main(){
	menu();
	printf("\n");
	menudep();
	return 0;
};
