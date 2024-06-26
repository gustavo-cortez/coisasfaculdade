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

Produto *cabeca = NULL; // Ponteiro para o início da lista de produtos

// Função para inserir um novo produto na lista
void inserir(int codigo, const char *nome, int quantidade, float preco) {
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

    if (cabeca == NULL) {
        cabeca = novoProduto;
    } else {
        Produto *atual = cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoProduto;
    }
    printf("Produto %d inserido com sucesso!\n", codigo);
}

// Função para excluir um produto da lista
void excluir(int codigo) {
    if (cabeca == NULL) {
        printf("Produto %d não cadastrado!\n", codigo);
        return;
    }

    Produto *atual = cabeca;
    Produto *anterior = NULL;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto %d não cadastrado!\n", codigo);
    } else {
        if (anterior == NULL) {
            cabeca = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        printf("Produto %d excluido com sucesso!\n", codigo);
    }
}

// Função para atualizar a quantidade ou o preço de um produto
void atualizar(int codigo, char opcao, float novoValor) {
    Produto *atual = cabeca;

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
        printf("Opcao invalida.\n");
        return;
    }

    printf("Produto %d atualizado!\n", codigo);
}

// Função para consultar produtos com base em uma sequência de caracteres na descrição
void consultar(const char *sequencia) {
    Produto *atual = cabeca;
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
void salvarProdutos() {
    FILE *arquivo = fopen("Produtos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Produtos.dat para escrita.\n");
        return;
    }

    int quantidade = 0;
    Produto *atual = cabeca;
    while (atual != NULL) {
        quantidade++;
        atual = atual->prox;
    }

    fwrite(&quantidade, sizeof(int), 1, arquivo);
    atual = cabeca;
    while (atual != NULL) {
        fwrite(atual, sizeof(Produto), 1, arquivo);
        atual = atual->prox;
    }

    fclose(arquivo);
}

// Função para carregar a lista de produtos a partir de um arquivo
void carregarProdutos() {
    FILE *arquivo = fopen("Produtos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao importar do arquivo Produtos.dat.\n");
        return;
    }

    int quantidade;
    fread(&quantidade, sizeof(int), 1, arquivo);

    for (int i = 0; i < quantidade; i++) {
        Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
        if (novoProduto == NULL) {
            printf("Erro ao alocar memória para os produtos.\n");
            return;
        }

        fread(novoProduto, sizeof(Produto), 1, arquivo);
        novoProduto->prox = NULL;

        if (cabeca == NULL) {
            cabeca = novoProduto;
        } else {
            Produto *atual = cabeca;
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novoProduto;
        }
    }

    fclose(arquivo);
}

// Função para realizar o registro de venda
void registrarVenda() {
    int codigo, totalProdutos = 0, para;
    float totalVenda = 0.0;

    para = 1;
    while (para == 1) {
        
        scanf("%d", &codigo);

        if (codigo != 0) {
                
            Produto *atual = cabeca;
            Produto *anterior = NULL;
            int produtoEncontrado = 0;

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
                printf("%d - produto nao cadastrado\n", codigo);
            }
        }
        if (codigo == 0){  

            para = 0;

        }
    }

    printf("---------\nTotal %.2f\n", totalVenda);
}

void listarProdutosBaixosEstoque() {
    FILE *arquivo = fopen("Comprar.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Comprar.txt para escrita.\n");
        return;
    }

    Produto *atual = cabeca;
    int encontrados = 0;

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


int main() {

    Produto itens;
    char comando[10];
    int codigo, quantidade, sair;
    float preco;
    char sequencia[50];
    char opcao;
    char nomeArquivo[50];

    carregarProdutos(); // Carrega produtos a partir do arquivo Produtos.dat

    sair = 0;

    do{
        printf("Digite um comando (inserir, excluir, atualizar, consultar, vender ou sair): ");
        scanf("%s", comando);

        if (strcmp(comando, "inserir") == 0) {
            scanf("%d %s %d %f", &codigo, nomeArquivo, &quantidade, &preco);
            inserir(codigo, nomeArquivo, quantidade, preco);
        } else if (strcmp(comando, "excluir") == 0) {
            scanf("%d", &codigo);
            excluir(codigo);
        } else if (strcmp(comando, "atualizar") == 0) {
            scanf(" %c %d %f", &opcao, &codigo, &preco);
            atualizar(codigo, opcao, preco);
        } else if (strcmp(comando, "consultar") == 0) {
            scanf("%s", sequencia);
            consultar(sequencia);
        }else if (strcmp(comando, "sair") == 0) {
            listarProdutosBaixosEstoque();
            salvarProdutos(); // Salva produtos no arquivo Produtos.dat
            sair = 1;
        }else if (strcmp(comando, "vender") == 0) {
            registrarVenda();
        }else {
            printf("Comando invalido.\n");
        }
    }while(sair != 1);

    return 0;
} 