#include <stdio.h>
int main (void)
{
    char nome[11];
    int idade;
    float salbruto, salreaj, grat, total, saliq, saldesc;
   
    scanf ("%10s", nome);
   
    scanf ("%d", &idade);

    scanf ("%f", &salbruto);
   
    salreaj = (salbruto * 0.38 + salbruto);
    grat = (salreaj * 0.2);
    total= (salreaj + grat);
    saldesc= (total /100*15);
    saliq = (total - saldesc);
   
    printf ("%.10s\n", nome);
    printf ("%d\n", idade);
    printf ("%f\n", salreaj);
    printf ("%f\n", saliq);
   
   
    return 0;
}