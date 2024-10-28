#include <stdio.h>

double sum_rec(float M[][12]){

    double sum = 0.0;
    int k = 0;

    for(int i = 7; i < 12; i++){

        for(int j = 0; j <= k; j++){

        sum += M[5-j][i] + M[6+j][i];

    }

    k++;
}

return sum;
}

double mult_rec(float M[][12]){

    double mult = 1.0;
    int k = 0;

    for(int i = 7; i < 12; i++){

        for(int j = 0; j <= k; j++){

        mult *= M[5-j][i] * M[6+j][i];

    }

    k++;
}

return mult;
}




float op_line(float matriz[][12], char op){

    switch (op)
    {
    case 'S':
        return sum_rec(matriz);
        break;
    
    case 'M':
        return mult_rec(matriz);
        break;
    }

}


int main(){

float matriz[12][12];


int size = sizeof(matriz[0])/sizeof(matriz[0][0]);

char op;

scanf("%c", &op);

for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12; j++){
    scanf("%f", &matriz[i][j]);
}
}



printf("%.1lf\n", op_line(matriz, op));

return 0;
}