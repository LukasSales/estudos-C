#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char* nome_comprador;
    char pais_origem[30];
    char pais_destino[30];
    int frete;

    // Informações do produto
    int ID;
    char* nome_produto;
    double valorPorLote;
    int quantidadeDeLotes;
    int valor_frete;
    double valorTotal;
};

// Construtor personalizado para a estrutura Produto
struct Produto criarProduto(const char* nome_comprador, const char* pais_origem, const char* pais_destino, int ID, double valorPorLote, int quantidadeDeLotes) {
    struct Produto novoProduto;

    // Aloca memória para o nome do comprador e copia o valor fornecido
    novoProduto.nome_comprador = (char*)malloc(strlen(nome_comprador) + 1);
    strcpy(novoProduto.nome_comprador, nome_comprador);

    // Define os valores dos outros campos
    novoProduto.ID = ID;

    // Copia o valor dos países de origem e destino (até 30 caracteres)
    strncpy(novoProduto.pais_origem, pais_origem, sizeof(novoProduto.pais_origem) - 1);
    novoProduto.pais_origem[sizeof(novoProduto.pais_origem) - 1] = '\0';

    strncpy(novoProduto.pais_destino, pais_destino, sizeof(novoProduto.pais_destino) - 1);
    novoProduto.pais_destino[sizeof(novoProduto.pais_destino) - 1] = '\0';

    novoProduto.valorPorLote = valorPorLote;
    novoProduto.quantidadeDeLotes = quantidadeDeLotes;

    // Atualiza o campo nome_produto com base no ID
    switch (ID) {
        case 700:
            novoProduto.nome_produto = "Soja";
            valorPorLote = 163.43;
            break;
        case 701:
            novoProduto.nome_produto = "Cafe";
            valorPorLote = 123.09;
            break;
        case 702:
            novoProduto.nome_produto = "Laranja";
            valorPorLote = 179.53;
            break;
        case 703:
            novoProduto.nome_produto = "Banana";
            valorPorLote = 193.78;
            break;
        case 704:
            novoProduto.nome_produto = "Trigo";
            valorPorLote = 156.66;
            break;
        case 705:
            novoProduto.nome_produto = "Melancia";
            valorPorLote = 249.51;
            break;
        case 706:
            novoProduto.nome_produto = "Abacaxi";
            valorPorLote = 221.75;
            break;
        case 707:
            novoProduto.nome_produto = "Carne bovina";
            valorPorLote = 457.85;
            break;
        case 708:
            novoProduto.nome_produto = "Caju";
            valorPorLote = 173.98;
            break;
        case 709:
            novoProduto.nome_produto = "Carne suína";
            valorPorLote = 376.91;
            break;
        // Adicione mais casos conforme necessário
        default:
            novoProduto.nome_produto = "Operacao invalida!";
            break;
    }

    // Calcula o valor do frete com base no país de origem
    if (strcmp(pais_origem, "Africa") == 0) {
        novoProduto.valor_frete = 250;
    } else if (strcmp(pais_origem, "America") == 0) {
        novoProduto.valor_frete = 150;
    } else if (strcmp(pais_origem, "Asia") == 0) {
        novoProduto.valor_frete = 450;
    } else if (strcmp(pais_origem, "Europa") == 0) {
        novoProduto.valor_frete = 300;
    } else {
        novoProduto.valor_frete = 400;
    }

    return novoProduto;
}

// Função para calcular o valor total
double calcularValorTotal(double valorPorLote, int quantidadeDeLotes) {
    return ((valorPorLote * quantidadeDeLotes)/5.17);
}

int main() {

    char Comprador[31];  // Declara uma string de tamanho 31 para acomodar até 30 caracteres e o caractere nulo '\0'.
    char Pais_destino[31];
    char Continente_origem[31];
    
    int ID;
    int Quantidade_lotes;
    fgets(Comprador, sizeof(Comprador), stdin);
    Comprador[strcspn(Comprador, "\n")] = '\0';  // Remova o caractere de nova linha
    fgets(Pais_destino, sizeof(Pais_destino), stdin);
    Pais_destino[strcspn(Pais_destino, "\n")] = '\0';  // Remova o caractere de nova linha
    fgets(Continente_origem, sizeof(Continente_origem), stdin);
    Continente_origem[strcspn(Continente_origem, "\n")] = '\0';  // Remova o caractere de nova linha
    scanf("%d", &ID);
    scanf("%d", &Quantidade_lotes);

    // Criando uma estrutura Produto usando o construtor personalizado
    struct Produto meuProduto = criarProduto(Comprador, Continente_origem, Pais_destino, ID, 0, Quantidade_lotes);

    // Verifica se o nome_produto não é "Operacao invalida!"
    if (strcmp(meuProduto.nome_produto, "Operacao invalida!") != 0) {
        meuProduto.valorTotal = calcularValorTotal(meuProduto.valorPorLote, meuProduto.quantidadeDeLotes);

        printf("%s\n", meuProduto.nome_comprador);
        printf("%s\n", meuProduto.pais_destino);
        printf("%s\n", meuProduto.nome_produto);
        printf("Valor do produto: U$ %.2lf\n", meuProduto.valorTotal);
        printf("Valor do frete: U$ %d\n", meuProduto.valor_frete);
        printf("Valor total: U$ %.2lf\n", meuProduto.valorTotal);
    } else {
        printf("Operacao invalida!\n");
    };

    // Liberando a memória alocada para o nome do comprador (não liberamos nome_produto, pois não alocamos memória dinamicamente para ele)
    free(meuProduto.nome_comprador);

    return 0;
}
