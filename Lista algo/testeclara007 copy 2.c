#include <stdio.h>
#include <string.h>

#define MAX 100 // Tamanho máximo para as variáveis char
#define MAXX 21 // Tamanho máximo para as variáveis char

struct Usuario {
    char nome[MAX];
    char email[MAX];
    char regiao[MAX];
    char senha[20];
};

struct Carrinho {
    char item[25];
    float valor;
    int quantidade;
    float valor_total;
};

// Função para calcular o frete com base na região
float calcularFrete(char regiao[]) {
    if (strcmp(regiao, "Nordeste") == 0) {
        return 0.0;
    } else if (strcmp(regiao, "Sudeste") == 0) {
        return 43.28;
    } else if (strcmp(regiao, "Sul") == 0) {
        return 62.94;
    } else if (strcmp(regiao, "Centro-oeste") == 0) {
        return 38.04;
    } else if (strcmp(regiao, "Norte") == 0) {
        return 19.98;
    } else {
        return -1.0; // Região inválida
    }
}


int main() {
    struct Carrinho carrinho[12];
    struct Usuario usuario;
    float subtotal = 0.0, total, frete;

    // Etapa 1: Cadastro do usuário
    
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    fgets(usuario.email, sizeof(usuario.email), stdin);
    fgets(usuario.regiao, sizeof(usuario.regiao), stdin);
    fgets(usuario.senha, sizeof(usuario.senha), stdin);

    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';
    usuario.email[strcspn(usuario.email, "\n")] = '\0';
    usuario.regiao[strcspn(usuario.regiao, "\n")] = '\0';
    usuario.senha[strcspn(usuario.senha, "\n")] = '\0';

    // Etapa 2: Login
    char inputEmail[100], inputSenha[20];
    int loginSucesso = 0;
    
    do {
        fgets(inputEmail, sizeof(inputEmail), stdin);
        fgets(inputSenha, sizeof(inputSenha), stdin);
        
        inputEmail[strcspn(inputEmail, "\n")] = '\0';
        inputSenha[strcspn(inputSenha, "\n")] = '\0';

        if (strcmp(inputEmail, usuario.email) == 0 && strcmp(inputSenha, usuario.senha) == 0) {
            printf("Login bem-sucedido! Vamos às compras.\n");
            loginSucesso = 1;
        } else {
            printf("E-mail ou senha inválidos! Favor, realize o login novamente.\n");
        }
    } while (!loginSucesso);

    // Tabela de produtos
    char produtos[][100] = {
        "Caneca Neon", "Moletom Nasa", "Lapiseira Técnica 0.3", "Lapiseira Técnica 0.5",
        "Lapiseira Técnica 0.7", "Caneca Panda Vermelho", "Borracha Faber", "Moletom Barroco",
        "Caneta Tinteiro", "Tinta Nankin 45ml", "Post-it 90 folhas", "Fita Anti-adesiva"
    };

    float precos[12] = {
        67.39,
        172.90,
        39.90,
        39.90,
        39.90,
        70.83,
        4.99,
        210.00,
        128.65,
        51.58,
        24.90,
        532.41
    };

    // Etapa 3: Compondo o carrinho
    int numItensCarrinho = 0;

    while (numItensCarrinho < 12) {
        char item[100];
        int quantidade;
        int encontrado = 0;

        fgets(item, sizeof(item), stdin);
        item[strcspn(item, "\n")] = '\0';

        if (strcmp(item, "FINALIZAR COMPRA") == 0) {
            break;
        }
        scanf("%d", &quantidade);
        getchar();

        for (int i = 0; i < 12; i++){
            if (strcmp(item, produtos[i]) == 0){
                carrinho[numItensCarrinho].quantidade = quantidade;
                carrinho[numItensCarrinho].valor = precos[i];
                strcpy(carrinho[numItensCarrinho].item, produtos[i]);
                carrinho[numItensCarrinho].valor_total = precos[i]*quantidade;
                numItensCarrinho ++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado){
            printf("Item não encontrado.\n");
        }

    }


    // Etapa 5: Imprimindo o Carrinho
    printf("%-*s%33s\n", -MAXX, "Itens", "Quantidade e Preço");
    for (int i = 0; i < numItensCarrinho; i++) {
        printf("%-*s%15dxR$%.2f\n", MAXX, carrinho[i].item, carrinho[i].quantidade, carrinho[i].valor);
        subtotal += carrinho[i].valor_total;
    }
    printf("\n%-*s%16s%.2f\n", MAXX, "Subtotal", "R$", subtotal);

    // Calcular o frete com base na região
    frete = calcularFrete(usuario.regiao);

    total = subtotal + frete;
    printf("%-*s%13s%.2f\n", MAXX, "Total (Subtotal + Frete)", "R$", total);

       // Etapa 6: Confirmação da compra

    
    char confirmacao[20];
   
    fgets(confirmacao, sizeof(confirmacao), stdin);

    confirmacao[strcspn(confirmacao, "\n")] = '\0';

    if (strcmp(confirmacao, "CONFIRMAR") == 0) {
        printf("Compra efetuada com sucesso. Agora é só aguardar o dia da felicidade :)\n");
    } else if (strcmp(confirmacao, "CANCELAR") == 0) {
        printf("Compra cancelada... Que pena... quem sabe na próxima :(\n");
    }
    return 0;
}