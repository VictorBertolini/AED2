#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void shellSort(int *vet, int size)
{
    int h = 1;
    int aux;
    int j;
    do
    {
        h = h * 3 + 1;
    } while (h < size);

    do
    {
        h = h / 3;

        for (int i = h; i < size; i++)
        {
            aux = vet[i];
            for (j = i; j >= h && aux < vet[j - h]; j = j - h)
                vet[j] = vet[j - h];
            
            vet[j] = aux;
        }
    } while (h != 1);
}

int main()
{
    srand(time(NULL));

    int vet[SIZE];

    for (int i = 0; i < SIZE; i++)
        vet[i] = rand() % SIZE;

    for (int i = 0; i < SIZE; i++)
        printf("[ %d ] ", vet[i]);


    shellSort(vet, SIZE);

    printf("\n");
    for (int i = 0; i < SIZE; i++)
        printf("[ %d ] ", vet[i]);

    return 0;
}