#include <stdio.h>
#include <stdlib.h>

struct date
{
    int day;
    int month;
    int year;
};

typedef struct date Date;

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