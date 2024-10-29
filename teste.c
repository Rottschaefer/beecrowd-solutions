#include <stdio.h>
#include <stdio.h>

int main() {

    int matriz[2][2]; // Matriz 2x2
    int i, j;

    printf("Digite 4 numeros separados por espaco:\n");

    // Le a linha de numeros separados por espacos e armazena na matriz
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &matriz[i][j]); // Captura os numeros
        }
    }

    // Exibe a matriz lida
    printf("Matriz inserida:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
