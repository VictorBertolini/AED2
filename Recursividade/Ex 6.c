#include <stdio.h>
/*
6. Crie um programa em C, que contenha uma func¸ao recursiva que receba dois inteiros ˜
positivos k e n e calcule k n
. Utilize apenas multiplicac¸oes. O programa principal deve ˜
solicitar ao usuario os valores de k e n e imprimir o resultado da chamada da func¸ ´ ao.
*/

int recursiveExp(int k, int n)
{
    if (n > 0)
        return k * recursiveExp(k, n - 1);
    
    return 1;
}

int main()
{
    int 
        k,
        n,
        answer;

    printf("Enter a number for K:\n");
    scanf("%d", &k);

    printf("Enter a number for N:\n");
    scanf("%d", &n);

    answer = recursiveExp(k, n);

    printf("The result is: %d\n", answer);
    return 0;
}