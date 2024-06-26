#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *v, int n) {
    int comparacoes, trocas, aux, i , j, *vord;
    vord = (int *)malloc(n * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    for(i = 0; i < n; i++){

        vord[i] = v[i];

    } 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (vord[j] > vord[j + 1]) {
                aux = vord[j];
                vord[j] = vord[j + 1];
                vord[j + 1] = aux;
                trocas++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", vord[i]);
    }
    printf("\nbubble sort: %d %d\n", comparacoes, trocas);
    free(vord);
}

void insertionsort(int *v, int n) {
    int comparacoes, trocas, chave, i, j, *vord;
    vord = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++){

        vord[i] = v[i];

    } 
    trocas = 0;
    comparacoes = 0;
    for (i = 1; i < n; i++) {
        chave = vord[i];
        j = i - 1;
        comparacoes++;
        while (j >= 0 && vord[j] > chave) {
            vord[j + 1] = vord[j];
            j--;
            trocas++;
            comparacoes++;
        }
        vord[j + 1] = chave;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", vord[i]);
    }
    printf("\ninsertion sort: %d %d\n", comparacoes, trocas);
    free(vord);
}

void selectionsort(int *v, int n) {
    int comparacoes, trocas, aux, i, j, iaux, *vord;
    vord = (int *)malloc(n * sizeof(int));
    comparacoes = 0;
    trocas = 0;
    for(i = 0; i < n; i++){

        vord[i] = v[i];

    } 
    for (i = 0; i < n - 1; i++) {
        iaux = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;
            if (vord[j] <= vord[iaux]) {
                iaux = j;
            }
        }
        if (iaux != i) {
            aux = vord[i];
            vord[i] = vord[iaux];
            vord[iaux] = aux;
            trocas++;
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", vord[i]);
    }
    printf("\nselection sort: %d %d\n", comparacoes, trocas);
}
int separa(int p, int r, int *v) {
    int pivo, i, j, aux;
    pivo = v[p];
    i = p - 1;
    j = r + 1;
    
    while (1) {
        do {
            j--;
        } while (v[j] > pivo);

        do {
            i++;
        } while (v[i] < pivo);

        if (i < j) {

            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        } else {
            return j;
        }
    }
}
void quicksort(int p, int r, int *v) {
    int q;
    if (p < r) {
        q = separa(p, r, v);
        quicksort(p, q, v);
        quicksort(q + 1, r, v);
    }
}
void intercala(int p, int q, int r, int *v) {
    int i, j, k, *w;
    w = (int *)malloc(r * sizeof(int));
    i = p; 
    j = q; 
    k = 0;
    while (i < q && j < r) {
        if (v[i] < v[j]) {
            w[k] = v[i];
            i++;
        } else {
            w[k] = v[j];
            j++;
        }
        k++;
    }

    while (i < q) {
        w[k] = v[i];
        i++;
        k++;
    }

    while (j < r) {
        w[k] = v[j];
        j++;
        k++;
    }

    for (i = p; i < r; i++) {
        v[i] = w[i - p];
    }
}
void mergesort(int p , int r , int *v){
    int q;
    if( p < r - 1){

        q = ( p + r ) / 2;
        mergesort(p , q , v);
        mergesort(q , r , v);
        intercala(p , q , r , v);
    }
}
int main(void){

	int n, *vetor, i, *vord;
    
    scanf("%d", &n);
    
    vetor = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++){

        scanf("%d", &vetor[i]);
        
    }  

    bubblesort(vetor, n);
    insertionsort(vetor, n);
    selectionsort(vetor , n);
    printf("Mergesort\n");
    vord = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++){

        vord[i] = vetor[i];

    } 
    mergesort(0, n, vord);
    for (i = 0; i < n; i++) {
        printf("%d ", vord[i]);
    }
    printf("\n");
    quicksort(0, n-1, vetor);
    printf("QuickSort\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    free(vetor);
    free(vord);
    return 0;
}