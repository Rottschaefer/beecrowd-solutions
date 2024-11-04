#include <stdio.h>

int calc(int regioes, int m, int num_pre, int num_pos, int sobra){

    if( (13 - num_pre + sobra)%m == 0 && num_pos+num_pre != regioes-1 && regioes != 13){
        return calc(regioes, m+1, 1, 0, 0);
    }
    else if(num_pos+num_pre == regioes-1 || regioes == 13){
        return m;
    }

    else{
        int x = (13 - num_pre + sobra);
        sobra = (regioes - 13 - num_pos + x%m)%m;
        num_pos += (regioes - 13 - num_pos + x%m)/m;
        num_pre += x/m;
        return calc(regioes, m, num_pre, num_pos, sobra);

    }
}

int main(){
    int regioes = -1;

    scanf("%d", &regioes);

    int m = 1;

    while(regioes != 0){
        printf("%d\n",calc(regioes, m, 1, 0, 0));
        scanf("%d", &regioes);
    }
  
    return 0;
}





