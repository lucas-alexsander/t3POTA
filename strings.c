#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<conio.h>

//funcao responsavel por imprimir a lista de strings
void printStrings(char c[][25], int qtd){
    
    int i, j;
    
    for (i = 0; i < qtd; i++){
    	printf("\n[");    	
    	for (j = 0; j < 25; j++){
    		
    		printf("%c", c[i][j]);
		}
		printf("]");
	}
    
}


//Funcao que ira gerar aleatoriamente strings
void randomStrings(char c[][25], int qtd){
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < qtd; i++){
		for(j = 0; j < 25; j++){
			c[i][j] = 'a' + (char)(rand()%26);
		}		
	}
    
    printStrings(c, qtd);
}

//metodo de ordenacao bubble sort
void bubbleSortS(char c[][25], int qtd) {
	
	int i, j, mov = 0, comp = 0;	
	
	char temp[25];
	
	char c2[qtd][25];    
    
	for (i = 0; i < qtd; i++){
		for(j = 0; j < 25; j++){
			c2[i][j] = c[i][j];
		}
	}
  
    for (j=0; j<qtd-1; j++)
    {
        for (i=j+1; i<qtd; i++)
        {
        	comp++;
            if (strcmp(c[j], c[i]) > 0)
            {
                strcpy(temp, c[j]);
                strcpy(c[j], c[i]);
                strcpy(c[i], temp);
                mov++;
            }
        }
    }

    printf("\n\caracteres ordenados atraves do metodo bubble sort:\n");
    printStrings(c2, qtd);
    printf("\nForam feitas %d comparacoes e %d movimentacoes,", comp, mov);
}


//Funcao para trabalhar com strings
void optionStrings(){
	
	int qtdStr;

    printf("\nInforme quantos grupos de caracteres serao gerados\n");
    scanf("%d", &qtdStr);
    
    //cria um vetor com a quantidade de grupo de caracteres que serao informadas (tamanho maximo de 25 caracteres)
    char palavra[qtdStr][25];
	
    int option;
    while(1==1){
        printf("\n---------------------");
        printf("\nEscolha uma das opcoes:");
        printf("\n1 - Gerar caracteres Aleatorios");
        printf("\n2 - Retornar ao menu principal\n");
        scanf("%d", &option);
        switch (option)
        {        
        case 1:
            randomStrings(palavra, qtdStr);
            bubbleSortS(palavra, qtdStr);
            break;
        case 2:
            return;         
        default:
            printf("Informe um numero valido entre 1 e 2");
            break;
        }
    }
    return;
}
