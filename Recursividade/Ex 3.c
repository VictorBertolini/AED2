//3. Fac¸a uma func¸ao recursiva que permita inverter um n ˜ umero inteiro N. Ex: 123 - 321
#include <stdio.h>
#include <string.h>


void invert(int num)
{
    if (num > 0)
    {
        printf("%d", num % 10);
        return invert(num / 10);
    }
}

int main()
{
    int num;

    printf("Enter the number to invert: ");
    scanf("%d", &num);

    invert(num);

    return 0;
}