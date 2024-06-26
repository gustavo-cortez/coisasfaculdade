#include <stdio.h>

int main()
{
    int n, i, soma,aux;
    printf("Informe um número:");
    scanf("%d", &n);
    
    aux = n * 2;
    soma = 0;
    
    for (i = 1; i < aux; i = i + 1)
    {
        if(i % 2 != 0)
        {
            soma = soma + i;
        }
    }
    printf("O quadrado é:%d", soma);
    
    
    return 0;
}