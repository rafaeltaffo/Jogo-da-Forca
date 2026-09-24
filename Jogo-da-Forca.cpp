// Jogo da Forca - Rafael Taffo Montanha

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

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
					break;
				case 2:
					limparTela();
					break;
				case 3:
					return 0;	
			}
				
		} while(1);
	}

void limparTela()
{
	system("cls");
}

void forcaIA()
{
	char *palavras[] = { "Bola", "Girassol", "Laranja", "Computador", "Paralelepipedo", "Guitarra", "Caderno", "Otorrinolaringologista", "Esmeralda", "Aventura", "Montanha", "Basquete", "Futebol", "Galaxia", "Planeta", "Moeda", "Dinheiro", "Independencia", "Chiclete", "Contexto" };
    int total = 20;
    
    srand(time(NULL)); 
    int indice = rand() % total;

    strcpy(palavra_secreta, palavras[indice]);
}

int menuPrincipal()
{
	int opcao;
	
	printf("==================================================== Jogo da Forca =====================================================\n\n");
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
	char letras_testadas[26];
	int vidas = 6;
	int venceu = 0;
	int total_testadas = 0;
	
	
	
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
		printf("==================================================== Jogo da Forca =====================================================\n\n");
		printf("Palavra: %s\t\t\t\t\t\t\t\t\t\t\t\tVidas: %d\n", exibir, vidas);
	
	
		printf("Letras erradas: ");
		for (int j = 0; j < total_testadas; j++)
		{
		    printf("%c", letras_testadas[j]);
		    if (j < total_testadas - 1)
		    {
		        printf(", ");
		    }
		}
		printf("\n");
		
		int opcao = menuJogo();
				
		switch(opcao)
		{
			case 1:	
			{
			    printf("Letra: ");
			    scanf(" %c", &letra);
			    
			    int acertou = 0;
			    
			    if (!isalpha(letra))
			    {
			        printf("\nEntrada invalida! Digite uma letra, nao um numero.\n\n");
			        system("pause");
			        limparTela();
			        break;
			    }
			    
			    letra = tolower(letra);
			    
			    int ja_testou = 0;
			    for (int j = 0; j < total_testadas; j++)
			    {
			    	if (letras_testadas[j] == letra)
			    	{
			    		ja_testou = 1;
					}
				}
				
				if(ja_testou)
				{
					printf("\nVoce ja tentou essa letra! Escolha outra.\n\n");
					system("pause");
					limparTela();
					break;
				}
				
			    for (int k = 0; k < tamanho; k++)
			    {
			        if(tolower(palavra_secreta[k]) == letra)
			        {
			            exibir[k] = palavra_secreta[k];
			            acertou = 1;
			        }
			    }
			    
			    if(!acertou)
			    {
			        vidas--;
			        printf("\nLetra errada! Perdeu uma vida.\n\n");
			        system("pause");
			        
			        letras_testadas[total_testadas] = letra;
    				total_testadas++;
			    }
			    
			    if (strcmp(exibir, palavra_secreta) == 0)
			    {		        
			        venceu = 1;
			    }
			    limparTela();
			    break;
			}
				
			case 2:
	        {
	            char chute[50];
	            printf("Palavra: ");
	            scanf(" %s", chute);
	            
	            if (_stricmp(chute, palavra_secreta) == 0)
	            {
	                venceu = 1;
	            }
	            else
	            {
	                vidas = 0;
	            }
	            limparTela();
		        break;
	        }
		}	
	} while ((vidas > 0) && (!venceu));
	
	printf("==================================================== Jogo da Forca =====================================================\n\n");
	
	if (venceu)
	{
	    printf("Parabens, voce venceu!\t\t\t\t\t\t\t\t\t\t\t\tVidas: %d\n\n", vidas);
	}
	else
	{
	    printf("Voce perdeu! Suas vidas acabaram.\t\t\t\t\t\t\t\t\t\tVidas: %d\nA palavra era: %s\n\n", vidas, palavra_secreta);
	}

	system("pause");
	limparTela();
	
	return 0;
}
