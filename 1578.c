#include <stdio.h>
#include <math.h>

// Função para calcular o número de dígitos de um número
int how_many_digits(unsigned long long x) {
    if (x == 0) {
        return 1;
    }
    return floor(log10(x)) + 1;
}

// Função para obter o maior número de dígitos por coluna
void get_column_max_size(int columns[], int m, unsigned long long M[30][30]) {
    int max = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (how_many_digits(M[j][i]) > max) {
                max = how_many_digits(M[j][i]);
            }
        }
        columns[i] = max;
        max = 1;
    }
}

// Função para imprimir a matriz formatada
void print_matriz(int m, unsigned long long M[30][30], int n) {
    int sizes[30];
    get_column_max_size(sizes, m, M);

    printf("Quadrado da matriz #%i:\n", n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                // Último elemento da linha sem espaço à direita
                printf("%*llu", sizes[j], M[i][j]);
            } else {
                // Elementos intermediários com espaço
                printf("%*llu ", sizes[j], M[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para ler e calcular o quadrado dos elementos da matriz
void read_and_square(int m, unsigned long long M[30][30]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%llu", &M[i][j]);
            M[i][j] = M[i][j] * M[i][j];
        }
    }
}

int main() {
    unsigned long long matriz[30][30];
    int matriz_numbers;
    int m;

    scanf("%i", &matriz_numbers);

    for (int i = 0; i < matriz_numbers; i++) {
        scanf("%i", &m);
        read_and_square(m, matriz);
        print_matriz(m, matriz, i + 4);

        // Linha em branco entre matrizes, mas não após a última
        if (i < matriz_numbers - 1) {
            printf("\n");
        }
    }

    return 0;
}
