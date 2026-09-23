// Jogo da Forca - Rafael Taffo Montanha

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

char palavra_secreta[50];
void limparTela();
void forcaIA();
int menuPrincipal();
int menuJogo();
int jogarIA();

	int main()
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

void forcaIA()
{
	char *palavras[] = { "Bola", "Girassol", "Laranja", "Computador", "Paralelepipedo", "Guitarra" };
    int total = 6;
    
    srand(time(NULL)); 
    int indice = rand() % total;

    strcpy(palavra_secreta, palavras[indice]);
}

int menuPrincipal()
{
	int opcao;
	
	printf("========================= Jogo da Forca =========================\n\n");
    printf("1 - Iniciar Novo Jogo (IA)\n");
    printf("2 - Iniciar Novo Jogo (2 Jogadores)\n");
    printf("3 - Sair\n\n");
    printf("Opcao: ");
    
    if (scanf(" %d", &opcao) != 1)
    {
        opcao = -1;
        printf("\nOpcao invalida!\n\n");
    	system("pause");
    	limparTela();
    	int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    else if (opcao < 1 || opcao > 3)
    {
        printf("\nOpcao invalida!\n\n");
        opcao = -1;
        system("pause");
    	limparTela();
    }
    return opcao;
}

int menuJogo()
{
	int opcao;
	
	printf("\n");
	printf("|1 - Adivinhar uma letra|\n");
    printf("|2 - Adivinhar a palavra|\n\n");
    printf("Opcao: ");
	
    if (scanf(" %d", &opcao) != 1)
    {
        opcao = -1;
        printf("\nOpcao invalida!\n\n");
    	system("pause");
    	limparTela();
    	int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    else if (opcao != 1 && opcao != 2)
    {
        printf("\nOpcao invalida!\n\n");
        opcao = -1;
        system("pause");
    	limparTela();
    }
	return opcao;
}

int jogarIA()
{
	char letra;
	int vidas = 6;
	int venceu = 0;
	
	forcaIA();
	int tamanho = strlen(palavra_secreta); // Conta o tamanho da string

    char exibir[50];
    for(int i = 0; i < tamanho; i++)
    {
        exibir[i] = '_';	// Substitui as letras por '_'
    }
	exibir[tamanho] = '\0';
	
	do
	{
		printf("========================= Jogo da Forca =========================\n\n");
		printf("Palavra: %s\t\t\t\t\tVidas: %d\n", exibir, vidas);
	
		int opcao = menuJogo();
	
		switch(opcao)
		{
			case 1:	
				printf("Letra: ");
				scanf(" %c", &letra);
				
				int acertou = 0;
				for (int k = 0; k < tamanho; k++)
				{
					if(palavra_secreta[k] == letra)
					{
						exibir[k] = letra;
						acertou = 1;
					}
				}
				
				if(!acertou)
				{
					vidas--;
					printf("\nLetra errada! Perdeu uma vida.\n\n");
					system("pause");
				}
				
				if (strcmp(exibir, palavra_secreta) == 0)
				{
				    printf("\nVoce venceu! A palavra era: %s\n\n", palavra_secreta);
				    venceu = 1;
				    system("pause");
				}
				limparTela();
				break;				
		}
	} while ((vidas > 0) && (!venceu));
}

