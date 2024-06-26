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


void identificarPosicao(struct Ponto *ponto) {
    if (ponto->x == 0 && ponto->y == 0) {
        printf("Coordenadas do ponto: (%.2f, %.2f) na origem.\n", ponto->x, ponto->y);
        ponto->quadrante = 0;
    } else if (ponto->x == 0) {
        printf("Coordenadas do ponto: (%.2f, %.2f) X está na origem.\n", ponto->x, ponto->y);
        ponto->quadrante = 0;
    } else if (ponto->y == 0) {
        printf("Coordenadas do ponto: (%.2f, %.2f) Y está na origem.\n", ponto->x, ponto->y);
        ponto->quadrante = 0;
    } else if (ponto->x > 0 && ponto->y > 0) {
        ponto->quadrante = 1;
    } else if (ponto->x < 0 && ponto->y > 0) {
        ponto->quadrante = 2;
    } else if (ponto->x < 0 && ponto->y < 0) {
        ponto->quadrante = 3;
    } else if (ponto->x > 0 && ponto->y < 0) {
        ponto->quadrante = 4;
    }
}
int main(void){
    
    struct PontoCart ponto;
    
    leituraponto(&ponto);
    identificarPosicao(&ponto);

    if(ponto.quadrante != 0){
        
        printf("Coordenadas do ponto: (%.2f, %.2f) no %d° quadrante.\n", ponto.x, ponto.y, ponto.quadrante);
        
    }
    
    return 0;
}
