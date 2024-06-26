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

// Estrutura de dados para representar um produto
struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    struct Produto *prox;
};

typedef struct Produto Produto;

// Função para inserir um novo produto na lista
void inserir(Produto **listaProd, int codigo, const char *nome, int quantidade, float preco) {
    // Verifique se já existe um produto com o mesmo código
    Produto *atual = *listaProd;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("Erro ao inserir o produto %d.\nProduto com código %d já existe na lista. Não é possível inserir.\n", codigo, codigo);
            return;
        }
        atual = atual->prox;
    }

    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro ao alocar memória para o novo produto.\n");
        return;
    }

    novoProduto->codigo = codigo;
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->preco = preco;
    novoProduto->prox = NULL;

    if (*listaProd == NULL) {
        *listaProd = novoProduto;
    } else {
        Produto *atual = *listaProd;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoProduto;
    }
    printf("Produto %d inserido com sucesso!\n", codigo);
}


// Função para excluir um produto da lista
void excluir(Produto **listaProd, int codigo) {
    if (*listaProd == NULL) {
        printf("Produto %d não cadastrado!\n", codigo);
        return;
    }

    Produto *atual = *listaProd;
    Produto *anterior = NULL;

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

// Função para atualizar um produto
void atualizar(Produto *listaProd, int codigo, char opcao, float novoValor) {
    Produto *atual = listaProd;

    while (atual != NULL && atual->codigo != codigo) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto %d não cadastrado.\n");
        return;
    }

    if (opcao == 'q') {
        atual->quantidade = novoValor;
    } else if (opcao == 'v') {
        atual->preco = novoValor;
    } else {
        printf("Opção inválida.\n");
        return;
    }

    printf("Produto %d atualizado!\n", codigo);
}

// Função para consultar produtos com base em uma sequência de caracteres na descrição
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

// Função para salvar a lista de produtos em um arquivo
void salvarProdutos(Produto *listaProd) {
    int quantidade;
    FILE *arquivo = fopen("Produtos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Produtos.dat para escrita.\n");
        return;
    }

    quantidade = 0;
    Produto *atual = listaProd;
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

    fclose(arquivo);
}

// Função para carregar a lista de produtos a partir de um arquivo
void carregarProdutos(Produto **listaProd) {
    int quantidade, i;
    FILE *arquivo = fopen("Produtos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao importar do arquivo Produtos.dat.\n");
        return;
    }

    fread(&quantidade, sizeof(int), 1, arquivo);

    for (i = 0; i < quantidade; i++) {
        Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
        if (novoProduto == NULL) {
            printf("Erro ao alocar memória para os produtos.\n");
            return;
        }

        fread(novoProduto, sizeof(Produto), 1, arquivo);
        novoProduto->prox = NULL;

        if (*listaProd == NULL) {
            *listaProd = novoProduto;
        } else {
            Produto *atual = *listaProd;
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novoProduto;
        }
    }

    fclose(arquivo);
}
// Função para importar produtos de um arquivo de texto
void importarProdutos(Produto **listaProd, const char *nomeArquivo) {
    int quantidade, i;
    FILE *arquivo = fopen(nomeArquivo, "r"); // Abre o arquivo de texto para leitura

    if (arquivo == NULL) {
        printf("Falha: Erro ao importar do arquivo %s.\n", nomeArquivo);
        return;
    }

    // Lê a quantidade de produtos no arquivo
    fscanf(arquivo, "%d", &quantidade);

    for (i = 0; i < quantidade; i++) {
        Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
        if (novoProduto == NULL) {
            printf("Erro ao alocar memória para os produtos.\n");
            return;
        }

        // Lê os dados do produto do arquivo
        fscanf(arquivo, "%d;%[^;];%d;%f", &novoProduto->codigo, novoProduto->nome, &novoProduto->quantidade, &novoProduto->preco);
        novoProduto->prox = NULL;

        if (*listaProd == NULL) {
            *listaProd = novoProduto;
        } else {
            Produto *atual = *listaProd;
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novoProduto;
        }
    }

    fclose(arquivo);
    printf("Sucesso: %d produtos importados!\n", quantidade);
}


// Função para realizar o registro de venda
void registrarVenda(Produto *listaProd) {
    int codigo, totalProdutos, para, produtoEncontrado;
    float totalVenda = 0.0;

    totalProdutos = 0;
    para = 1;
    while (para == 1) {
        
        scanf("%d", &codigo);

        if (codigo != 0){
                
            Produto *atual = listaProd;
            Produto *anterior = NULL;
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

                anterior = atual;
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
    int encontrados;
    FILE *arquivo = fopen("Comprar.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Comprar.txt para escrita.\n");
        return;
    }

    Produto *atual = listaProd;
    encontrados = 0;

    while (atual != NULL) {
        if (atual->quantidade < 15) {
            printf("%d - %s - %d\n", atual->codigo, atual->nome, atual->quantidade);
            fprintf(arquivo, "%d - %s - %d\n", atual->codigo, atual->nome, atual->quantidade);
            encontrados = 1;
        }
        atual = atual->prox;
    }

    fclose(arquivo);

    if (!encontrados) {
        printf("Nenhum produto com estoque baixo encontrado!\n");
    }
}

// Função para listar produtos em ordem alfabética e salvar em Relatorio.txt
void listarProdutosRelatorio(Produto *listaProd) {
    int encontrados, letraInicial, i;
    FILE *arquivo = fopen("Relatorio.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Relatorio.txt para escrita.\n");
        return;
    }

    Produto *atual = listaProd;
    encontrados = 0;

    // Listas produtos por letra inicial
    Produto *listaPorLetra[26];
    for (i = 0; i < 26; i++) {
        listaPorLetra[i] = NULL;
    }

    while (atual != NULL) {
        letraInicial = atual->nome[0] - 'a';
        if (letraInicial >= 0 && letraInicial < 26) {
            Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
            if (novoProduto == NULL) {
                printf("Erro ao alocar memória para produtos.\n");
                return;
            }
            *novoProduto = *atual;
            novoProduto->prox = listaPorLetra[letraInicial];
            listaPorLetra[letraInicial] = novoProduto;
            encontrados = 1;
        }
        atual = atual->prox;
    }

    for (i = 0; i < 26; i++) {
        if (listaPorLetra[i] != NULL) {
            fprintf(arquivo, "%c\n", 'A' + i);
            printf("%c\n", 'A' + i);
            Produto *produtoAtual = listaPorLetra[i];
            while (produtoAtual != NULL) {
                printf("%d - %s - %d - %.2f\n", produtoAtual->codigo, produtoAtual->nome, produtoAtual->quantidade, produtoAtual->preco);
                fprintf(arquivo, "%d - %s - %d - %.2f\n", produtoAtual->codigo, produtoAtual->nome, produtoAtual->quantidade, produtoAtual->preco);
                Produto *aux = produtoAtual;
                produtoAtual = produtoAtual->prox;
                free(aux);
            }
        }
    }

    fclose(arquivo);

    if (!encontrados) {
        printf("Nenhum produto encontrado!\n");
    }
}

int main() {
    char comando[10];
    int codigo, quantidade, sair;
    float preco, novoValor;
    char sequencia[50];
    char opcao;
    char nomeArquivo[50];
    Produto *listaProd = NULL;

    // Produtos do arquivo Produtos.dat
    carregarProdutos(&listaProd);

    sair = 0;

    do {
        printf("Digite um comando (inserir, excluir, atualizar, consultar, vender, sair, ou relatorio): ");
        scanf("%s", comando);

        if (strcmp(comando, "inserir") == 0) {
            scanf("%d %s %d %f", &codigo, nomeArquivo, &quantidade, &preco);
            inserir(&listaProd, codigo, nomeArquivo, quantidade, preco);
        } else if (strcmp(comando, "excluir") == 0) {
            scanf("%d", &codigo);
            excluir(&listaProd, codigo);
        } else if (strcmp(comando, "atualizar") == 0) {
            scanf(" %c %d %f", &opcao, &codigo, &novoValor);
            atualizar(listaProd, codigo, opcao, novoValor);
        } else if (strcmp(comando, "consultar") == 0) {
            scanf("%s", sequencia);
            consultar(listaProd, sequencia);
        } else if (strcmp(comando, "sair") == 0) {
            listarProdutosBaixosEstoque(listaProd); // Lista produtos com estoque baixo e salva em Comprar.txt
            salvarProdutos(listaProd); // Salva produtos no arquivo Produtos.dat
            sair = 1;
        } else if (strcmp(comando, "relatorio") == 0) {
            listarProdutosRelatorio(listaProd); // Lista produtos no arquivo Relatorio.txt
        } else if (strcmp(comando, "vender") == 0) {
            registrarVenda(listaProd);
        } else if (strcmp(comando, "importar") == 0) {
            scanf("%s", sequencia);
            importarProdutos(&listaProd, sequencia);
        }else {
            printf("Comando inválido.\n");
        }
    } while (sair != 1);

    Produto *atual = listaProd;
    while (atual != NULL) {
        Produto *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}


