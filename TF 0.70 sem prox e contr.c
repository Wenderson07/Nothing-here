#include <stdio.h>
#include <string.h>
#define F 4
#include <locale.h>
int i =0;
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
	int quant;
}tDepartamento;

tFuncionario func[F];
int prox[F];
int controle[2][11];
tDepartamento dep[10];

void coments_A(){
/* Necessario tbm criar uma variavel q conte os departamentos ja cadastrados 
Duvidas que permanecem: ordem de onde starta as porra, onde inserir a porra desses
prox e controle, acho tbm q o unico define necessario eh o de funcionario.*/

/* Aparenta-se tbm q primeiro ira ser feito registro dos departamentos para depois
vir a dos funcionarios. */

/* No momento, O CODIGO DO DEPARTAMENTO ESTA SENDO IGUAL AO NUMERO CORRESPONDENTE DE 
DEPARTAMENTO, CODIGO 1 == DEPARTAMENTO 1, NUM SEI SE É PRA FICAR ASSIM, MAS NO MOMENTO
ESTA.*/

/*
Objetivo: Verificar se uma data eh valida.
Parâmetros: dia, mes, ano.
Retorno: 1 se for data valida, 0 se não. 
*/
//NO FINAL, AJEITAR O ANO.
}
int ValidarData(int dia,int mes,int ano){	
	if((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 00 && ano <= 99)){
		if(ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)){ 
			if(dia == 29 && mes == 2){
				return 1;
			}
		}
        if(dia <= 28 && mes == 2){
        	return 1;
		}
		if(dia >= 30 && mes == 2){
			return 0;
		}
        if((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
            return 1;
		} 
        if((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)){
            return 1;
		}
        else{
        	return 0;
		}
    }
    else{
    	return 0;
	}
}

//PARTE DOS DEPARTAMENTOS

//Objetivo: Criar Departamento.
//AJEITAR NO FINAL: os prints do final.
void criardep(){ 
	int cod,i,cont=0,x,resp; 

	while(resp!=0){
		printf("Digite o código do departamento: ");
		scanf(" %d", &cod);
		for(i=0;i<10;i++){
		    if(cod == dep[i].cod){
				cont++;
			}
		}
		if(cont>0){
			printf("Departamento %d já existe!\n", cod);
			cont=0;
			printf("---------------\n0 - Para retornar ao Menu Departamento\n1 - Digitar um novo código\n---------------\n");
			scanf("%d", &resp);
			if(resp==0)
				return;
		}
		else{
			x = cod-1;
			dep[x].cod = cod;
			printf("Digite o nome do departamento: ");
			scanf(" %s", dep[x].nome);
			printf("Departamento de código %d e Nome %s criado com sucesso\n", dep[x].cod,dep[x].nome);
			printf("---------------\n0 - Para retornar ao Menu Departamento\n1 - Digitar um novo código\n---------------\n");
			scanf("%d", &resp);
			if(resp==0)
				return;
		}			
	}
}

//Objetivo: Alterar informaçoes do Departamento.
//AJEITAR NO FINAL: os prints do final.
void alterardep(){ 
	int resp,i,cont=0,resp2;
	while(resp2!=0){
		printf("Digite o código do departamento ");
		scanf(" %d", &resp);
		for(i=0;i<10;i++){
			if(resp == dep[i].cod){
				cont++;
			}
		}
		if(cont==0){
			printf("Departamento %d não existe!\n", resp);
			printf("---------------\n0 - Para retornar ao Menu Departamento\n1 - Digitar um novo código\n---------------\n");
			scanf("%d", &resp2);
			if(resp2==0)
				return;
		}
		else{
			printf("Nome atual do departamento %d: %s\n", resp,dep[resp-1].nome);
			printf("Digite o novo nome do departamento: ");
			scanf(" %s", dep[resp-1].nome);
			printf("Nome do departamento alterado com sucesso\n", dep[resp-1].cod,dep[resp-1].nome);
			return;
		}
	}
}

//Objetivo: Consultar Departamento.
void consultardep(){
	int resp,cont=0,i;
	printf("Qual o código do departamento? ");
	scanf(" %d", &resp);
	for(i=0;i<F;i++){
		if(resp == dep[i].cod){
			cont++;
		}
	}
	if(cont==0){
		printf("Departamento %d não existe!\n", resp);
		return;
	}
	else{
		printf("Nome do departamento %d: %s\n", resp,dep[resp-1].nome);
		printf("Quantidade de funcionários dentro do departamento: %d\n", dep[resp-1].quant);
	}
}

//Objetivo: Listar as informaçoes dos Departamentos criados.
void listardep(){
	int j,cont=0;
	for(j=0;j<10;j++){
		if(dep[j].cod==0){
			cont++;
			if(cont==10){
				printf("Não há departamentos cadastrados.\n");
			}
		}
		else{
			printf("Departamento %d - código: %d\n", j+1,dep[j].cod);
			printf("Departamento %d - nome: %s\n", j+1,dep[j].nome);
			printf("Departamento %d - quantidade de funcionários: %d\n", j+1,dep[j].quant);
			printf("\n");
		}
	}
}

//Objetivo: Excluir Departamentos.
//Nessa funçao de excluir provavelmente usasse ponteiro.
/*AINDA PRECISA-SE AJEITAR , QUANDO EXCLUI UM DEPARTAMENTO, EM VEZ DO SUCESSOR TOMAR O LUGAR
DO EXCLUIDO ELE APENAS SE COPIA PARA ESSA POSIÇAO.*/
void excluirdep(){
	int resp,cod,j,cont,x,y,sentinela;
	char resp2;
	
	while(resp!=2){
		printf("Qual o código do departamento?: ");
		scanf(" %d", &cod);
		for(j=0;j<10;j++){
			if(dep[j].cod == cod){
				cont++;
				x = j;
			}
		}
		if(cont==0){
			printf("Departamento %d não existe!\n", cod);
			printf("---------------\n0 - Para retornar ao Menu Departamento\n1 - Digitar um novo código\n---------------\n");
			scanf("%d", &resp);
			if(resp==0)
				return;
		}
		else{
			printf("Departamento %d - Nome: %s\n               - Quantidade de Funcionarios: %d\n",x+1,dep[x].nome,dep[x].quant);
			if(dep[x].quant!=0){
				printf("Há funcionário(s) lotado(s) no Departamento %d.Não é possível excluir o departamento!\n", dep[x].cod);
				printf("---------------\n0 - Para retornar ao Menu Departamento\n1 - Digitar um novo código\n---------------\n");
				scanf("%d", &resp);
				if(resp==0)
					return;
			}
			break;
		}
	}
	while((resp2!='s') || (resp2!='n')){
		printf("Deseja realmente excluir o departamento? <s/n>: ");
		scanf(" %c", &resp2);
		if(resp2=='n'){
			printf("Departamento não excluido!\n");
			return;
		}
		if(resp2=='s'){
			for(j=0;j<10;j++){
				if(dep[j].cod != 0){
					y = j-1;
				}
			}
			sentinela = dep[y].cod;
			printf("%d\n", sentinela);
			j = 0;
			while(dep[j].cod != sentinela){
				if(dep[j].cod == cod){
					dep[j].cod=dep[j+1].cod;
					strcpy(dep[j].nome,dep[j+1].nome);
					dep[j].quant=dep[j+1].quant;
					if(dep[j].cod != sentinela){
						dep[j+1].cod=dep[x].cod;
						strcpy(dep[j+1].nome,dep[x].nome);
						dep[j+1].quant=dep[x].quant;
					}
				}
				j++;
			}
			dep[10-1].cod=0;
			strcpy(dep[10-1].nome,"");
			dep[10-1].quant=0;
			printf("Departamento excluido com sucesso!\n");
			break;
		}
	}
}


//PARTE DOS FUNCIONARIOS

//Objetivo: Cadastrar um novo funcionario.
void cadastrar(){
	char cpf[12];
	int a,j,x,y,z,resp=0,cont=1,cont2=0,resp2;
	
	while(resp!=2){
		printf("Digite o CPF: ");
   		scanf(" %s", cpf);
		for(j=0;j<F;j++){
			a = strcmp(cpf,func[j].cpf);
			if(a==0){
				cont = 0;
			}
		}
		if(cont==0){
			printf("CPF %s já cadastrado!\n", cpf);
			cont = 1;
			printf("---------------\n0 - Voltar ao Menu Funcionario\n1 - Digitar um novo cpf\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			strcpy(func[i].cpf,cpf);
			resp = 2;
		}
	}
	printf("Digite o nome: ");
	scanf(" %s", func[i].nome);
	printf("Digite a data de nascimento?: ");
	scanf("%d %d %d", &func[i].dt_nasc.dia,&func[i].dt_nasc.mes,&func[i].dt_nasc.ano);
	x = ValidarData(func[i].dt_nasc.dia,func[i].dt_nasc.mes,func[i].dt_nasc.ano);
	while(x==0){
		if(x==0){
			printf("Data Inválida! Digite novamente: ");
			scanf("%d %d %d", &func[i].dt_nasc.dia,&func[i].dt_nasc.mes,&func[i].dt_nasc.ano);
			x = ValidarData(func[i].dt_nasc.dia,func[i].dt_nasc.mes,func[i].dt_nasc.ano);
		}
		else{
			break;
		}
	}
	printf("Digite data de admissão na empresa?: ");
	scanf("%d %d %d", &func[i].dt_adm.dia,&func[i].dt_adm.mes,&func[i].dt_adm.ano);
	y = ValidarData(func[i].dt_adm.dia,func[i].dt_adm.mes,func[i].dt_adm.ano);
	while(y==0){
		if(y==0){
			printf("Data Inválida! Digite novamente: ");
			scanf("%d %d %d", &func[i].dt_adm.dia,&func[i].dt_adm.mes,&func[i].dt_adm.ano);
			y = ValidarData(func[i].dt_adm.dia,func[i].dt_adm.mes,func[i].dt_adm.ano);
		}
		else{
			break;
		}
	}
	printf("Digite o cargo: ");
	scanf(" %d", &func[i].cargo);
	while(resp2!=0){
		printf("Digite o departamento?: ");
	   	scanf(" %d", &func[i].dept);
	   	cont2 = 0;
		for(j=0;j<10;j++){
			if(dep[j].cod == func[i].dept){
				cont2++;
			}
		}
		if(cont2 == 0){
			printf("Departamento %d não existe!\n", func[i].dept);
			printf("Código e Nome dos Departamentos que existem: \n");
			for(j=0;j<10;j++){
				printf("Código: %d, Nome: %s\n", dep[j].cod,dep[j].nome);
			}
			printf("---------------\n0 - Para retornar ao Menu Funcionario\n1 - Digitar um novo código\n---------------\n");
			scanf(" %d", &resp2);
			if(resp2==0)
				return;
		}	   	
		else{
			z = func[i].dept - 1;
			dep[z].quant++;
			break;
		}	   
	}
	printf("Funcionário cadastrado com sucesso!\n");
	i++;
}

//Objetivo: Alterar informaçoes de um funcionario.
void alterar(){ 
	char cpf[12],cpf2[12];
	int j,a,cont=0,x,resp,resp2,resp3,cont2,b,c;
	
	// Se a == 0, entao cpf == func[j].cpf
	while(resp!=2){
		printf("Digite o CPF do funcionario?: ");
   		scanf(" %s", cpf);
		for(j=0;j<F;j++){
			a = strcmp(func[j].cpf,cpf);
			if(a==0){
				cont++;
				x = j;
			}
		}
		if(cont==0){
			printf("CPF %s não cadastrado!\n", cpf);
			printf("---------------\n0 - Voltar ao Menu Funcionario\n1 - Digitar um novo CPF\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			printf("MENU ALTERAR FUNCIONARIO(CPF: %s)\n", cpf);
			printf("1 - CPF\n2 - Nome\n3 - Data de Nascimento\n4 - Data de Admissão na empresa\n5 - Cargo\n0 - Sair\n");
			scanf(" %d", &resp2);
			
			while(resp2!=0){
				switch(resp2){
					case 0:
						break;
					case 1:
						while(resp3!=2){
							//vvvvvv EXCLUIR NO FINAL.
							printf("Antigo CPF: %s\n", func[x].cpf);
				   			printf("Digite o novo cpf?: ");
				   			scanf(" %s", cpf2);
							for(j=0;j<F;j++){
								a = strcmp(func[j].cpf,cpf2);
								if(a==0){
									cont2=0;
								}
							}
							if(cont2==0){
								printf("CPF %s já cadastrado!\n", cpf2);
								printf("---------------\n0 - Voltar ao Menu Alterar Funcionario\n1 - Digitar um novo cpf\n---------------\n");
								scanf(" %d", &resp3);
								if(resp3==0)
									break;
							}
							else{
								strcpy(func[x].cpf,cpf2);
								printf("CPF alterado com sucesso!\n");			   		
				   				break;
							}		   			
					   	}
					   	break;
					case 2:
						//vvvvvv EXCLUIR NO FINAL.
						printf("Antigo NOME: %s\n", func[x].nome);
				   		printf("Digite o novo nome?: ");
				   		scanf(" %s", func[x].nome);
				   		printf("Nome alterado com sucesso!\n");
						printf("Novo NOME: %s\n", func[x].nome); // EXCLUIR NO FINAL.
				   		break;
					case 3:
						//vvvvvv EXCLUIR NO FINAL.
						printf("Antiga Data de Nascimento: %d %d %d\n", func[x].dt_nasc.dia,func[x].dt_nasc.mes,func[x].dt_nasc.ano);
						printf("Digite o novo ano de nascimento?(DD MM AA): ");
						scanf("%d %d %d", &func[x].dt_nasc.dia,&func[x].dt_nasc.mes,&func[x].dt_nasc.ano);
						b = ValidarData(func[x].dt_nasc.dia,func[x].dt_nasc.mes,func[x].dt_nasc.ano);	
						while(b==0){
							if(b==0){
								printf("Data Inválida! Digite novamente: ");
								scanf("%d %d %d", &func[x].dt_nasc.dia,&func[x].dt_nasc.mes,&func[x].dt_nasc.ano);
								b = ValidarData(func[x].dt_nasc.dia,func[x].dt_nasc.mes,func[x].dt_nasc.ano);
							}
							else{
								break;
							}
						}
						printf("Data de nascimento alterada com sucesso!\n");
						printf("Nova data de Nascimento: %d %d %d\n", func[x].dt_nasc.dia,func[x].dt_nasc.mes,func[x].dt_nasc.ano);
						//^^^^^^ EXCLUIR NO FINAL.
						break;
					case 4:
						//vvvvvv EXCLUIR NO FINAL.
						printf("Antiga Data de Admissão: %d %d %d\n", func[x].dt_adm.dia,func[x].dt_adm.mes,func[x].dt_adm.ano);
						printf("Digite a nova data(DD MM AA): ");
						scanf("%d %d %d", &func[x].dt_adm.dia,&func[x].dt_adm.mes,&func[x].dt_adm.ano);
						c = ValidarData(func[x].dt_adm.dia,func[x].dt_adm.mes,func[x].dt_adm.ano);
						while(c==0){
							if(c==0){
								printf("Data Inválida! Digite novamente: ");
								scanf("%d %d %d", &func[x].dt_adm.dia,&func[x].dt_adm.mes,&func[x].dt_adm.ano);
								c = ValidarData(func[x].dt_adm.dia,func[x].dt_adm.mes,func[x].dt_adm.ano);
							}
							else{
								break;
							}
						}
						printf("Data de admissão alterada com sucesso!\n");
						printf("Nova data de admissão: %d %d %d\n", func[x].dt_adm.dia,func[x].dt_adm.mes,func[x].dt_adm.ano);
						//^^^^^^ EXCLUIR NO FINAL.
						break;
					case 5:
						//vvvvvv EXCLUIR NO FINAL.
				   		printf("Antigo Cargo: %d\n", func[x].cargo);
				   		printf("Digite o novo cargo?: ");
				   		scanf(" %d", &func[x].cargo);
				   		printf("Cargo alterado com sucesso!\n");
				   		printf("Novo Cargo: %d\n", func[x].cargo);
				   		//^^^^^^ EXCLUIR NO FINAL.
				   	   	break;
					default:
				   		printf("Try again\n");
				   		break;
				}
				printf("MENU ALTERAR FUNCIONARIO(CPF: %s)\n", cpf);
				printf("1 - CPF\n2 - Nome\n3 - Data de Nascimento\n4 - Data de Admissão na empresa\n5 - Cargo\n0 - Sair\n");
				scanf(" %d", &resp2);
			}
			printf("Saiu\n");
			//^^^^^^ EXCLUIR NO FINAL.
			break;
		}
	}
}

//Objetivo: Transferir um funcionario para outro departamento.
void transferir(){
	int resp,cod,j,cont=0,x,y,z,a,cod2;
	char cpf[12];
	
	while(resp!=2){
		printf("Qual o código do departamento origem?: ");
		scanf(" %d", &cod);
		for(j=0;j<10;j++){
			if(dep[j].cod == cod){
				cont++;
				x = j+1;	
			}			
		}
		if(cont==0){
			printf("Departamento %d não existe!\n", cod);
			printf("Código e nome dos Departamentos que existem: \n");
			for(j=0;j<10;j++){
				printf("Code: %d, Nome: %s\n", dep[j].cod,dep[j].nome);
			}
			printf("---------------\n0 - Para retornar ao Menu Funcionario\n1 - Digitar um novo codigo de departamento\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			printf("Quantidade de funcionários dentro do departamento q perdera gente: %d\n", dep[x-1].quant);//EXCLUIR FINAL
			break;
		}
	}
	resp = 3;
	cont = 0;
	while(resp!=2){
		printf("Qual o cpf do funcionário?: ");
		scanf(" %s", cpf);
		for(j=0;j<10;j++){
			if(func[j].dept==x){
				a = strcmp(func[j].cpf,cpf);
				if (a==0){
					cont++;
					y = j;
				}	
			}
		}
		if(cont==0){
			printf("Departamento %d não possui funcionário com o cpf %s!\n", x,cpf);
			printf("---------------\n0 - Para retornar ao Menu Funcionario\n1 - Digitar outro cpf\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			printf("Antigo Departamento: %d\n", func[y].dept); //EXCLUIR NO FINAL
			break;
		}
	}
	resp = 3;
	cont = 0;
	while(resp!=2){
		printf("Qual o código do departamento destino?: ");
		scanf(" %d", &cod2);
		for(j=0;j<10;j++){
			if(dep[j].cod == cod2){
				cont++;
			}			
		}
		if(cont==0){
			printf("Departamento %d não existe!\n", cod2);
			printf("Codigo e Nome dos Departamentos q existem: \n");
			for(j=0;j<10;j++){
				printf("Code: %d, Nome: %s\n", dep[j].cod,dep[j].nome);
			}
			printf("---------------\n0 - Para retornar ao Menu Funcionario\n1 - Digitar um novo codigo de departamento\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			func[y].dept = cod2;
			printf("Novo Departamento: %d\n", func[y].dept);
			dep[x-1].quant = dep[x-1].quant - 1;
			for(j=0;j<10;j++){
				if(dep[j].cod == cod2){
					dep[j].quant++;
					z = j;
				}
			}
			printf("Transferencia realizada com sucesso!\n");
			printf("Quantidade de funcioarios no departamento q perdeu gente: %d\n", dep[x-1].quant); //EXCLUIR FINAL
			printf("Quantidade de func. no departamento q ganhou gente: %d\n", dep[z].quant);//EXCLUIR FINAL
			break;
		}
	}
}

//Objetivo: Demitir um funcionario.
/*Quando se excluir um funcionario q esta entre outros dois ele invez de deslocar as informaçoes do sucessor
para o lugar do excluido ele apenas faz copiar.*/ // < Agora so aparece esse problema se for ficar so um funcionario.
//Aki provavelmente tbm deveria se usar ponteiro.
void demitir(){
	int resp,j,cod,cont=0,x,y,a,b;
	char cpf[12],resp2;
	
	while(resp!=2){
		printf("Qual o codigo do departamento?: ");
		scanf(" %d", &cod);
		for(j=0;j<10;j++){
			if(dep[j].cod == cod){
				cont++;
				x = j+1;	
			}			
		}
		if(cont==0){
			printf("Departamento %d não existe!\n", cod);
			printf("Codigo e Nome dos Departamentos q existem: \n");
			for(j=0;j<10;j++){
				printf("Code: %d, Nome: %s\n", dep[j].cod,dep[j].nome);
			}
			printf("---------------\n0 - Para retornar ao Menu Funcionario\n1 - Digitar um novo codigo de departamento\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			break;
		}
	}
	resp = 3;
	cont = 0;
	while(resp!=2){
		printf("Qual o cpf?: ");
		scanf(" %s", cpf);
		for(j=0;j<10;j++){
			if(func[j].dept==x){
				a = strcmp(func[j].cpf,cpf);
				if (a==0){
					cont++;
					y = j;
				}	
			}
		}
		if(cont==0){
			printf("Departamento %d não possui funcionario com o cpf %s!\n", x,cpf);
			printf("---------------\n0 - Para retornar ao Menu Funcionario\n1 - Digitar outro cpf\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			break;
		}
	}
	while((resp2!='s') || (resp2!='n')){
		printf("Deseja realmente demitir o funcionario? <s/n>: ");
		scanf(" %c", &resp2);
		if(resp2=='n'){
			printf("Funcionario não demitido!\n");
			return;
		}
		if(resp2=='s'){
			for(j=0;j<F;j++){
				a = strcmp(func[j].cpf,cpf);
				if (a==0){
					strcpy(func[j].cpf,func[j+1].cpf);
					strcpy(func[j].nome,func[j+1].nome);
					func[j].dt_nasc = func[j+1].dt_nasc;
					func[j].dt_adm = func[j+1].dt_adm;
					func[j].cargo = func[j+1].cargo;
					func[j].dept = func[j+1].dept;
					b = strcmp(func[j].cpf,cpf);
					if(b!=0){
						strcpy(func[j+1].cpf,func[y].cpf);
						strcpy(func[j+1].nome,func[y].nome);
						func[j+1].dt_nasc = func[y].dt_nasc;
						func[j+1].dt_adm = func[y].dt_adm;
						func[j+1].cargo = func[y].cargo;
						func[j+1].dept = func[y].dept;
					}
				}
			}
			strcpy(func[F-1].cpf,"");
			strcpy(func[F-1].nome,"");
		   	func[F-1].dt_nasc.dia = 0;
			func[F-1].dt_nasc.mes = 0;
			func[F-1].dt_nasc.ano = 0;
			func[F-1].dt_adm.dia = 0;
			func[F-1].dt_adm.mes = 0;
			func[F-1].dt_adm.ano = 0;
			func[F-1].cargo = 0;
			func[F-1].dept = 0;
			dep[x-1].quant = dep[x-1].quant - 1;
			printf("Funcionario demitido com sucesso!\n");
			break;
		}
	}	
}

//Objetivo: Mostrar a informaçoes de um funcionario especifico.
void pesquisar(){
	char cpf[12];
	int a,j,resp,cont=0,x;
	
	while(resp!=2){
		printf("Qual o CPF do funcionario?: ");
		scanf(" %s", cpf);
		for(j=0;j<F;j++){
			a = strcmp(func[j].cpf,cpf);
			if(a==0){
				cont++;
				x = j;
			}
		}
		if(cont==0){
			printf("CPF %s não cadastrado!\n", cpf);
			printf("---------------\n0 - Retornar ao Menu Funcionario\n1 - Digitar um novo cpf\n---------------\n");
			scanf(" %d", &resp);
			if(resp==0)
				return;
		}
		else{
			printf("Funcionario %d\n", x+1);
			printf("CPF: %s\n", func[x].cpf);
			printf("Nome: %s\n", func[x].nome);
			printf("Data de Nascimento: %d %d %d\n", func[x].dt_nasc.dia,func[x].dt_nasc.mes,func[x].dt_nasc.ano);
			printf("Data de Admissao: %d %d %d\n", func[x].dt_adm.dia,func[x].dt_adm.mes,func[x].dt_adm.ano);
			printf("Cargo: %d\n", func[x].cargo);
			printf("Departamento: %d\n", func[x].dept);
			printf("\n");
			break;
		}
	}
}

//Objetivo: Listar todos os departamentos com todos os funcionario que o integram e suas respectivas informaçoes.
void listarfunc(){
	int j,k,cont=0;
	printf("LISTA DE FUNCIONARIOS\n");
	for(j=0;j<10;j++){
		if(dep[j].cod==0){
			cont++;
		}
		else{
			if(dep[j].quant!=0){
				printf("--------------------\nDepartamento %d\n--------------------\n", j+1);
				for(k=0;k<F;k++){
					if(func[k].dept==j+1){
						printf("Funcionario %d\n", k+1);
						printf("CPF: %s\n", func[k].cpf);
						printf("Nome: %s\n", func[k].nome);
						printf("Data de Nascimento: %d %d %d\n", func[k].dt_nasc.dia,func[k].dt_nasc.mes,func[k].dt_nasc.ano);
						printf("Data de Admissao: %d %d %d\n", func[k].dt_adm.dia,func[k].dt_adm.mes,func[k].dt_adm.ano);
						printf("Cargo: %d\n", func[k].cargo);
						printf("\n");
					}
				}
			}
		}
	}
}

//Objetivo: Listar todos os funcionarios com suas informaçoes de um departamento especifico.
void listarTdep(){
	int cod,j,cont=0;
	
	printf("Qual o codigo do departamento?: ");
	scanf(" %d", &cod);
	for(j=0;j<10;j++){
		if(dep[j].cod == cod){
			cont++;
		}			
	}
	if(cont==0){
		printf("Departamento %d não existe!\n", cod);
		return;
	}
	else{
		printf("---------------\nDepartamento %d\n---------------\n", cod);
		for(j=0;j<F;j++){
			if(func[j].dept==cod){
				printf("Funcionario %d\n", j+1);
				printf("CPF: %s\n", func[j].cpf);
				printf("Nome: %s\n", func[j].nome);
				printf("Data de Nascimento: %d %d %d\n", func[j].dt_nasc.dia,func[j].dt_nasc.mes,func[j].dt_nasc.ano);
				printf("Data de Admissao: %d %d %d\n", func[j].dt_adm.dia,func[j].dt_adm.mes,func[j].dt_adm.ano);
				printf("Cargo: %d\n", func[j].cargo);
				printf("\n");
			}
		}
	}
}


		
/*
//PARTE DOS ARQUIVOS
//Objetivo: Salvar as informações de todos os funcionarios
//Salvar em ordem por departamento[FAZER],mudar pra bin
void salvar_arquivos(){
	FILE *arquivo_func;
	arquivo_func =fopen("funcionario.txt","a");
	if (arquivo_func == NULL){
		printf("Erro ao abrir o arquivo_func");
		exit(1);
	} 
	fwrite(&func,sizeof(tFuncionario),F,arquivo_func);
	fclose(arquivo_func);
}

void leitura_dos_arquivos(){
	FILE *arquivo_leitura;
 arquivo_leitura = fopen("funcionario.txt","r");
	if(arquivo_leitura == NULL){
		printf("Problemas ao abrir o arquivo!\n");
		
		}
else
{
	while(fread(&func,sizeof(tFuncionario),1,arquivo_leitura)==1)
	{
		printf("Nome: %s\n",func[i].nome);
		printf("CPF: %s\n",func[i].cpf);
		printf("Data de nasc: %d%d%d\n",func[i].dt_nasc.dia,func[i].dt_nasc.mes,func[i].dt_nasc.ano);
		printf("Data de adm: %d%d%d\n",func[i].dt_adm.dia,func[i].dt_adm.mes,func[i].dt_adm.ano);
		printf("Cargo: %d",func[i].cargo);
		printf("Departamento: %d ",func[i].dept);
	}
}
	
	
}
*/

//PARTE DOS MENUS

//Objetivo: acessar as configuraçoes de Funcionarios.
void menufunc(){
	int resp;
	printf("MENU FUNCIONARIO\n");
	printf("===============\n1 - Cadastrar funcionario\n2 - Alterar dados do funcionario\n3 - Transferir funcionario de departamento\n4 - Demitir funcionario\n5 - Pesquisar funcionario\n6 - Listar todos os funcionarios\n7 - Listar todos de um Departamento\n0 - Sair\n===============\n");
	scanf("%d", &resp);
	while(resp != 0){
		switch(resp){
			case 0:
				printf("Programa finalizado\n");
				break;
			case 1:
				cadastrar();
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
	   			pesquisar();
	   			break;
	   		case 6:
	   			listarfunc();
	   			break;
	   		case 7:
	   			listarTdep();
	   			break;
			default:
				printf("Nop,para de tentar achar bug ai,vlw\n");
				break;
		};
		printf("===============\n1 - Cadastrar funcionario\n2 - Alterar dados do funcionario\n3 - Transferir funcionario de departamento\n4 - Demitir funcionario\n5 - Pesquisar funcionario\n6 - Listar todos os funcionarios\n7 - Listar todos de um Departamento\n0 - Sair\n===============\n");
		scanf("%d", &resp);
	}
}

//Objetivo: acessar as configuraçoes de Departamentos.
void menudep(){
	int resp;
	printf("MENU DEPARTAMENTO\n");
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
    				consultardep();
		   			break;
		   		case 4:
		   			listardep();
		   			break;
		   		case 5:
		   			excluirdep();
		   			break;
				default:
					printf("Nop,para de tentar achar bug ai,vlw\n");
					break;
			};
			printf("===============\n1 - Criar Departamento\n2 - Alterar nome do Departamento\n3 - Consultar Departamento\n4 - Listar Departamentos\n5 - Excluir Departamento\n0 - Sair\n===============\n");
			scanf("%d", &resp);
		}
}

//Objetivo: acessar os menus Departamento e Funcionario.
void menuprin(){
	int resp;
	printf("MENU PRINCIPAL\n");
	printf("===============\n1 - Funcionario\n2 - Departamento\n0 - Sair\n===============\n");
	scanf(" %d", &resp);
	while(resp != -1){
		switch(resp){
			case 0:
				//salvar_arquivos();
				printf("Programa finalizado\n");
				exit(1);
				break;
			case 1:
				menufunc();
				break;
			case 2:
				menudep();
				break;
			default:
				printf("Nop,para de tentar achar bug ai,vlw\n");
				break;
		};
		printf("MENU PRINCIPAL\n");
	   	printf("===============\n1 - Funcionario\n2 - Departamento\n0 - Sair\n===============\n");
		scanf(" %d", &resp);
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	menuprin();
	return 0;
}; 
