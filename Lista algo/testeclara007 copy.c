#include <stdio.h>
#include <string.h>

#define MAX 30 // Tamanho máximo para as variáveis char
#define MAXX 21 // Tamanho máximo para as variáveis char

struct Usuario {
    char nome[MAX];
    char email[MAX];
    char regiao[MAX];
    char senha[MAX];
};

struct Carrinho {
    char item[22];
    float valor;
    int quantidade;
    float valor_total;
};

int verificarLogin(struct Usuario usuario, char *email, char *senha) {
    return (strcmp(usuario.email, email) == 0 && strcmp(usuario.senha, senha) == 0);
}

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
    char item[25];
    int quantidade;
    float subtotal = 0.0, total, frete;
    char confirmacao[MAX];

    // Etapa 1: Cadastro do usuário
    
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';  // Remove a quebra de linha do final

    fgets(usuario.email, sizeof(usuario.email), stdin);
    usuario.email[strcspn(usuario.email, "\n")] = '\0';

    fgets(usuario.regiao, sizeof(usuario.regiao), stdin);
    usuario.regiao[strcspn(usuario.regiao, "\n")] = '\0';

    fgets(usuario.senha, sizeof(usuario.senha), stdin);
    usuario.senha[strcspn(usuario.senha, "\n")] = '\0';

    // Etapa 2: Login
    char inputEmail[MAX], inputSenha[MAX];
    int loginSucesso = 0;
    
    do {
        fgets(inputEmail, sizeof(inputEmail), stdin);
        inputEmail[strcspn(inputEmail, "\n")] = '\0';  // Remova a quebra de linha
        
        fgets(inputSenha, sizeof(inputSenha), stdin);
        inputSenha[strcspn(inputSenha, "\n")] = '\0';  // Remova a quebra de linha

        if (verificarLogin(usuario, inputEmail, inputSenha)) {
            printf("Login bem-sucedido! Vamos às compras.");
            loginSucesso = 1;
        } else {
            printf("E-mail ou senha inválidos! Favor, realize o login novamente.\n");
        }
    } while (!loginSucesso);

    // Tabela de produtos
    char produtos[12][25] = {
        "Caneca Neon",
        "Moletom Nasa",
        "Lapiseira Técnica 0.3",
        "Lapiseira Técnica 0.5",
        "Lapiseira Técnica 0.7",
        "Caneca Panda Vermelho",
        "Borracha Faber",
        "Moletom Barroco",
        "Caneta Tinteiro",
        "Tinta Nankin 45ml",
        "Post-it 90 folhas",
        "Fita Anti-adesiva"
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

    while (1) {

        if (numItensCarrinho < 12){
            fgets(item, sizeof(item), stdin);
        }

        if (strcmp(item, "FINALIZAR COMPRA\n") == 0 || numItensCarrinho == 12) {
            break;
        }

        // Remova o caractere '\n' da entrada do usuário
        item[strcspn(item, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < 12; i++) {
            if (strncmp(item, produtos[i], 10) == 0) {
                int quantidade;
                scanf("%d", &quantidade);
                encontrado = 1;
                int verificador = 0;    

                for (int k = 0; k < numItensCarrinho + 1; k++){
                    if (strncmp(item, carrinho[k].item, 10) == 0){
                        carrinho[k].quantidade = carrinho[k].quantidade + quantidade;
                        carrinho[k].valor_total = carrinho[k].quantidade*precos[k];
                        verificador = 1;
                        break;
                    }
                }
                if (!verificador){

                    strcpy(carrinho[numItensCarrinho].item, produtos[i]);
                    carrinho[numItensCarrinho].valor = precos[i];
                    carrinho[numItensCarrinho].quantidade = quantidade;
                    carrinho[numItensCarrinho].valor_total = quantidade*precos[i];
                    numItensCarrinho++;
                }
                getchar(); // Consumir o caractere '\n' do buffer
                break;
            }
        }

        if (!encontrado) {
            getchar(); // Consumir o caractere '\n' do buffer
            scanf("%d", &quantidade);
            printf("\nItem não encontrado.");
            getchar(); // Consumir o caractere '\n' do buffer

        }
        
    }

    // Etapa 5: Imprimindo o Carrinho
    printf("\n%*s%33s\n", -MAXX, "Itens", "Quantidade e Preço");
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

    
    if (numItensCarrinho == 12){
        fgets(confirmacao, sizeof(confirmacao), stdin);
    }
   
    fgets(confirmacao, sizeof(confirmacao), stdin);

    if (strcmp(confirmacao, "CONFIRMAR\n") == 0) {
        printf("Compra efetuada com sucesso. Agora é só aguardar o dia da felicidade :)\n");
    } else if (strcmp(confirmacao, "CANCELAR\n") == 0) {
        printf("Compra cancelada... Que pena... quem sabe na próxima :(\n");
    }
    return 0;
}