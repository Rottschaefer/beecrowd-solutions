#include <stdio.h>

int calc_josephus(int n, int salto){
    

    if(n == 1){
        return 1;
    }

    int x = calc_josephus(n-1, salto)+salto;


    return (x-1)%n+1;

}


int main(){
    int regioes;

    scanf("%d", &regioes);

    while(regioes != 0){

        int m = 1;

        while(calc_josephus(regioes-1, m) != 12){

            m++;
        }

        printf("%d\n",m);

        scanf("%d", &regioes);

    }

  
    return 0;
}





