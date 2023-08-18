#include <stdio.h>

/*
13. Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo N e imprima todos os ´
numeros naturais de 0 at ´ e N em ordem decrescente. 
*/

void recursivePrint(int num, int size)
{
    if (size > 0)
    {
        printf("[ %d ] ", size);
        return recursivePrint(num, size - 1);
    }
    
    return;
}

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    recursivePrint(num, num);

    return 0;
}