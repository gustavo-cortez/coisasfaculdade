/******************************************
* *
* Nome: Gustavo Cortez de Paula
* Trabalho Prático *
* Disciplina: Algortimos e Programação II *
* Professores: Ivone, Mauro e Ronaldo *
* *
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estrutura de dados para representar um produto*/
struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    struct Produto *prox;
};

typedef struct Produto Produto;

/*Função para inserir um novo produto na lista*/
void inserir(Produto **listaProd, int codigo, const char *nome, int quantidade, float preco) {
    int veri;
    Produto *atual;
    Produto *novoProduto;
    /*Verificação se já existe um produto com o mesmo código*/
    atual = *listaProd;
    veri = 0;
    while (atual != NULL && veri != 1) {
        if (atual->codigo == codigo) {
            printf("Erro ao inserir o produto %d.\n", codigo);
            veri = 1;
        }
        else{
            atual = atual->prox;
        } 
    }
    if(veri == 0){
        novoProduto = (Produto *)malloc(sizeof(Produto));
        if (novoProduto == NULL) {
            printf("Erro ao alocar memória para o novo produto.\n");
        }
        else{
            novoProduto->codigo = codigo;
            strcpy(novoProduto->nome, nome);
            novoProduto->quantidade = quantidade;
            novoProduto->preco = preco;
            novoProduto->prox = NULL;

            if (*listaProd == NULL) {
                *listaProd = novoProduto;
            } else {
                atual = *listaProd;
                while (atual->prox != NULL) {
                    atual = atual->prox;
                }
                atual->prox = novoProduto;
            }
            printf("Produto %d inserido com sucesso!\n", codigo);
        }
    }
}

/*Função para excluir um produto da lista*/
void excluir(Produto **listaProd, int codigo) {
    Produto *anterior;
    Produto *atual;
    if (*listaProd == NULL) {
        printf("Produto %d não cadastrado!\n", codigo);
    }
    else{

        atual = *listaProd;
        anterior = NULL;

        while (atual != NULL && atual->codigo != codigo) {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == NULL) {    
            printf("Produto %d não cadastrado!\n", codigo);
        } else {
            if (anterior == NULL) {
                *listaProd = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Produto %d excluído com sucesso!\n", codigo);
        }
    }
}

/*Função para atualizar a quantidade ou o preço de um produto*/
void atualizar(Produto *listaProd, int codigo, char *opcao, float novoValor) {
    Produto *atual = listaProd;

    while (atual != NULL && atual->codigo != codigo) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto %d não cadastrado.\n", codigo);
    }
    else{

        if (strcmp(opcao, "-q") == 0) {
            atual->quantidade = novoValor;
            printf("Produto %d atualizado!\n", codigo);
        } else if (strcmp(opcao, "-v") == 0) {
            atual->preco = novoValor;
            printf("Produto %d atualizado!\n", codigo);
        } else {
            printf("Opção inválida.\n");
        }

    }
}

/*Função para consultar produtos com base em uma sequência de caracteres na descrição*/
void consultar(Produto *listaProd, const char *sequencia) {
    Produto *atual = listaProd;
    int encontrados = 0;

    while (atual != NULL) {
        if (strstr(atual->nome, sequencia) != NULL) {
            printf("%d - %s - %d - %.2f\n", atual->codigo, atual->nome, atual->quantidade, atual->preco);
            encontrados = 1;
        }
        atual = atual->prox;
    }

    if (!encontrados) {
        printf("Nenhum produto encontrado!\n");
    }
}

/*Função para salvar a lista de produtos em um arquivo*/
void salvarProdutos(Produto *listaProd) {
    int quantidade;
    Produto *atual;
    FILE *arquivo = fopen("Produtos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Produtos.dat para escrita.\n");
    }
    else{
        quantidade = 0;
        atual = listaProd;
        while (atual != NULL) {
            quantidade++;
            atual = atual->prox;
        }

        fwrite(&quantidade, sizeof(int), 1, arquivo);
        atual = listaProd;
        while (atual != NULL) {
            fwrite(atual, sizeof(Produto), 1, arquivo);
            atual = atual->prox;
        }

    }
    fclose(arquivo);
}

/*Função para carregar a lista de produtos a partir de um arquivo*/
void carregarProdutos(Produto **listaProd) {
    int quantidade, i, veri;
    veri = 0;
    Produto *novoProduto;
    Produto *atual;
    FILE *arquivo = fopen("Produtos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao importar do arquivo Produtos.dat.\n");
    }
    else{

        fread(&quantidade, sizeof(int), 1, arquivo);

        while(i < quantidade && veri != 1) {
            novoProduto = (Produto *)malloc(sizeof(Produto));
            if (novoProduto == NULL) {
                printf("Erro ao alocar memória para os produtos.\n");
                veri = 1;
            }
            else{
                fread(novoProduto, sizeof(Produto), 1, arquivo);
                novoProduto->prox = NULL;

                if (*listaProd == NULL) {
                    *listaProd = novoProduto;
                } else {
                    atual = *listaProd;
                    while (atual->prox != NULL) {
                        atual = atual->prox;
                    }
                    atual->prox = novoProduto;
                }
                i++;
            }
        }
        fclose(arquivo);
    }

}
/*Função para importar produtos de um arquivo de texto*/
void importarProdutos(Produto **listaProd, const char *nomeArquivo) {
    int quantidade, i, impo, produtoExiste, veri;
    Produto *novoProduto;
    Produto *atual;
    FILE *arquivo = fopen(nomeArquivo, "r");
    veri = 0;
    i = 0;
    if (arquivo == NULL) {
        printf("Erro ao importar do arquivo %s.\n", nomeArquivo);
    }
    else{
        fscanf(arquivo, "%d", &quantidade);
        impo = quantidade;
        while(i < quantidade && veri != 1){
            novoProduto = (Produto *)malloc(sizeof(Produto));
            if (novoProduto == NULL) {
                printf("Erro ao alocar memória para os produtos.\n");
                veri = 1;
            }
            else{
                fscanf(arquivo, "%d;%[^;];%d;%f", &novoProduto->codigo, novoProduto->nome, &novoProduto->quantidade, &novoProduto->preco);
                novoProduto->prox = NULL;

                atual = *listaProd;
                produtoExiste = 0;

                while (atual != NULL && !produtoExiste) {
                    if (atual->codigo == novoProduto->codigo) {
                        produtoExiste = 1;
                        impo = impo - 1;
                        free(novoProduto);
                    }
                    atual = atual->prox;
                }

                if (!produtoExiste) {
                    if (*listaProd == NULL) {
                        *listaProd = novoProduto;
                    } else {
                        atual = *listaProd;
                        while (atual->prox != NULL) {
                            atual = atual->prox;
                        }
                        atual->prox = novoProduto;
                    }
                }
            }
            i++;
        }
        if(veri != 1){
            printf("%d produtos importados!\n", impo);
        }  
        fclose(arquivo); 
    }
}

/*Função para realizar o registro de venda*/
void registrarVenda(Produto *listaProd) {
    int codigo, totalProdutos, para, produtoEncontrado;
    float totalVenda = 0.0;
    Produto *atual;
    totalProdutos = 0;
    para = 1;
    while (para == 1) {
        
        scanf("%d", &codigo);

        if (codigo != 0){
                
            atual = listaProd;
            produtoEncontrado = 0;

            while (atual != NULL) {
                if (atual->codigo == codigo) {
                    produtoEncontrado = 1;

                    if (atual->quantidade > 0) {
                        totalProdutos++;
                        totalVenda += atual->preco;

                        printf("%d - %s - %.2f\n", atual->codigo, atual->nome, atual->preco);
                        atual->quantidade--;
                    } else {
                        printf("%d - %s - produto em falta no estoque\n", atual->codigo, atual->nome);
                    }
                }

                atual = atual->prox;
            }

            if (!produtoEncontrado) {
                printf("%d - produto não cadastrado\n", codigo);
            }
        }
        else{  
            para = 0;
        }
    }

    printf("---------\nTotal %.2f\n", totalVenda);
}

void listarProdutosBaixosEstoque(Produto *listaProd) {
    int veri, cod, quant, trocou;
    char nome[50];
    float valor;
    Produto *listaBaixa = NULL;
    Produto *atual = listaProd;
    Produto *ProdOrdem;
    Produto *atualAux; 
    Produto *aux;
    Produto *proximo;
    Produto *anterior;
    FILE *arquivo = fopen("Comprar.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Comprar.txt para escrita.\n");
    }
    else{
        veri = 0;
        while (atual != NULL && veri != 1) {
            if (atual->quantidade < 15) {
                ProdOrdem = (Produto *)malloc(sizeof(Produto));
                if (ProdOrdem == NULL) {
                    printf("Erro de alocação de memória.\n");
                    veri = 1;
                }
                else{
                    *ProdOrdem = *atual;
                    ProdOrdem->prox = listaBaixa;
                    listaBaixa = ProdOrdem;
                }
            }
            if(veri != 1){
                atual = atual->prox;
            }
        }
        if(veri != 1){
            atualAux = NULL; 

            do {
                trocou = 0;
                atualAux = listaBaixa;
                anterior = NULL;

                while (atualAux != NULL && atualAux->prox != NULL) {
                    if (atualAux->quantidade > atualAux->prox->quantidade) {
                        if (anterior == NULL) {
                            listaBaixa = atualAux->prox;
                        } else {
                            anterior->prox = atualAux->prox;
                        }
                        aux = atualAux->prox->prox;
                        atualAux->prox->prox = atualAux;
                        atualAux->prox = aux;
                        trocou = 1;
                    }

                    anterior = atualAux;
                    atualAux = atualAux->prox;
                }
            } while (trocou);

            if(veri != 1){
                proximo = listaBaixa;

                while (proximo != NULL) {
                    printf("%d - %s - %d\n", proximo->codigo, proximo->nome, proximo->quantidade);
                    fprintf(arquivo, "%d - %s - %d\n", proximo->codigo, proximo->nome, proximo->quantidade);

                    anterior = proximo;
                    proximo = proximo->prox;
                    free(anterior);
                }

                if (listaBaixa == NULL) {
                    printf("Nenhum produto com estoque baixo encontrado!\n");
                }
            }
        }
    }
    fclose(arquivo);
}

/*Função para listar produtos em ordem alfabética e salvar em Relatorio.txt*/
void listarProdutosRelatorio(Produto *listaProd) {
    int encontrados, trocou, veri, i, indice;
    char letraInicial;
    Produto *atual;
    Produto *aux;
    Produto *ProdOrdem;
    Produto *atualAux; 
    Produto *anterior;
    Produto *listaPorLetra[26];
    Produto *novoProduto;
    Produto *produtoAtual;
    Produto *produtosInicio;
    FILE *arquivo = fopen("Relatorio.txt", "w");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo Relatorio.txt para escrita.\n");
    }
    else{
        for(i = 0; i < 26; i++) {
            listaPorLetra[i] = NULL;
        }
        atual = listaProd;
        encontrados = 0;
        veri = 0;
        while(atual != NULL) {
            letraInicial = atual->nome[0];

            if(letraInicial >= 'a' && letraInicial <= 'z') {
                letraInicial = letraInicial - 32;
            }

            if(letraInicial >= 'A' && letraInicial <= 'Z') {
                indice = letraInicial - 'A';

                novoProduto = (Produto *)malloc(sizeof(Produto));

                if(novoProduto == NULL) {
                    printf("Erro de alocação de memória.\n");
                    veri = 1;
                }
                else{
                    *novoProduto = *atual;
                    novoProduto->prox = listaPorLetra[indice];
                    listaPorLetra[indice] = novoProduto;
                    encontrados = 1;
                }
            }
            if(veri != 1){
                atual = atual->prox;
            }
        }
        if(veri != 1){
            if(encontrados) {
                for(i = 0; i < 26; i++) {
                    if(listaPorLetra[i] != NULL){
                        produtoAtual = listaPorLetra[i];
                        produtosInicio = NULL; 

                        while(produtoAtual != NULL){
                            novoProduto = (Produto *)malloc(sizeof(Produto));
                            *novoProduto = *produtoAtual;

                            if(produtosInicio == NULL){
                                produtosInicio = novoProduto;
                            }

                            produtoAtual = produtoAtual->prox;
                        }

                        do {
                        trocou = 0;
                        atualAux = produtosInicio;
                        anterior = NULL;

                        while (atualAux != NULL && atualAux->prox != NULL) {
                            if (strcmp(atualAux->nome,atualAux->prox->nome) > 0) {
                                if (anterior == NULL) {
                                    produtosInicio = atualAux->prox;
                                } else {
                                    anterior->prox = atualAux->prox;
                                }
                                aux = atualAux->prox->prox;
                                atualAux->prox->prox = atualAux;
                                atualAux->prox = aux;
                                trocou = 1;
                            }

                            anterior = atualAux;
                            atualAux = atualAux->prox;
                        }
                    } while (trocou);

                        fprintf(arquivo, "%c\n", 'A' + i);
                        printf("%c\n", 'A' + i);

                        ProdOrdem = produtosInicio;
                        while(ProdOrdem != NULL) {
                            printf("%d - %s - %d - %.2f\n", ProdOrdem->codigo, ProdOrdem->nome, ProdOrdem->quantidade, ProdOrdem->preco);
                            fprintf(arquivo, "%d - %s - %d - %.2f\n", ProdOrdem->codigo, ProdOrdem->nome, ProdOrdem->quantidade, ProdOrdem->preco);
                            ProdOrdem = ProdOrdem->prox;
                        }
                    }
                }
            } else {
                printf("Nenhum produto encontrado!\n");
            }

            fclose(arquivo);
        }
    }
}

int main(void){
    char comando[10];
    int codigo, quantidade, sair;
    float preco, novoValor;
    char sequencia[50];
    char opcao[3];
    char nomeArquivo[50];
    Produto *listaProd = NULL;
    Produto *atual;
    Produto *proximo;
    
    /*Produtos do arquivo Produtos.dat*/
    carregarProdutos(&listaProd);

    sair = 0;

    do{
        scanf("%s", comando);

        if(strcmp(comando, "inserir") == 0) {
            scanf("%d %s %d %f", &codigo, nomeArquivo, &quantidade, &preco);
            inserir(&listaProd, codigo, nomeArquivo, quantidade, preco);
        }
        else{
            if (strcmp(comando, "excluir") == 0) {
                scanf("%d", &codigo);
                excluir(&listaProd, codigo);
            }
            else{
                if(strcmp(comando, "atualizar") == 0) {
                    scanf(" %s %d %f", opcao, &codigo, &novoValor);
                    atualizar(listaProd, codigo, opcao, novoValor);
                }
                else{
                    if (strcmp(comando, "consultar") == 0) {
                        scanf("%s", sequencia);
                        consultar(listaProd, sequencia);
                    }
                    else{
                        if (strcmp(comando, "sair") == 0) {
                            listarProdutosBaixosEstoque(listaProd); /*Lista produtos com estoque baixo e salva em Comprar.txt*/
                            salvarProdutos(listaProd); /*Salva produtos no arquivo Produtos.dat*/
                            sair = 1;
                        }
                        else{
                            if (strcmp(comando, "relatorio") == 0) {
                                listarProdutosRelatorio(listaProd); /*Lista produtos no arquivo Relatorio.txt*/
                            }
                            else{
                                if (strcmp(comando, "vender") == 0) {
                                    registrarVenda(listaProd);
                                }
                                else{
                                    if (strcmp(comando, "importar") == 0) {
                                    scanf("%s", sequencia);
                                    importarProdutos(&listaProd, sequencia);
                                    }
                                    else{
                                        if (strcmp(comando, "help") == 0) {
                                            printf("Optei pela lista encadeada simples sem cabeça pelo simples fato de ser mais intuitivo usar ponteiro auxiliares para andar ao invés de usar uma duplamente encadeada e também pelo fato de dar errado quando tentei usar a com cabeça. Usei Bubble Sort nos algoritmos de ordenação, visto que um metódo simples que vai trocando até estar certo. Há vários comentários no código para que possa facilitar a minha vida e a dos professores que estão corrigindo!\n");
                                        }
                                        else{
                                            printf("Comando inválido.\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(sair != 1);

    atual = listaProd;
    while(atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}