#include <stdio.h>
#include <string.h>

typedef struct Empregados {
    char nomes[10][20];
    char sobrenomes[10][20];
} Empregados;

typedef struct Cadastro {
    char nome[20];
    char sobrenome[20];
} Cadastro;

void popularEmpregados(Empregados *lista) {
    strcpy(lista->nomes[0], "Tulla Luana");
    strcpy(lista->nomes[1], "Elon");
    strcpy(lista->nomes[2], "Mark");
    strcpy(lista->nomes[3], "Hulk");

    strcpy(lista->sobrenomes[0], "Web Diva");
    strcpy(lista->sobrenomes[1], "Musk");
    strcpy(lista->sobrenomes[2], "Zuckerberg");
    strcpy(lista->sobrenomes[3], "Magrelo");
}

struct CarrinhoCompra {
    char destino[50];
    char hotel[50];
    char voo[50];
    int dias, pessoas, custoHotel, quartosCasal, quartosSolteiro;
    float custoVoo;
    float custoTotal;
} typedef Pedido;

int main() {
    Empregados empregados;
    Cadastro cadastroAtual, login;
    popularEmpregados(&empregados);
    Pedido pedidos[5];
    char resposta[5], local[50], escolha[50], entrada[50], senha[20], senhaCorreta[20];
    int i = 0, contador = 0, verificador = 0, quartosCasal, quartosSolteiro, indice, indiceAnterior = 5, temp;

    scanf(" %s", resposta);

    if (strcmp(resposta, "Nao") == 0) {
        scanf(" %[^\n] %[^\n]", cadastroAtual.nome, cadastroAtual.sobrenome);
    }
    scanf(" %[^\n] %[^\n]", login.nome, login.sobrenome);

    while(verificador < 10){
        if(strcmp((login.nome), empregados.nomes[verificador]) == 0 && strcmp(login.sobrenome, empregados.sobrenomes[verificador]) == 0){
            contador ++;
        }
        verificador ++;
    }

    do {
        if (contador != 1){

            if (strcmp(cadastroAtual.nome, login.nome) != 0 || strcmp(cadastroAtual.sobrenome, login.sobrenome) != 0) {
                scanf(" %[^\n]", escolha);
                if (strcmp(escolha, "Tentar") == 0) {
                    scanf(" %[^\n] %[^\n]", login.nome, login.sobrenome);
                } else if (strcmp(escolha, "Cadastrar") == 0) {
                    scanf(" %[^\n] %[^\n]", cadastroAtual.nome, cadastroAtual.sobrenome);
                    scanf(" %[^\n] %[^\n]", login.nome, login.sobrenome);
                }
                indice = 0;
                while (indice < 4) {
                    if (strcmp(login.nome, empregados.nomes[indice]) == 0 && strcmp(login.sobrenome, empregados.sobrenomes[indice]) == 0) {
                        contador++;
                    }
                    indice++;
                }
            } else
                contador = 1;
        }
    } while (contador != 1);
    strcpy(senhaCorreta, login.sobrenome);
    scanf(" %[^\n]", local);
    while (strcmp(local, "Finalizar") != 0) {
        strcpy(pedidos[i].destino, local);
        if (strcmp(local, "Feira de Santana") == 0) {
            scanf("%d %d", &pedidos[i].pessoas, &pedidos[i].dias);
            scanf(" %s", escolha);
            strcpy(pedidos[i].voo, escolha);
            if (strcmp(escolha, "Azul") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 346.73 * 2;
            } else if (strcmp(escolha, "Gol") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 384.32 * 2;
            } else if (strcmp(escolha, "Latam") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 421.95 * 2;
            }
            scanf(" %s %d %d", escolha, &pedidos[i].quartosCasal, &pedidos[i].quartosSolteiro);
            strcpy(pedidos[i].hotel, escolha);
            if (strcmp(escolha, "Jomil") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 100 + pedidos[i].quartosSolteiro * 80) * pedidos[i].dias;
            } else if (strcmp(escolha, "Plaza") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 120 + pedidos[i].quartosSolteiro * 65) * pedidos[i].dias;
            } else if (strcmp(escolha, "Ibis") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 140 + pedidos[i].quartosSolteiro * 75) * pedidos[i].dias;
            }
            pedidos[i].custoTotal = pedidos[i].custoHotel + pedidos[i].custoVoo;
            i++;
        } else if (strcmp(local, "Salvador") == 0) {
            scanf("%d %d", &pedidos[i].pessoas, &pedidos[i].dias);
            scanf(" %s", escolha);
            strcpy(pedidos[i].voo, escolha);
            if (strcmp(escolha, "Azul") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 528.86 * 2;
            } else if (strcmp(escolha, "Gol") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 583.42 * 2;
            } else if (strcmp(escolha, "Latam") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 635.17 * 2;
            }
            scanf(" %s %d %d", escolha, &pedidos[i].quartosCasal, &pedidos[i].quartosSolteiro);
            strcpy(pedidos[i].hotel, escolha);
            if (strcmp(escolha, "Aquarena") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 174 + pedidos[i].quartosSolteiro * 100) * pedidos[i].dias;
            } else if (strcmp(escolha, "Bougainville") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 227 + pedidos[i].quartosSolteiro * 150) * pedidos[i].dias;
            } else if (strcmp(escolha, "Sotero") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 210 + pedidos[i].quartosSolteiro * 130) * pedidos[i].dias;
            }
            pedidos[i].custoTotal = pedidos[i].custoHotel + pedidos[i].custoVoo;
            i++;
        } else if (strcmp(local, "Porto Seguro") == 0) {
            scanf("%d %d", &pedidos[i].pessoas, &pedidos[i].dias);
            scanf(" %s", escolha);
            strcpy(pedidos[i].voo, escolha);
            if (strcmp(escolha, "Azul") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 412.44 * 2;
            } else if (strcmp(escolha, "Gol") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 469.73 * 2;
            } else if (strcmp(escolha, "Latam") == 0) {
                pedidos[i].custoVoo = pedidos[i].pessoas * 522.13 * 2;
            }
            scanf(" %[^\n] %d %d", escolha, &pedidos[i].quartosCasal, &pedidos[i].quartosSolteiro);
            strcpy(pedidos[i].hotel, escolha);
            if (strcmp(escolha, "Vitoria Regia") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 200 + pedidos[i].quartosSolteiro * 120) * pedidos[i].dias;
            } else if (strcmp(escolha, "Monte Pascoal") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 230 + pedidos[i].quartosSolteiro * 140) * pedidos[i].dias;
            } else if (strcmp(escolha, "Portobello") == 0) {
                pedidos[i].custoHotel = (pedidos[i].quartosCasal * 272 + pedidos[i].quartosSolteiro * 160) * pedidos[i].dias;
            }
            pedidos[i].custoTotal = pedidos[i].custoHotel + pedidos[i].custoVoo;
            i++;
        }
        scanf(" %[^\n]", local);
    }
    int j = 0;
    while (j < i) {
        printf("Destino: %s\nVoo da %s\nHotel %s\n%d dias\n%d passageiros\n%d Quartos de casal\n%d Quartos de solteiro\nPreço: %.2f\n\n", pedidos[j].destino, pedidos[j].voo, pedidos[j].hotel, pedidos[j].dias, pedidos[j].pessoas, pedidos[j].quartosCasal, pedidos[j].quartosSolteiro, pedidos[j].custoTotal);
        j++;
    }
    scanf(" %[^\n]", local);
    if (strcmp(local, "Sim") == 0) {
        scanf("%d", &contador);
        while (contador > 0) {
            scanf("%d", &indice);
            temp = indice;
            if (indice > indiceAnterior) {
                temp--;
            }
            temp--;
            while (temp < i - 1) {
                pedidos[temp] = pedidos[temp + 1];
                temp++;
            }
            i--;
            contador--;
            indiceAnterior = indice;
        }
        j = 0;
        while (j < i) {
            printf("Destino: %s\nVoo da %s\nHotel %s\n%d dias\n%d passageiros\n%d Quartos de casal\n%d Quartos de solteiro\nPreço: %.2f\n\n", pedidos[j].destino, pedidos[j].voo, pedidos[j].hotel, pedidos[j].dias, pedidos[j].pessoas, pedidos[j].quartosCasal, pedidos[j].quartosSolteiro, pedidos[j].custoTotal);
            j++;
        }
    }
    scanf(" %[^\n]", senha);
    j = 4;
    while (strcmp(senha, senhaCorreta) != 0) {
        printf("Senha inválida! Você tem %d tentativas.\n", j);
        scanf(" %[^\n]", senha);
        j--;
        if (j == 1) {
            printf("Senha inválida! Última tentativa antes do bloqueio.\n");
            scanf(" %[^\n]", senha);
            break;
        }
    }
    if (strcmp(senha, senhaCorreta) == 0) {
        printf("Compra realizada com sucesso");
    } else {
        printf("CONTA BLOQUEADA!!");
    }
    return 0;
}