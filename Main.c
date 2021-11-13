#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int boolean = 1;
    char command;
    FILE *f;
    char buff;

    while (boolean)
    {
        printf("Enter the command:");
        scanf("%c", &command);
        while (getchar() != '\n');
        switch (command)
        {
        case 's':
            f = fopen("jazdci.csv", "r");
            printf("summ is working \n");
            break;
         case 'd':
         printf("Driver is working \n");
          break;
        default:
            printf("Try another command \n");
            break;
        }
    }
    return 0;
}