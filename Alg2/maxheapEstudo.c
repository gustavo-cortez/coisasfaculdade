#include <stdio.h>
#include <stdlib.h>

int pai(int i){

    if(i == 0){

        return 0;

    }
    else{

        return (i-1)/2;

    }

}
int esquerdo(int i){

    return 2*(i + 1) - 1;

}
int direito(int i){

    return 2*(i + 1);

}

void troca(int *n, int *nmaior){

    int aux;

    aux = *nmaior;
    *nmaior = *n;
    *n = aux;

}

void desce(int n, int *S, int i){

    int e, d, maior;

    e = esquerdo(i);
    d = direito(i);

    if(e < n && S[e] > S[i]){

        maior = e;

    }
    else{
        maior = i;
    }

    if(d < n && S[d] > S[maior]){

        maior = d;

    }

    if(maior != i){

        troca(&S[i], &S[maior]);
        desce(n, S, maior);

    }
}

void sobe(int n, int *S, int i){

    while(S[pai(i) < S[i]]){

        troca(&S[i], &S[pai(i)]);
        i = pai(i);

    }

}

void constroi_max_heap(int n, int *S){

    int i;
    for(i = n/2 - 1; i >= 0; i--){

        desce(n,S,i);

    }

}
void heapsort ( int n , int *S)
{
    int i, aux;
    aux = n;
    constroi_max_heap(n, S);
    for( i = aux - 1; i > 0; i--){
        troca(&S[0] , &S[i]);
        aux--;
        desce(aux , S, 0);
    }
}

int main(void){

    int *v, n, i;

    printf("Informe o tamanho de N:\n");
    scanf("%d", &n);

    v = (int *)malloc(n *sizeof(int));

    for(i = 0; i < n; i++){

        scanf("%d", &v[i]);

    }

    printf("\n");
    heapsort(n, v);

    for(i = 0; i < n; i++){

        printf("%d ", v[i]);

    }


    return 0;
}