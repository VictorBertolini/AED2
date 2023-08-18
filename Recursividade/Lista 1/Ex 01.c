#include <stdio.h>
//Implemente uma função recursiva para calcular o valorde 2n

/// @author Victor Bertolini de Sousa
/// @number: 12211BCC050 

int twoPowN(int n)
{
    //Do recursive calls until N reach to 0
    if (n > 0)
        return twoPowN(--n) * 2;
    
    // When 0 reach 0, so return 1
    return 1;    
}

int main()
{
    int num;
    int answer;

    printf("Enter a number to calculate 2^n:\n");
    scanf("%d", &num);

    answer = twoPowN(num);

    printf("The result is: %d\n", answer);

    return 0;
}