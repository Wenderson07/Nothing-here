#include <stdio.h>
#include <string.h>
#include <conio.h>
void cadastro(){
	printf("Usuario cadastrado com sucesso");
}
void fim(){
	printf("Programa finalizado");
}
	
void demitir(){
	printf("O funcionario foi demitido");
}
void transferir(){
	printf("O usuario foi transferido");
	
}
void menu(){
	int resp;
	printf("===============\n1 - Cadastrar\n2 - Demitir\n3 - Transferir\n0 - Sair\n===============\n");
		scanf("%d", &resp);
		switch(resp)
		{
		case 0:
			fim();
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
			printf("nop");
			break;
		};
}
	
int main(){
	menu();
};
