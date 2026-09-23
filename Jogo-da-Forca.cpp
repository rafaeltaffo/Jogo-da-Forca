// Jogo da Forca - Rafael Taffo Montanha

#include<stdio.h>
#include<stdlib.h>

void limparTela();
int menuPrincipal();
int menuJogo();
void forcaIA();

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

int menuJogo()
{
	int opcao;
	printf("|1 - Adivinhar uma letra|\n");
    printf("|2 - Adivinhar a palavra|\n\n");
    printf("Opcao: ");
	scanf(" %d", &opcao);
}

void forcaIA()
{
	char *palavras[] = { "Bola", "Girassol", "Laranja", "Computador", "Paralelepipedo", "Guitarra" };
    int total = 6;
	
    srand(time(NULL)); 
    int indice = rand() % total;
	
    strcpy(palavra_secreta, palavras[indice]);
}
