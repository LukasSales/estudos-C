#include <stdio.h>
#include <stdlib.h>

// Função para verificar se um número é primo
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Função para verificar se a soma dos algarismos é múltiplo de 3
int is_sum_multiple_of_three(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return (sum % 3 == 0);
}

// Função para verificar se um número é um quadrado perfeito
int is_square(int num) {
    int root = 1;
    while (root * root < num) {
        root++;
    }
    return (root * root == num);
}

// Função para determinar a categoria da pergunta com base na casa atual
char* get_category(int casa) {
    if (is_prime(casa)) return "Artes";
    if (is_sum_multiple_of_three(casa)) return "Esportes";
    if (is_square(casa)) return "Ciência";
    return "Conhecimentos Gerais";
}

// Função para determinar se um jogador acerta uma pergunta com base na sorte e categoria
int player_hits_question(int sorte, char* categoria, int casa, int jogador) {
    int soma = sorte + (casa % 7);

    if ((categoria[0] == 'C' && categoria[1] == 'i') && jogador == 0){
        return 1;

    }else if (categoria[0] == 'C' && categoria[1] == 'o' && jogador == 1){
        return 0;

    }else if (categoria[0] == 'E' && jogador == 2){
        return 1;
    }else if (categoria[0] == 'A' && jogador == 3){
        return 1;
    }else if (soma > 5){
        return 1;
    }else {
        return 0;
    }

}

int main() {
    int sorteios[4];
    int rodadas;

    // Recebe a sorte inicial dos jogadores
    for (int i = 0; i < 4; i++) {
        scanf("%d", &sorteios[i]);
    }

    // Recebe o número de rodadas
    scanf("%d", &rodadas);

    int pontos[4] = {0};
    int valores_dados[4] = {0};

    // Realiza as rodadas do jogo
    for (int r = 0; r < rodadas; r++) {
        for (int i = 0; i < 4; i++) {
            int valor_lido;
            scanf("%d", &valor_lido);
            valores_dados[i] += valor_lido; // Incrementa o valor lido ao elemento correspondente do array
        }
    

        for( int j = 0; j < 4; j++){
            if (valores_dados[j] > 31){
                valores_dados[j] = (valores_dados[j] - 31);
            };
        };

        for (int i = 0; i < 4; i++) {
            char* categoria = get_category(valores_dados[i]);
            if (player_hits_question(sorteios[i], categoria, valores_dados[i], i)) {
                pontos[i]++;
            }
        }
    }

    int index[4] = {0, 1, 2, 3};

    // Ordena os jogadores por pontuação decrescente
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (pontos[i] < pontos[j]) {
                int temp = pontos[i];
                int temp_ind = index[i];
                pontos[i] = pontos[j];
                index[i] = index[j];
                pontos[j] = temp;
                index[j] = temp_ind;
                int temp_sorteio = sorteios[i];
                sorteios[i] = sorteios[j];
                sorteios[j] = temp_sorteio;
            }
        }
    }

    char* jogadores[4] = {"David", "Daniel", "Ricardinho", "Lucas"};

    // Exibe os resultados
    for (int i = 0; i < 4; i++) {
        printf("%s %d\n", jogadores[index[i]], pontos[i]);
    }

    return 0;
}
