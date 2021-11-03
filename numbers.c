#include <stdio.h>
#include <stdlib.h>

//Função que irá gerar aleatoriamente números
void randomNumbers(){
    printf("randomNumbers");
}

//Função que receberá números de um arquivo
void getFromFile(){
    printf("getFromFile");
}

//Função que receberá do usuário números a serem armazenados em memória
void inputNumbers(){
    int qtdNumbers;
    int* listaNumeros;

    printf("\nInforme quantos numeros serao gerados:");
    scanf("%d", &qtdNumbers);
    //Reserva em memória a quantidade de numeros (int) que serão gravados
    listaNumeros = (int*)malloc(qtdNumbers * sizeof(int));

    for(int i = 0; i < qtdNumbers; i++){
        printf("\nInforme um numero a ser gravado na lista: ");
        scanf("%d", &listaNumeros[i]);
    }

    printNumbers(listaNumeros, qtdNumbers, 0);
}

//Função recursiva que imprime na tela os números da lista passada por referência
//
//Recebe um ponteiro de lista de inteiros;
//Recebe a quantidade de elementos da lista;
//Recebe a contagem atual da recursão;
void printNumbers(int *listaNumeros, int qtd, int cont){
    if(cont == 0){
        printf("[");
    }
    if(cont < qtd-1){
        printf("%d, ", listaNumeros[cont]);
        printNumbers(listaNumeros, qtd, ++cont);
    }
    else{
        printf("%d]", listaNumeros[cont]);
    }
}

//Função para trabalhar com números
void optionNumbers(){
    int option;
    while(1==1){
        printf("\n---------------------");
        printf("\nEscolha uma das opcoes:");
        printf("\n1 - Gerar Numeros Aleatorios");
        printf("\n2 - Ler numeros do arquivo");
        printf("\n3 - Receber numeros manualmente");
        printf("\n4 - Retornar ao menu principal\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            randomNumbers();
            break;
        case 2:
            getFromFile();
            break;   
        case 3:
            inputNumbers();
            break;    
        case 4:
            return;         
        default:
            printf("Informe um numero valido entre 1 e 3");
            break;
        }
    }
    return;
}
