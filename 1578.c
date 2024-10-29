#include <stdio.h>


int how_many_digits(int x){
    int digits = 0;

    if(x == 0){
        return 1;
    }

    while(x > 0){
        x = x/10;
        digits++;
    }

    return digits;
}

void get_column_max_size(int columns[], int m, long long int M[][m]){
    int max = 1;

     for(int i = 0; i<m ;i++){
        for(int j = 0; j<m ;j++){


            if(M[i][j] > max){
                max = how_many_digits(M[j][i]);
            }
    }

    columns[i] = max;
    max = 0;

    }
}

void print_matriz(int m, long long int M[][m], int n){

    int sizes[20];

    get_column_max_size(sizes, m, M);

    printf("Qudrado da matriz #%i:\n", n);

     for(int i = 0; i<m ;i++){
         for(int j = 0; j<m ;j++){
             printf("%*lli ", sizes[j],M[i][j]);
             printf("i:%i - j:%i\n", i, j);

     }
            printf("\n");
     }
}

void read_and_square(int m, long long int M[][m]) {



    // Leitura de cada linha da matriz
    for (int i = 0; i < m; i++) {
        printf("Digite 2 numeros para a linha %d separados por espaco:\n", i + 1);

        // Lê duas entradas para cada linha da matriz
        for (int j = 0; j < m; j++) {
            scanf("%lli", &M[i][j]);
            M[i][j]=M[i][j]*M[i][j];
        }
    }

    

}
int main(){

    int m = 2;
    int n = 4;

    long long int matriz[20][20] ={0};

    read_and_square(m,matriz);
    print_matriz(m,matriz, n);


 for (int i = 0; i < m; i++) {
         for (int j = 0; j < m; j++) {
             printf("%lli - ", matriz[1][1]);
             printf("i:%i - j:%i\n", i, j);
         }
         puts("\n");
     }
     

        // char car;
        // int teste[3];

        // int i = 0;
        

        //  for(int i=0; i<3; i++){
        //     scanf("%d%c", &teste[i], &car);
        //  }

        //  for(int i=0; i<3; i++){
        //  printf("%i - ", teste[i]);
        //  }

// for (int i = 0; i < m; i++) {
//         for (int j = 0; j < m; j++) {
//             // Lê um número inteiro e armazena na matriz
//             printf("%lli - ", matriz[i][j]);
//         }
//     }

    

    // printf("\n\n%i", how_many_digits(0));
    
    return 0;
}