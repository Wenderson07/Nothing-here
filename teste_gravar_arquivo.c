#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define F 4
int i = 0;

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


void cadastrar(){
	char resp ='s';
	do{
	printf("\nQual o cpf?: ");
   	scanf(" %s",func[i].cpf);
	printf("Qual o nome?: ");
	scanf(" %s",func[i].nome);
	printf("Qual a data de nascimento?: ");
	scanf("%d %d %d", &func[i].dt_nasc.dia,&func[i].dt_nasc.mes,&func[i].dt_nasc.ano);
	printf("Qual a data de admissao na empresa?: ");
	scanf("%d %d %d", &func[i].dt_adm.dia,&func[i].dt_adm.mes,&func[i].dt_adm.ano);
	printf("Qual o cargo?: ");
	scanf(" %d", &func[i].cargo);
	printf("Qual o departamento?: ");
	scanf(" %d", &func[i].dept);
	i++;
	printf("Deseja continuar?\n");
	resp =getche();}
	while(resp != 'n');
}

//PARTE DOS ARQUIVOS
//Objetivo: Salvar as informações de todos os funcionarios
int salvar_arquivos(){
	FILE *arquivo;
	int j;
	
	arquivo =fopen("funcionario.txt","w");
	if (arquivo == NULL){
		printf("Erro ao abrir o arquivo");
		exit(1);
	} 
	fwrite(func,sizeof(tFuncionario),F,arquivo);
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
}}




int main(){
	cadastrar();
	salvar_arquivos();
	leitura_dos_arquivos();
	return 0;
}
