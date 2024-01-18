#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

/*PROGRAMAÇÃO DINÂMICA*/
long resultArray[SIZE];
int position = 1; // The position 0 and 1 already has values

int exponentiation(int num)
{
    // The start value
    resultArray[0] = 2;

    // Get one before because arrays start with 0
    num = num - 1;

    // start in the 'position' (point not calculated yet)
    // Put in 'resultArray[i]' the ( result before * 2 )
    for (int i = position; i <= num; i++)
        resultArray[i] = 2 * resultArray[i - 1];

    // Change the position to start where its not calculated
    if (num > 0)
        position = num;
    
    // Return the result
    return resultArray[num];
    
}


int main()
{
    int
        num,
        result;

    printf("Digite um N para ver 2^N:\n");
    scanf("%d", &num);

    result = exponentiation(num);

    printf("O resultado eh: %d\n", result);

    return 0;
}
