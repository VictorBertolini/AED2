#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

/*PROGRAMAÇÃO DINÂMICA*/
long vetorFibonacci[SIZE];
int position = 2; // The position 0 and 1 already has values


long fibonacci_BottomUp(int num)
{
    // Put the starter values
    vetorFibonacci[0] = 1;
    vetorFibonacci[1] = 1;

    // Getting the value before because arrays starts in 0
    num = num - 1;

    // It start calculating the position 2, than 3, than 4.... until 'num' position
    for (int i = position; i <= num; i++)
        vetorFibonacci[i] = vetorFibonacci[i - 2] + vetorFibonacci[i - 1];

    // Now you don't need to calculate everything before because the starter position is changed
    if (num > 1)
        position = num;

    // Return the result
    return vetorFibonacci[num];
}

int main()
{
    int
        num,
        result;

    printf("Digite um numero para ver o correspondente em Fibonacci:\n");
    scanf("%d", &num);

    result = fibonacci_BottomUp(num);

    printf("O resultado eh: %d\n", result);

    return 0;
}