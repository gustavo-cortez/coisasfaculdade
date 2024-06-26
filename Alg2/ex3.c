#include <stdio.h>

struct PontoCart{
    float x;
    float y;
	int quadrante;
};

void leituraponto(struct PontoCart *ponto){    
    scanf("%f", &ponto->x);
    scanf("%f", &ponto->y);    
}
