#include <stdio.h>

int main(void)
{
    int a, b, c;
    double y, e, x, x1, x2, delta, raiz, raiz1;

    scanf("%d %d %d %lf %lf", &a, &b, &c, &y, &e);
 
    delta = b * b - 4 * a * c;

    if(delta < 0)
    {
        printf("Não há raízes reais.\n");
    }
    else
    {
        double limite = 0.5 * e; // Condição de parada do método da bisseção

        // Método da bisseção para encontrar a raiz
        do
        {
            raiz =  delta / y;
            raiz1 = (y + raiz) / 2;
            y = raiz1;
        }
        while(raiz - raiz1 > limite || raiz1 - raiz > limite);

        // Verifica o tipo de raiz
        if (delta > 0)
        {
            x1 = (-b + raiz1) / (2 * a);
            x2 = (-b - raiz1) / (2 * a);
            printf("Há duas raízes reais: %.6lf e %.6lf\n", x1, x2);
        }
        else if (delta == 0)
        {
            x = -b / (2 * a);
            printf("Há uma raiz real: %.6lf\n", x);
        }
    }

    return 0;
}
