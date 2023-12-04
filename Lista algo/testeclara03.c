#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definição da estrutura do jogador
struct Jogador {
    char nome[20];
    char posicao[3];
    char* nivel;
    int Chute;
    int Drible;
    int Forca;
    int Defesa;
    int Velocidade;
    int Passe;
    float Overall;
};

float over_all(struct Jogador jogador) {

    if (strcmp(jogador.posicao, "ATA") == 0) {
        return (jogador.Chute*5 + jogador.Drible*3 + jogador.Forca*1 + jogador.Defesa*1 + jogador.Velocidade*3 + jogador.Passe*2) / 15.0;

    } else if (strcmp(jogador.posicao, "MEI") == 0) {
        return (jogador.Chute*3 + jogador.Drible*3 + jogador.Forca*2 + jogador.Defesa*2 + jogador.Velocidade*3 + jogador.Passe*2) / 15.0;

    } else if (strcmp(jogador.posicao, "ZAG") == 0) {
        return (jogador.Chute*2 + jogador.Drible*1 + jogador.Forca*4 + jogador.Defesa*5 + jogador.Velocidade*2 + jogador.Passe*1) / 15.0;

    } else {
        return (jogador.Chute*2 + jogador.Drible*1 + jogador.Forca*4 + jogador.Defesa*5 + jogador.Velocidade*2 + jogador.Passe*1) / 15.0;

    };
};

char* Descobrinivel(double Overall) {
    char* Nivel = (char*)malloc(sizeof(char) * 10); // Aloca espaço para a string
    if (Overall < 60) {
        strcpy(Nivel, "PRATA");
    } else if (Overall < 70) {
        strcpy(Nivel, "OURO");
    } else if (Overall < 90) {
        strcpy(Nivel, "LEGEND");
    } else {
        strcpy(Nivel, "TOTY");
    }
    return Nivel;
}

void Selecionar_jogador(struct Jogador jogadores[], int n, char** habilidade, int* indiceMaiorOverall) {
    if (n <= 0) {
        // Trate o caso em que não há jogadores
        *habilidade = NULL;
        *indiceMaiorOverall = -1;
        return;
    }

    *indiceMaiorOverall = 0;  // Suponha que o primeiro jogador tem o maior overall inicialmente

    for (int i = 1; i < n; i++) {
        if (jogadores[i].Overall > jogadores[*indiceMaiorOverall].Overall) {
            *indiceMaiorOverall = i;  // Atualize o índice do jogador com o maior overall
        }
    }

    if (strcmp(jogadores[*indiceMaiorOverall].posicao, "ATA") == 0) {
        *habilidade = "FINALIZADOR";
    } else if (strcmp(jogadores[*indiceMaiorOverall].posicao, "MEI") == 0) {
        *habilidade = "DRIBLADOR";
    } else if (strcmp(jogadores[*indiceMaiorOverall].posicao, "GOL") == 0 || strcmp(jogadores[*indiceMaiorOverall].posicao, "ZAG") == 0) {
        *habilidade = "DEFENSOR NATO";
    }
};


int main() {
    int numeros[6];  // Suponha que haja no máximo 100 números

    int n; // Número de jogadores
    scanf("%d", &n);

    // Limpeza do buffer de entrada

    // Declaração de um vetor de jogadores com tamanho n
    struct Jogador jogadores[n];

    // Loop para cada jogador
    for (int i = 0; i < n; i++) {
        getchar();
        
        // Leitura do nome e posição
        fgets(jogadores[i].nome, sizeof(jogadores[i].nome), stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';  // Remove o caractere de nova linha
        scanf("%s", jogadores[i].posicao);

        // Inicializa a variável 'overall' para cada jogador
        int overall = 0;

        // Leitura dos valores numéricos
        for (int j = 0; j < 6; j++) {
            scanf("%d", &numeros[j]);
        };

        // Atribuição dos valores lidos à estrutura do jogador
        jogadores[i].Chute = numeros[0];
        jogadores[i].Drible = numeros[1];
        jogadores[i].Forca = numeros[2];
        jogadores[i].Defesa = numeros[3];
        jogadores[i].Velocidade = numeros[4];
        jogadores[i].Passe = numeros[5];

        // Cálculo do Overall

        jogadores[i].Overall = over_all(jogadores[i]);
        jogadores[i].nivel = Descobrinivel(jogadores[i].Overall);

        printf("%s - %s - %s\n", jogadores[i].nome, jogadores[i].posicao, jogadores[i].nivel);
        printf("Overall: %.2lf\n", jogadores[i].Overall);
        printf("Chute: %d\n", jogadores[i].Chute);
        printf("Drible: %d\n", jogadores[i].Drible);
        printf("Forca: %d\n", jogadores[i].Forca);
        printf("Defesa: %d\n", jogadores[i].Defesa);
        printf("Velocidade: %d\n", jogadores[i].Velocidade);
        printf("Passe: %d\n\n", jogadores[i].Passe);
    }

    char* habilidade;
    int indiceMaiorOverall;
    Selecionar_jogador(jogadores, n, &habilidade, &indiceMaiorOverall);

    printf("O melhor jogador para a habilidade %s\n", habilidade);
    printf("eh: %s!\n", jogadores[indiceMaiorOverall].nome);
    
      // Liberar a memória alocada para o campo 'nivel' de cada jogador
    for (int i = 0; i < n; i++) {
        free(jogadores[i].nivel);
    }

    return 0;
}