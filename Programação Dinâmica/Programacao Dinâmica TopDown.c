#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

/*PROGRAMAÇÃO DINÂMICA*/
long vetorFibonacci[SIZE]; // Array to help making the calculus


// Function where the recursion and the calculus are made
int fibonacci_TopDown(int num)
{
    // If the space wanted isn't calculated (-1) so you start the recursion (sum the 2 results before)
    if (vetorFibonacci[num] == -1)
        vetorFibonacci[num] = fibonacci_TopDown(num - 1) + fibonacci_TopDown(num - 2);
    
    // Return the value calculated 
    return vetorFibonacci[num];
}

// Funcition to prepare to start calculating without errors
int fibonacci_TopDown_inicial(int num)
{
    // Put the 2 start values (needed)
    vetorFibonacci[0] = 1;
    vetorFibonacci[1] = 1;

    // Clean all the array for the program know the unknown values
    for (int i = 2; i < SIZE; i++)
        vetorFibonacci[i] = -1;

    // Put 1 space back because the array starts with 0 position
    num = num - 1;

    // Calculate and return
    return fibonacci_TopDown(num);
}


int main()
{
    int 
        num,
        result;

    printf("Digite um numero para ver o correspondente em Fibonacci:\n");
    scanf("%d", &num);
    
    result = fibonacci_TopDown_inicial(num);

    printf("O resultado eh: %d\n", result);

    for (int i = 0; i < 15; i++)
        printf("[ %ld ] ", vetorFibonacci[i]);

    return 0;
}