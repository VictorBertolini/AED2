/*2. Fac¸a uma func¸ao recursiva que calcule e retorne o N-esimo termo da sequencia Fibonacci.
Alguns numeros desta sequ ´ encia s ˆ ao: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89... */

#include <stdio.h>

int fibonacci(int num)
{
    if (num == 1 || num == 2)
        return 1;
    
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int 
main()
{
    int num;
    int answer;

    printf("Enter the number to calculate the fibonacci: ");
    scanf("%d", &num);

    answer = fibonacci(num);

    printf("\nThe result is: %d\n", answer);

    return 0;
}