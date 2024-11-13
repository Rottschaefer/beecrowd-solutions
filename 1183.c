#include <stdio.h>

void calc(){

    char op;

    scanf("%c", &op);

    double res = 0;



    double actual = 0;
    
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf", &actual);

            if(j > i){
                
                    res += actual;
            }
        }
    }

   if(op == 'S'){
        printf("%.1lf\n", res);  
    }
    else if(op == 'M'){
        printf("%.1lf\n", res / 66.0);  
    }

    
}

int main(){

    calc();

    return 0;

}