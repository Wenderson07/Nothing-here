#include <stdio.h>
#include <string.h>
#include <conio.h>

void cadastro(){
	printf("Usuario cadastrado com sucesso\n");
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
			
		switch(resp)
		{
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
		scanf("%d", &resp);}
}
	
int main(){
	menu();
};
