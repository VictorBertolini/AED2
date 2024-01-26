#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void insertionSort(int *vet, int size)
{
    int aux, j;
    for (int i = 1; i < size; i++)
    {
        aux = vet[i];
        for (j = i - 1; j >= 0 && vet[j - 1] > aux; j--)
            vet[j + 1] = vet[j];
        vet[j] = aux;
    }
}

int main()
{
    srand(time(NULL));

    int vet[SIZE];

    for (int i = 0; i < SIZE; i++)
        vet[i] = rand() % SIZE;

    for (int i = 0; i < SIZE; i++)
        printf("[ %d ] ", vet[i]);


    insertionSort(vet, SIZE);

    printf("\n");
    for (int i = 0; i < SIZE; i++)
        printf("[ %d ] ", vet[i]);

    return 0;
}