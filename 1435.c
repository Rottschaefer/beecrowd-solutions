#include <stdio.h>

int get_min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

void print_matrix(int ord){

    int meio = ord/2;

    int k = 1;
    int y = 1;

    for(int i=0; i<ord;i++){

        if(ord%2 != 0){
            if(i <=meio){
                y = i+1;
            }
            else{
                y--;
            }
        }
        else{
            if(i < meio){
            y = i+1;
        }
            else if( i!= meio){
                y--;
            }
        }

        for(int j=0; j<ord;j++){

            if(i != 0 && i!= ord-1){

                if(ord%2 != 0){
                    if(j<= meio){
                        k++;
                     }
                    else{
                        k--;
                    }       
                }
                else{
                    if(j < meio){
                        k++;
                     }
                    else if(j != meio){
                        k--;
                    }     
                }
                
            }
            else{
                k=1;
            }

            
      

            if(j == ord-1){
                printf("%3i\n", get_min(y, k));
            }
            else{
                printf("%3i ", get_min(y, k));
            }
            
        }
        k = 0;
    }
}

int main(){

    int ord = 1;
    while(ord != 0){
        scanf("%d", &ord);

        if(ord == 0){
            break;
        }
        print_matrix(ord);
        printf("\n");
    }


    return 0;
}