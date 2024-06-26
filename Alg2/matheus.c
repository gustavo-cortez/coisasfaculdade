#include <stdio.h>
    int main(void)
{
    int a, b, c, delta;
    float chuteinicialy, parametrodeerro, r1, r2, result, diferent;
    scanf("%d %d %d %f %f", &a, &b, &c, &chuteinicialy, &parametrodeerro);
    delta=(b * b) - (4 * a * c);

    diferent=1+parametrodeerro;
    while(diferent>parametrodeerro)
    {
        result=(chuteinicialy+(delta/chuteinicialy))/2;
        diferent=result-chuteinicialy;
        if(diferent<0)
        {
            diferent=diferent*(-1);
        }
        chuteinicialy=result;
    }

    r1=(-(b)+chuteinicialy)/(a*2);
    r2=(-(b)-chuteinicialy)/(a*2);

    if(delta==0)
    {
        r1=-b/2 * a;
        printf("Há uma raiz real: %.0f\n", r1);
    }
    else
    {
        if(delta>0)
        {
            printf("Há duas raízes reais: %f e %f\n", r1, r2);
        }
        else
        {
            if(delta<0 || a == 0){
                printf("Não há raizes reais.\n");
            }
        }
    }

    return 0;
}