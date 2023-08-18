//1. Fac¸a uma func¸ao recursiva que calcule e retorne o fatorial de um n ˜ umero inteiro N
#include <stdio.h>

int factorial(int num)
{
    if (num != 1)
        return num * factorial(num - 1);
    return 1;
}

int 
main()
{
    int num;
    int answer;

    printf("Enter the number to calculate the factorial: ");
    scanf("%d", &num);

    answer = factorial(num);

    printf("\nThe result is: %d\n", answer);

    return 0;
}