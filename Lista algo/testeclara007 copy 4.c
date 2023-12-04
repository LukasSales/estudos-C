if (numItensCarrinho < 12){
            fgets(item, sizeof(item), stdin);
            item[strcspn(item, "\n")] = '\0';
        }

        if (strcmp(item, "FINALIZAR COMPRA\n") == 0 || numItensCarrinho == 12) {
            break;
        }

        int encontrado = 0;
        int quantidade;
        scanf("%d", &quantidade);
        for (int i = 0; i < 12; i++) {
            if (strncmp(item, produtos[i], 10) == 0) {
                carrinho[numItensCarrinho].item = item;
                carrinho[numItensCarrinho].quantidade = quantidade;
                carrinho[numItensCarrinho].valor = precos[i];
                numItensCarrinho++;
                encontrado = 1;
                break;   

                for (int k = 0; k < numItensCarrinho + 1; k++){
                    if (strncmp(item, carrinho[k].item, 10) == 0){

            }
        }

        if (!encontrado) {
            printf("\nItem não encontrado.");
        }
        
        }
    }