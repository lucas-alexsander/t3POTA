#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struct para armazenamento dos dados de uma Data
struct date
{
    int day;
    int month;
    int year;
};

//struct date Date
typedef struct date Date;

//struct dates para armazenar Date
struct dates
{
    int quantidade;
    Date* datas;
};

typedef struct dates Dates;


Date getDate(Dates* dates, int posicao)
{
    Date data = dates->datas[posicao];
    return data;
}

void printStringDate(Date* date)
{
    printf("%d/%d/%d", date->day, date->month, date->year);
}

void setDate(Dates* dates, Date date, int posicao){
    dates->datas[posicao] = date;
}

//Recebe uma variável do tipo Date*
//
//Retorna a conversão data em número de dias
int dateToDays(Date *date)
{
    return date->day + date->month * 30 + date->year * 12 * 30;
}

//Função criada para comparar duas datas do tipo Date
//
//Recebe duas variáveis do tipo Date*
//
//Retorna -1 se a date1 for maior;
//Retorna 0 se forem iguais;
//Retorna 1 se data2 for maior;
int compareDates(Date *date1, Date *date2)
{
    if (dateToDays(date1) > dateToDays(date2))
    {
        return -1;
    }
    else if (dateToDays(date1) == dateToDays(date2))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Função que irá gerar aleatoriamente datas
void randomDates(Dates *datas)
{
    //srand(time(NULL));
    
    for(int i = 0; i < datas->quantidade; i++){
        
        int dia = rand() % 30;
        int mes = rand() % 12;
        int ano = rand() % 2021;

        Date data;
        data.day = dia;
        data.month = mes;
        data.year = ano;

        datas->datas[i] = data;

    }
    printf("\nrandomNumbers");
    printDatas(datas);

    subMenuDates(datas);
}

//Função que receberá datas de um arquivo
void getDatesFromFile(Dates *datas)
{
    printf("\nAINDA NAO IMPLEMENTADO");
    printf("\ngetFromFile");
}

//Função que receberá do usuário datas a serem armazenados em memória
void inputDates(Dates *datas)
{


    printf("\ninputDates");
    for(int i = 0; i < datas->quantidade; i++){
        Date dataNova;

        printf("\nInforme o dia: ");
        int dia;
        scanf("%d", &dia);

        printf("\nInforme o mes: ");
        int mes;
        scanf("%d", &mes);

        printf("\nInforme o ano: ");
        int ano;
        scanf("%d", &ano);

        dataNova.day = dia;
        dataNova.month = mes;
        dataNova.year = ano;
        setDate(datas, dataNova, i);        
    }
    printf("DATAS INFORMADAS: ");
    printDatas(datas);

    subMenuDates(datas);
    
}



//IMPRIME NA TELA UMA LISTA DE DATAS
void printDatas(Dates* listaDatas)
{
    printf("[ ");
    for(int i = 0; i < listaDatas->quantidade; i++){
        if(i==0){
            printStringDate(&listaDatas->datas[i]);
        }
        else{
            printf(", ");
            printStringDate(&listaDatas->datas[i]);
        }
    }
    printf(" ]");
}

//selectSortDates(Dates* listaDatas)
void selectSortDates(Dates* listaDatas)
{
    int i,j, menor;

    for(i = 0; i < listaDatas->quantidade; i++)
    {
        menor = i;
        Date dateMin = getDate(listaDatas, i);
        for(j = i+1; j < listaDatas->quantidade; j++)
        {
            Date dateAtual = getDate(listaDatas, j);
            //SE A DATA ATUAL FOR MENOR QUE A DATA MENOR
            if(compareDates(&dateMin, &dateAtual) == -1){
                menor = j;
                dateMin = dateAtual;
            }
        }
        //TROCAR POSICAO MENOR SE FOR DIFERENTE DE I
        if(i != menor){
            Date dateAux = getDate(listaDatas, i);
            setDate(listaDatas, dateMin, i);
            setDate(listaDatas, dateAux, menor);
        }
    }

    printf("\nDATAS ORDENADAS: ");
    printDatas(listaDatas);
}

//Metodo de ordenacao insert Sort
void insertionSortDates(Dates* listaDatas) {
	int i, j, aux, comp = 0, mov = 0;
    Date date_aux;
	Dates* listaDatasNova;//int vetor[n];    
	listaDatasNova->quantidade = listaDatas->quantidade;
	for (i = 0; i < listaDatas->quantidade; i++){
		listaDatasNova->datas[i] = listaDatas->datas[i];
	}
	
	clock_t begin = clock(); 
  	for (i = 1; i < listaDatas->quantidade; i++) {
    	j = i;
        while (j > 0 && compareDates(&listaDatasNova->datas[j - 1], &listaDatasNova->datas[j]) == -1) {
              date_aux = listaDatasNova->datas[j];
              listaDatasNova->datas[j] = listaDatasNova->datas[j - 1];
              listaDatasNova->datas[j - 1] = date_aux;
              j--;
              comp++;
              mov++;
        }  	
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("\n\nNumeros ordenados atraves do metodo insert sort:\n");
    listaDatas = listaDatasNova;
    printDatas(listaDatas);
    printf("\nForam feitas %d comparacoes e %d movimentacoes no tempo de: %f", comp, mov, time_spent);
}

//bubbleSortDates(Dates* listaDatas)
void bubbleSortDates(Dates* listaDatas)
{
    printf("\nbubbleSortDates(Dates* listaDatas)");

        int i, j, aux, mov = 0, comp = 0;
    Date date_aux;
	Dates* novaLista;//int vetor[n];    
    novaLista->quantidade = listaDatas->quantidade;
    
	for (i = 0; i < listaDatas->quantidade; i++){
		novaLista->datas[i] = listaDatas->datas[i];
	}
    
    clock_t begin = clock();
	for (i = 1; i < listaDatas->quantidade; i++) {
        
        for (j = 0; j < listaDatas->quantidade - 1; j++) {
            
            comp++;
            if (compareDates(&novaLista->datas[j], &novaLista->datas[j+1]) == -1) {
                date_aux          = novaLista->datas[j];
                novaLista->datas[j]     = novaLista->datas[j + 1];
                novaLista->datas[j + 1] = date_aux;
                mov++;
            }
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("\nDatas ordenadas atraves do metodo bubble sort:\n");
    listaDatas = novaLista;
    printDatas(listaDatas);
    printf("\nForam feitas %d comparacoes e %d movimentacoes no tempo de: %f", comp, mov, time_spent);

}

//MENU BUSCAS
void subMenuDates(Dates* datas)
{
    int option, optionOK;
    while (1 == 1)
    {
        printf("\n---------------------");
        printf("\nEscolha uma das opcoes:");
        //Select sort, Insertion sort e o bubble sort
        printf("\n1 - Ordenacao 1: SELECT SORT");
        printf("\n2 - Ordenacao 2: INSERTION SORT");
        printf("\n3 - Ordenacao 3: BUBBLE SORT");
        printf("\n4 - Voltar\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            selectSortDates(datas);
            break;
        case 2:
            insertionSortDates(datas);
            break;
        case 3:
            bubbleSortDates(datas);
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

//Menu principal
void optionDates()
{
    Dates *datas = (Dates*)malloc(sizeof(Dates));


    int qtdDatas;

    printf("\nInforme a quantidade de datas: ");
    scanf("%d", &qtdDatas);
    datas->quantidade = qtdDatas;
    
    int option;
    while (1 == 1)
    {
        printf("\n---------------------");
        printf("\nEscolha uma das opcoes:");
        printf("\n1 - Gerar Datas Aleatorios");
        printf("\n2 - Receber Datas manualmente");
        printf("\n3 - Retornar ao menu principal\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            randomDates(datas);
            break;
        case 2:
            inputDates(datas);
            break;
        case 3:
            return;
        default:
            printf("Informe um numero valido entre 1 e 3");
            break;
        }
    }
    return;
}