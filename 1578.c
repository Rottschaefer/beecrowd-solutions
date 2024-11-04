#include <stdio.h>


int how_many_digits(int x){
    int digits = 0;

    if (x < 0) {
        x = -x; 
    }

    if(x == 0){
        return 1;
    }

    while(x > 0){
        x = x/10;
        digits++;
    }

    return digits;
}

void get_column_max_size(int columns[], int m, long long int M[30][30]){
    int max = 1;

     for(int i = 0; i<m ;i++){
        for(int j = 0; j<m ;j++){


            if(M[j][i] > max){
                max = how_many_digits(M[j][i]);
            }
    }

    columns[i] = max;
    max = 1;

    }
}

void print_matriz(int m, long long int M[30][30], int n){

    int sizes[30];

    get_column_max_size(sizes, m, M);

    printf("Quadrado da matriz #%i:\n", n);

     for(int i = 0; i<m ;i++){
         for(int j = 0; j<m ;j++){
             printf("%*lli ", sizes[j],M[i][j]);

     }
            printf("\n");
     }
}

void read_and_square(int m, long long int M[30][30]) {



    for (int i = 0; i < m; i++) {
  
        for (int j = 0; j < m; j++) {
            scanf("%lli", &M[i][j]);
            M[i][j]=M[i][j]*M[i][j];
        }
    }

    

}
int main(){

    long long int matriz[30][30];


    int matriz_numbers;
    int m;


    scanf("%i", &matriz_numbers);

    for(int i=0; i< matriz_numbers; i++){
        scanf("%i", &m);
        read_and_square(m,matriz);
        print_matriz(m,matriz, i + 4);
        printf("\n");
    }


    
    
    return 0;
}