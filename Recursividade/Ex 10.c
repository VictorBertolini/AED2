#include <stdio.h>

/*
10. Escreva uma func¸ao recursiva que determine quantas vezes um d ˜ ´ıgito K ocorre em um
numero natural N. Por exemplo, o d ´ ´ıgito 2 ocorre 3 vezes em 762021192.
*/

int recursiveSearch(int num, int search)
{
    if (num != 0)
    {
        if (num % 10 == search)
            return recursiveSearch(num / 10, search) + 1;
        
        return recursiveSearch(num / 10, search);
    }
    
    return 0;
}

int main()
{   
    int num;
    int search;
    int answer;

    printf("Enter a number:\n");
    scanf("%d", &num);

    printf("Enter a number to search:\n");
    scanf("%d", &search);

    answer = recursiveSearch(num, search);

    printf("The result is: %d\n", answer);

    return 0;
}