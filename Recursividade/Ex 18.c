#include <stdio.h>

/*
18. O superfatorial de um numero N ´ e definida pelo produto dos N primeiros fatoriais de N. ´
Assim, o superfatorial de 4 e´
sf(4) = 1! ∗ 2! ∗ 3! ∗ 4! = 288
Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo N e retorne o superfa- ´
torial desse numero.
*/
int fatorial(int num)
{
    if (num > 1)
        return fatorial(num - 1) * num;    
    return 1;
}

int hiperFatorial(int num)
{
    
}

int main()
{
    int num;
    int answer;

    printf("Enter a number to see the hiperFatorial:\n");
    scanf("%d", &num);

    answer = hiperFatorial(num);

    printf("The result is: %d\n", answer);

    return 0;
}