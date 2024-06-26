#include <stdio.h>
#include <stdlib.h>

struct lst{

    int num;
    struct lst *prox;

};
typedef struct lst lista;

int vazio(lista* topo) {
    return (topo == NULL);
}

lista* criaPilha(char item) {
    lista* novaPilha = (lista*)malloc(sizeof(lista));
    novaPilha->num = item;
    novaPilha->prox = NULL;
    return novaPilha;
}

void add_elemento(int n, lista **lst)
{
    lista *nova, *p, *item;
    item = *lst;
    p = NULL;
    nova = (lista *) malloc( sizeof(lista));
    if(nova != NULL)
    {
        nova->num = n;
        if(*lst != NULL)
        {
            item = *lst;
            while(item != NULL)
            {
                p = item;
                item = p->prox;
            }
            p->prox = nova;      
            nova->prox = NULL;
        }
        else
        {
           *lst = nova;
            nova->prox = NULL; 
        }
    }
}

lista* concatena(lista** lst1, lista** lst2){

    lista *r, *aux;
    r = NULL;

    while(!vazio(*lst1) && !vazio(*lst2)){
        if((*lst1)->num < (*lst2)->num){

            add_elemento((*lst1)->num, &r);
            aux = *lst1;
            *lst1 = (*lst1)->prox;
            free(aux);

        }else{

            add_elemento((*lst2)->num, &r);
            aux = *lst2;
            *lst2 = (*lst2)->prox;
            free(aux);
        }
    }
    if(!vazio(*lst1)){
        while(!vazio(*lst1)){
            add_elemento((*lst1)->num, &r);
            aux = *lst1;
            *lst1 = (*lst1)->prox;
            free(aux);
        }
    }
    else if(!vazio(*lst2)){
        while(!vazio(*lst2)){
            add_elemento((*lst2)->num, &r);
            aux = *lst2;
            *lst2 = (*lst2)->prox;
            free(aux);
        }
    }
    return r;
}

void imprimir_lista(lista *r)
{
    lista *p;
    for(p = r; p != NULL; p = p->prox)
    {
        printf("%d ", p->num);
    }
    printf("\n");
}
int main(void) {
    lista *lst1 = NULL;
    lista *lst2 = NULL;
    lista *r = NULL;
    int n, m, e, i;

    printf("Digite o tamanho da primeira Lista: ", n);
    scanf("%d", &n);
    printf("Digite o tamanho da segunda Lista: ", m);
    scanf("%d", &m);

    printf("Digite os %d número da primeira Lista: ", n);
    for(i = 1; i<=n ; i = i + 1)
    {
        scanf("%d", &e);
        add_elemento(e, &lst1);  
    }
    printf("Digite os %d número da segunda Lista: ", m);
    for(i = 1; i<=m ; i = i + 1)
    {
        scanf("%d", &e);
        add_elemento(e, &lst2);  
    }

    printf("Lista 1: \n");
    imprimir_lista(lst1);
    printf("Lista 2: \n");
    imprimir_lista(lst2);

    r = concatena(&lst1, &lst2);

    printf("Lista R: \n");
    imprimir_lista(r);
    free(r);
    free(lst1);
    free(lst2);
    return 0;
}