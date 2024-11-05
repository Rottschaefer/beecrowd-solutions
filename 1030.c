#include <stdio.h>

int calc_josephus(int n, int salto){
    

    if(n == 1){
        return 1;
    }

    int x = calc_josephus(n-1, salto)+salto;


    return (x-1)%n+1;

}


int main(){

    int nc;

    scanf("%d", &nc);

    int p;
    int m;

    for(int i = 0; i<nc; i++){
        scanf("%d %d", &p, &m);

        printf("Case %d: %d\n", i+1, calc_josephus(p, m));
    }
  
    return 0;
}