#include <stdio.h>
// 5. Crie uma func¸ao recursiva que receba um n ˜ umero inteiro positivo N e calcule o somat ´ orio ´
// dos numeros de 1 a N. 

int recursiveSum(int num)
{
    if (num > 0)
        return recursiveSum(num - 1) + num;
    return 0;
}

int main()
{
    int num;
    int answer;

    printf("Enter a number to calculate the sum of the numbers ultil it:\n");
    scanf("%d", &num);

    answer = recursiveSum(num);

    printf("The result is: [ %d ]\n", answer);
    return 0;
}