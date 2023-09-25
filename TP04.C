
#include <stdio.h>

int main() {
    FILE *entrada = fopen("C:/Users/robso/Desktop/ucb trabs/Ed/arquivo.html", "r");

    if (entrada == NULL) {
        printf("Nao foi possivel abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *saida = fopen("texto_limpo.txt", "w");

    if (saida == NULL) {
        printf("Não foi possível criar o arquivo de saída.\n");
        return 1;
    }

    int dentroTag = 0;
    char caractere;

    while ((caractere = fgetc(entrada)) != EOF) {
        if (caractere == '<') {
            dentroTag = 1;
            continue;
        } else if (caractere == '>') {
            dentroTag = 0;
            continue;
        }

        if (!dentroTag) {
            fputc(caractere, saida);
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("Tags HTML removidas com sucesso. O texto limpo foi salvo em texto_limpo.txt.\n");

    return 0;
}
