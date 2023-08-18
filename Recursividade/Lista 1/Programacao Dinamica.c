#include <stdio.h>

long long f[40];
int pos = 2;
long long fb(int n) 
{
    f[0] = 1; 
    f[1] = 1;
    int i;
    for (i = pos; i <= n; i++) 
        f[i] = f[i-2] + f[i-1];

    if (n > 1)
        pos = n;
    
    // guarda até onde já calculou 
    return f[n];
}

int main() 
{
    int i;
    for (i = 0; i < 40; i++)
        printf("%lld ",fb(i));
    
    return 0;
}