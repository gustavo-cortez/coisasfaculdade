#include<stdio.h>

int main(void)
{
 
    int di, hi, mi, si, df, hf, mf, sf, dc, hc, mc, sc, inicio, final, tempo_do_evento;/*c é de conclusivo*/

    scanf("%d %dh %dm %ds", &di, &hi, &mi, &si);
    inicio=hi*(60*60)+(mi*60)+si; /*inicio será o primeiro horario que sera inserido*/
 
    scanf(" %d %dh %dm %ds", &df, &hf, &mf, &sf);
    final=hf*(60*60)+(mf*60)+sf; /*final será o ultimo horario que sera inserido*/
 
    if (final>inicio){
        tempo_do_evento=final-inicio;     /*caso final seja maior que inicio da a se entender que, 1 dia foi passado*/
    }
  
    if (final==inicio){
        tempo_do_evento=0;
    }

    dc=df-di;
    hc=tempo_do_evento%(60*60)/(60*60);
    mc=tempo_do_evento%(60*60)%60;
    sc= tempo_do_evento% 60;
     
    printf("%dd%dh%dm%ds", dc, hc, mc, sc);
    return 0;
 }