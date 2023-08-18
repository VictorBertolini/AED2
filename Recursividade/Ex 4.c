#include <stdio.h>
// Faca uma funcao recursiva que permita somar os elementos de um vetor de inteiros. 

int recursiveSum(int *list, int size)
{
    if (size > 0)
        return list[size - 1] + recursiveSum(list, size - 1);
    return 0;
}

int main()
{  
    int size = 10;
    int numList[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int answer;

    answer = recursiveSum(numList, size);
    
    printf("The result is: [ %d ]\n", answer);

    return 0;
}