#include <stdio.h>

/*
16. A func¸ao fatorial duplo ˜ e definida como o produto de todos os n ´ umeros naturais ´ ´ımpares
de 1 ate algum n ´ umero natural ´ ´ımpar N. Assim, o fatorial duplo de 5 e´
5!! = 1 ∗ 3 ∗ 5 = 15
1
Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo impar N e retorne o ´
fatorial duplo desse numero
*/

int doubleFatorial(int num, int jump)
{
    if (jump <= num)
        return doubleFatorial(num, jump + 2) * jump;
    
    return 1;
}

int main()
{   
    int num;
    int answer;

    printf("Enter a number to see X!!:\n");
    scanf("%d", &num);

    answer = doubleFatorial(num, 1);

    printf("The result is: %d\n", answer);

    return 0;
}