#include <stdio.h>

double calc(int n){

    if(n == 0){
        return 1.0;
    }
    return 1.0 + 1.0/(1.0+calc(n-1));
}

int main(){

    int n;

    scanf("%d", &n);

    printf("%.10lf\n", calc(n));
    return 0;
}