#include <stdio.h>
/*
2) Construa um algoritmo que calcule o fatorial de um número utilizando programação dinâmica.
Compare o resultado obtido com os algoritmos iterativo e recursivo apresentados em aula.
*/

/// @author Victor Bertolini de Sousa
/// @number: 12211BCC050 

int fatorialResults[30];
int position = 1;

int dynamicFatorial(int n)
{
    fatorialResults[0] = 1;

    for (int count = position; count < n; count++)
        fatorialResults[count] = fatorialResults[count - 1] * count;
    
    if (n > 0)
        position = n;
    
    return fatorialResults[n - 1];
}

int main()
{
    int num;

    printf("Enter a number to calculate fatorial:\n");
    scanf("%d", &num);

    for (int count = 1; count <= num; count++)
        printf("[ %d ] ", dynamicFatorial(count));
    
    return 0;
}