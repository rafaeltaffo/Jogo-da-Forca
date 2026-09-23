// Jogo da Forca - Rafael Taffo Montanha

#include<stdio.h>
#include<stdlib.h>

void limparTela();
int menuPrincipal();
int menuJogo();
void forcaIA();
int jogarIA();

int main(void)
{
	int opcao;
	do
	{
		opcao = menuPrincipal();
		switch(opcao)	
		{
			case 1:
				limparTela();
				jogarIA();
		}
	} while(opcao != 3);
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

int jogarIA()
{	
	forcaIA();
	int tamanho = strlen(palavra_secreta);

    char exibir[50];
    for(int i = 0; i < tamanho; i++)
    {
        exibir[i] = '_';
    }
	exibir[tamanho] = '\0';
}
	
