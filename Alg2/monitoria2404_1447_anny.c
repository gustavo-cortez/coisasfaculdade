#include <stdio.h>
int main (void)
{
    int n, i, id, p, soma, pali, a, cont, b, c, primo, inv;
    scanf ("%d", &n);
    soma = 0;
    while (n != 0){
        p = 1;
        i = 1;
        while (i < n){
            id = n % i;
            if (id == 0){
                p = p + 1;
            }
            i++;
            if (p == 2 ){
                primo = n;
            }
            
        }
        for (cont = n; cont > 0; cont = cont / 10) {
            a = cont % 10;
            soma = soma + a;
        }
        inv = 0;
        pali = 0;
        for (c = n; c > 0; c = c / 10) {
            b = c % 10;
            inv = (inv * 10) + b;
        }
          if (n == inv){  
            pali = n;
        }
        if (primo == n && pali == n){
            printf ("%d\n", n);
        }
       scanf ("%d", &n);  
    }
    printf ("%d", soma);
    return 0;
}