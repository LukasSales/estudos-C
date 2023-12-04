#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações sobre os funcionários
struct Funcionario {
    char nome[51];
    char cpf[12]; // String sem espaços para o CPF
    float salario;
};

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    printf("Bem-vindo a empresa Jorginho Soccer!\n");

    int capacidadeMaxima;
    printf("Informe a quantidade maxima de funcionarios que ira ser cadastrada:\n");
    scanf("%d", &capacidadeMaxima);

    // Aloca memória para o array de funcionários com base na capacidade máxima
    struct Funcionario *funcionarios = (struct Funcionario *)malloc(capacidadeMaxima * sizeof(struct Funcionario));

    if (funcionarios == NULL) {
        printf("Erro ao alocar memoria. Encerrando o programa.\n");
        return 1;
    }

    int numFuncionarios = 0; // Contador de funcionários cadastrados

    while (1) { // Loop principal do programa
    
        printf("Menu:\n");
        printf("Adicionar funcionario--[1]\n");
        printf("Exibir informacoes--[2]\n");
        printf("Calcular media salarial--[3]\n");
        printf("Sair--[4]\n");

        int escolha;
        printf("Escolha uma opcao:\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: // Opção: Adicionar funcionário
                if (numFuncionarios < capacidadeMaxima) {
                    printf("Adicionar funcionario:\n");

                    limparBuffer(); // Limpa o buffer do teclado

                    // Solicita as informações do funcionário
                    printf("Nome:\n");
                    fgets(funcionarios[numFuncionarios].nome, sizeof(funcionarios[numFuncionarios].nome), stdin);
                    strtok(funcionarios[numFuncionarios].nome, "\n"); // Remove a quebra de linha

                    printf("CPF:\n");
                    scanf("%11s", funcionarios[numFuncionarios].cpf);

                    printf("Salario:\n");
                    scanf("%f", &funcionarios[numFuncionarios].salario);

                    printf("Funcionario adicionado com sucesso!\n");
                    numFuncionarios++;
                } else {
                    printf("Limite maximo de funcionarios atingido!\n");
                }
                break;

            case 2: // Exibir informações dos funcionários
                if (numFuncionarios > 0) {
                    printf("Informacoes dos funcionarios da Jorginho Soccer:\n");
                    for (int i = 0; i < numFuncionarios; i++) {
                        printf("Funcionario %d:\n", i + 1);
                        printf("Nome: %s\n", funcionarios[i].nome);
                        printf("CPF: %s\n", funcionarios[i].cpf);
                        printf("Salario: R$%.2f\n", funcionarios[i].salario);
                    }
                } else {
                    printf("Nao ha funcionarios cadastrados.\n");
                }
                break;

            case 3: // Opção: Calcular média salarial
            
                if (numFuncionarios > 0) {
                    float somaSalarios = 0.0;
                    for (int i = 0; i < numFuncionarios; i++) {
                        somaSalarios += funcionarios[i].salario;
                    }
                    float mediaSalarial = somaSalarios / numFuncionarios;
                    printf("Media Salarial: R$%.2f\n", mediaSalarial);
                } else {
                    printf("Nao ha funcionarios para calcular a media.\n");
                }
                break;

            case 4: // Opção: Sair do programa
                printf("Saindo do sistema.\n");
                free(funcionarios); // Libera a memória alocada
                return 0;

            default:
                printf("Opcao invalida sinto muito, tente novamente mais tarde ;-;\n");
                return 0;
        }
    }

    return 0;
}