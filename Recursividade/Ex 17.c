#include <stdio.h>

/*
17. O fatorial quadruplo de um n ´ umero N ´ e dado por: ´
(2n)!
n!
Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo N e retorne o fatorial ´
quadruplo desse n ´ umero. 
*/
int fatorial(int num)
{
    if (num > 1)
        return fatorial(num - 1) * num;    
    return 1;
}

int quadrupleFatorial(int num)
{
    return fatorial(2 * num) / fatorial(num);
}

int main()
{
    int num;
    int answer;

    printf("Enter a number to see the quadruple fatorial:\n");
    scanf("%d", &num);

    answer = quadrupleFatorial(num);

    printf("The result is: %d\n", answer);

    return 0;
}