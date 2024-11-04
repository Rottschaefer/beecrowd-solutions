#include <stdio.h>

void minas(int campo[], int n){

    for(int i = 0; i<n; i++){
        if(i == 0){
            printf("%d", (campo[0]+campo[1]));
        }
        
        else if(i == n-1){
            printf("%d", (campo[n-2]+campo[n-1]));
        }
        else{
            printf("%d", (campo[i-1] + campo[i]+campo[i+1]));
        }

        printf("\n");
        


    }
}

int main(){

    int n = 1;

    scanf("%d", &n);

    int campo[50];

    for(int i=0; i<n; i++){
        scanf("%d", &campo[i]);
    }



    minas(campo, n);
    return 0;
}