// Jogo da Forca - Rafael Taffo Montanha

#include<stdio.h>
#include<stdlib.h>

void limparTela();
int menuPrincipal();

int main(void)
{
	int opcao;
	opcao = menuPrincipal();
}
	
void limparTela()
{
	system("cls");
}

int menuPrincipal()
{
	int opcao;
	printf("========================= Jogo da Forca =========================\n\n");
    printf("1 - Iniciar Novo Jogo (IA)\n");
    printf("2 - Iniciar Novo Jogo (2 Jogadores)\n");
    printf("3 - Sair\n\n");
    printf("Opcao: ");
	scanf(" %d", &opcao);
}
