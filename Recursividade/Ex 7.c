#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
7. Crie um programa em C que receba um vetor de numeros reais com 100 elementos. ´
Escreva uma func¸ao recursiva que inverta ordem dos elementos presentes no vetor.
*/

void recursiveInvert(int *array, int size)
{
    int aux;
    size--;

    if (size > 50)
    {
        aux = array[size];
        array[size] = array[99 - size];
        array[99 - size] = aux;

        return recursiveInvert(array, size);
    }
}

int main()
{
    int 
        size = 100,
        numList[size];

    srand(time(NULL));

    for (int count = 0; count < size; count++)
    {
        numList[count] = count;
        printf("[ %d ] ", numList[count]);
    }

    recursiveInvert(numList, size);
    printf("\n====================================================================\n\n");

    for (int count = 0; count < size; count++)
        printf("[ %d ] ", numList[count]);
    
    return 0;
}