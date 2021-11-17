#include <stdio.h>
#include <stdlib.h>
#include "dates.c"
#include "numbers.c"
#include "strings.c"

int main()
{
    int option;
    while (1 == 1)
    {
        printf("\n====================");
        printf("\nEscolha uma opcao:\n");
        printf("\n1 - Numeros");
        printf("\n2 - Palavras");
        printf("\n3 - Datas");
        printf("\n4 - Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            optionNumbers();
            break;
        case 2:
            optionStrings();
            break;
        case 3:
            optionDates();
            break;
        case 4:
            printf("\nSee you, bye bye");
            return 0;
        default:
            break;
        }
    }
}
