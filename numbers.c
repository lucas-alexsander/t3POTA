#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao recursiva que imprime na tela os numeros da lista passada por referencia
//
//Recebe um ponteiro de lista de inteiros;
//Recebe a quantidade de elementos da lista;
//Recebe a contagem atual da recursao;
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

//Funcao que ira gerar aleatoriamente numeros
void randomNumbers(int vet[], int quantidade){
	int i;
	
	srand(time(NULL));
	
	for(i = 0; i < quantidade; i++){
		
		vet[i] = rand() % 1000;
	}
    
    printNumbers(vet, quantidade, 0);
}

//Funcao que recebera numeros de um arquivo
void getFromFile(int vet[], int quantidade){
	int i;
	
	FILE *arquivo;
	
	arquivo = fopen("numeros.txt", "r");
	
	if (arquivo == NULL){
		printf("ERRO! O arquivo não existe!\n");
	}
	else{
		//Le arquivo com numeros separados por quebra de linha
		for(i = 0; i < quantidade; i++){
			fscanf(arquivo, "%d\n", &vet[i]);
		}
	}
		
	fclose(arquivo);
	printNumbers(vet, quantidade, 0);	
}

//Funcao que recebera do usuario numeros a serem armazenados em memoria
void inputNumbers(int vet[], int quantidade){
	
	int i;

    for(i = 0; i < quantidade; i++){
        printf("\nInforme um numero a ser gravado na lista: ");
        scanf("%d", &vet[i]);
    }

    printNumbers(vet, quantidade, 0);
}

//metodo de ordenacao bubble sort
void bubbleSort(int *vet, int n) {
    int i, j, aux, mov = 0, comp = 0;
    
	int vetor[n];    
    
	for (i = 0; i < n; i++){
		vetor[i] = vet[i];
	}
    
    clock_t begin = clock();
	for (i = 1; i < n; i++) {
        
        for (j = 0; j < n - 1; j++) {
            
            comp++;
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
                mov++;
            }
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("\n\nNumeros ordenados atraves do metodo bubble sort:\n");
    printNumbers(vetor, n, 0);
    printf("\nForam feitas %d comparacoes e %d movimentacoes no tempo de: %f", comp, mov, time_spent);
}

//Metodo de ordenacao select Sort

void selectSort(int *vet, int n) {
	
	int i, j, i_menor, aux, mov = 0, comp = 0;
    
	int vetor[n];    
    
	for (i = 0; i < n; i++){
		vetor[i] = vet[i];
	}
	clock_t begin = clock();
	for (i = 0; i < n; i++) {
		
		i_menor = i;
		for (j = i + 1; j < n; j++){
			comp++;
			if (vetor[j] < vetor[i_menor]){
				i_menor = j;
			}				
		}		
		
		aux = vetor[i];
		vetor[i] = vetor[i_menor];
		vetor[i_menor] = aux;
		mov++;
	}
	clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
	printf("\n\nNumeros ordenados atraves do metodo select sort:\n");
    printNumbers(vetor, n, 0);
    printf("\nForam feitas %d comparacoes e %d movimentacoes no tempo de: %f", comp, mov, time_spent);	
}

//Metodo de ordenacao insert Sort
void insertSort(int *vet, int n) {
	int i, j, aux, comp = 0, mov = 0;
	int vetor[n];    
	
	for (i = 0; i < n; i++){
		vetor[i] = vet[i];
	}
	
	clock_t begin = clock(); 
  	for (i = 1; i < n; i++) {
    	j = i;
        while (j > 0 && vetor[j - 1] > vetor[j]) {
              aux = vetor[j];
              vetor[j] = vetor[j - 1];
              vetor[j - 1] = aux;
              j--;
              comp++;
              mov++;
        }  	
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("\n\nNumeros ordenados atraves do metodo insert sort:\n");
    printNumbers(vetor, n, 0);
    printf("\nForam feitas %d comparacoes e %d movimentacoes no tempo de: %f", comp, mov, time_spent);
}



//Funcao para trabalhar com numeros
void optionNumbers(){
	
	int qtdNumbers;
    int* listaNumeros;

    printf("\nInforme quantos numeros serao gerados ou lidos:\n");
    scanf("%d", &qtdNumbers);
    //Reserva em memoria a quantidade de numeros (int) que serao gravados
    listaNumeros = (int*)malloc(qtdNumbers * sizeof(int));
	
    int option;
    while(1==1){
        printf("\n---------------------");
        printf("\nEscolha uma das opcoes:");
        printf("\n1 - Gerar Numeros Aleatorios");
        printf("\n2 - Ler numeros do arquivo");
        printf("\n3 - Inserir numeros manualmente");
        printf("\n4 - Retornar ao menu principal\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            randomNumbers(listaNumeros, qtdNumbers);
            bubbleSort(listaNumeros, qtdNumbers);
            selectSort(listaNumeros, qtdNumbers);
            insertSort(listaNumeros, qtdNumbers);
            break;
        case 2:
            getFromFile(listaNumeros, qtdNumbers);
            bubbleSort(listaNumeros, qtdNumbers);
            selectSort(listaNumeros, qtdNumbers);
            insertSort(listaNumeros, qtdNumbers);
            break;   
        case 3:
            inputNumbers(listaNumeros, qtdNumbers);
            bubbleSort(listaNumeros, qtdNumbers);
            selectSort(listaNumeros, qtdNumbers);
            insertSort(listaNumeros, qtdNumbers);
            break;    
        case 4:
            return;         
        default:
            printf("Informe um numero valido entre 1 e 4");
            break;
        }
    }
    return;
}
