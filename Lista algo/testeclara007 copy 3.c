#include <stdio.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_EMAIL 100
#define MAX_REGIAO 100
#define MAX_SENHA 20
#define MAX_ITENS 12
#define MAX 21

struct Usuario {
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char regiao[MAX_REGIAO];
    char senha[MAX_SENHA];
};

struct Item {
    char nome[MAX_NOME];
    int quantidade;
    float precoUnitario;
};

int main() {
    struct Usuario usuario;
    struct Item carrinho[MAX_ITENS];
    
    char produtos[][MAX_NOME] = {
        "Caneca Neon", "Moletom Nasa", "Lapiseira Técnica 0.3", "Lapiseira Técnica 0.5",
        "Lapiseira Técnica 0.7", "Caneca Panda Vermelho", "Borracha Faber", "Moletom Barroco",
        "Caneta Tinteiro", "Tinta Nankin 45ml", "Post-it 90 folhas", "Fita Anti-adesiva"
    };
    
    float precos[] = {
        67.39, 172.90, 39.90, 39.90, 39.90, 70.83, 4.99, 210.00, 128.65, 51.58, 24.90, 532.41
    };
    
    char regioes[][MAX_REGIAO] = {"Nordeste", "Sudeste", "Sul", "Centro-oeste", "Norte"};
    float fretes[] = {0.0, 43.28, 62.94, 38.04, 19.98};
    
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    fgets(usuario.email, sizeof(usuario.email), stdin);
    fgets(usuario.regiao, sizeof(usuario.regiao), stdin);
    fgets(usuario.senha, sizeof(usuario.senha), stdin);
    
    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';
    usuario.email[strcspn(usuario.email, "\n")] = '\0';
    usuario.regiao[strcspn(usuario.regiao, "\n")] = '\0';
    usuario.senha[strcspn(usuario.senha, "\n")] = '\0';

    char email[MAX_EMAIL];
    char senha[MAX_SENHA];
    int loginSucesso = 0;
    
    while (!loginSucesso) {
        fgets(email, sizeof(email), stdin);
        fgets(senha, sizeof(senha), stdin);

        email[strcspn(email, "\n")] = '\0';
        senha[strcspn(senha, "\n")] = '\0';

        if (strcmp(email, usuario.email) == 0 && strcmp(senha, usuario.senha) == 0) {
            printf("Login bem-sucedido! Vamos às compras.\n");
            loginSucesso = 1;
        } else {
            printf("E-mail ou senha inválidos! Favor, realize o login novamente.\n");
        }
    }
    
    int numItensCarrinho = 0;
    float subtotal = 0.0;
    
    while (numItensCarrinho < MAX_ITENS) {
        char nomeItem[MAX_NOME];
        int quantidade;
        int itemEncontrado = 0;
        
        fgets(nomeItem, sizeof(nomeItem), stdin);
        nomeItem[strcspn(nomeItem, "\n")] = '\0';

        if (strcmp(nomeItem, "FINALIZAR COMPRA") == 0) {
            break;
        }

        scanf("%d", &quantidade);
        getchar();

        for (int i = 0; i < MAX_ITENS; i++) {
            if (strcmp(nomeItem, produtos[i]) == 0) {
                carrinho[numItensCarrinho].quantidade = quantidade;
                carrinho[numItensCarrinho].precoUnitario = precos[i];
                strcpy(carrinho[numItensCarrinho].nome, produtos[i]);
                subtotal += quantidade * precos[i];
                numItensCarrinho++;
                itemEncontrado = 1;
                break;
            }
        }

        if (!itemEncontrado) {
            printf("Item não encontrado.\n");
        }
    }

    printf("%-*s%33s\n", -MAX, "Itens", "Quantidade e Preço");
    
    for (int i = 0; i < numItensCarrinho; i++) {
        printf("%*s%15dxR$%.2f\n", -MAX, carrinho[i].nome, carrinho[i].quantidade, carrinho[i].precoUnitario);
    }
    
    char *regiaoUsuario = usuario.regiao;
    float frete = 0.0;
    
    for (int i = 0; i < sizeof(regioes) / sizeof(regioes[0]); i++) {
        if (strcmp(regiaoUsuario, regioes[i]) == 0) {
            frete = fretes[i];
            break;
        }
    }
    
    printf("\n%*s%16s%.2f\n", -MAX, "Subtotal", "R$", subtotal);
    printf("%*s%13s%.2f\n", -MAX, "Total (Subtotal + Frete)", "R$", subtotal + frete);
    
    char confirmacao[20];
    
    fgets(confirmacao, sizeof(confirmacao), stdin);

    confirmacao[strcspn(confirmacao, "\n")] = '\0';

    if (strcmp(confirmacao, "CONFIRMAR") == 0) {
        printf("Compra efetuada com sucesso. Agora é só aguardar o dia da felicidade :)\n");
    } else if (strcmp(confirmacao, "CANCELAR") == 0) {
        printf("Compra cancelada... Que pena... quem sabe na próxima :(\n");
    } else {
        printf("Opção inválida. Compra cancelada.\n");
    }

    return 0;
}