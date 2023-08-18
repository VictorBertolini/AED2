#include <stdio.h>

/*
12. Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo N e imprima todos os ´
numeros naturais de 0 at ´ e N em ordem crescente.
*/

void recursivePrint(int num, int size)
{
    if (size != num)
    {
        printf("[ %d ] ", size);
        return recursivePrint(num, size + 1);
    }
    
    printf("[ %d ]", num);
    return;
}

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    recursivePrint(num, 0);

    return 0;
}