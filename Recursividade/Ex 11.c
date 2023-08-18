#include <stdio.h>

/*
11. A multiplicac¸ao de dois n ˜ umeros inteiros pode ser feita atrav ´ es de somas sucessivas. ´
Proponha um algoritmo recursivo Multip Rec(n1,n2) que calcule a multiplicac¸ao de dois ˜
inteiros.
*/
int Multip_Rec(int num1, int num2)
{
    if (num2 > 0)
        return Multip_Rec(num1, num2 - 1) + num1;
        
    return 0;
}

int main()
{
    int num1;
    int num2;
    int answer;

    printf("Enter a number:\n");
    scanf("%d", &num1);

    printf("Enter another number:\n");
    scanf("%d", &num2);

    answer = Multip_Rec(num1, num2);

    printf("[ %d ] x [ %d ] = %d\n", num1, num2, answer);

    return 0;
}