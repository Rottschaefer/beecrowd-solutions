#include <stdio.h>

int partition(long int *v, int m, int esquerda, int direita){

    int inicio = esquerda;
    long int pivo = *(v+esquerda);

    int same_mod = 0;
    int odd_even = 0;
    int both_even = 0;
    int both_odd = 0;


    while (esquerda < direita){


        while (*(v+esquerda)%m <= pivo%m && esquerda < direita)
        {   
            same_mod = *(v+esquerda)%m == pivo%m;

            odd_even = same_mod && (*(v+esquerda)%2 == 0 && pivo%2 != 0) ; //different from rigth

            both_even = same_mod && (*(v+esquerda)%2 == 0 && pivo%2 == 0)  && *(v+esquerda) > pivo;

            both_odd = same_mod && (*(v+esquerda)%2 != 0 && pivo%2 != 0) && *(v+esquerda) < pivo;


            if (odd_even || both_even || both_odd)
            {
                same_mod = 0;
                break;
            }
            
            esquerda++;
            same_mod = 0;
        }
        while (*(v+direita)%m >= pivo%m && direita > inicio)
        {   
            same_mod = *(v+direita)%m == pivo%m;

            odd_even = same_mod && (*(v+direita)%2 != 0 && pivo%2 == 0); //different from left

            both_even = same_mod && (*(v+direita)%2 == 0 && pivo%2 == 0)  && *(v+direita) < pivo;

            both_odd = same_mod && (*(v+direita)%2 != 0 && pivo%2 != 0) && *(v+direita) > pivo;

            if (odd_even || both_even || both_odd)
            {
                same_mod = 0;
                break;
            }
            
            direita--;
            same_mod = 0;
        }


        if(esquerda < direita){

            int temp = *(v+esquerda);
            *(v+esquerda) = *(v+direita);
            *(v+direita) = temp;
        }
    }


    *(v+inicio) = *(v+direita);
    *(v+direita) = pivo;

    return direita;
}

void quick_sort(long int*v, int m, int inicio, int fim){

    if(inicio >= fim){
        return;
    }

    int pivo = partition(v, m, inicio, fim);

    quick_sort(v, m, pivo+1, fim);
    quick_sort(v, m, inicio, pivo-1);


}


int main(){

    int n = 0;

    int m = 1;

    scanf("%d %d", &n, &m);

    printf("%d %d\n", n, m);

    long int v[10000];

    while (n!=0 && m!=0)
    {


         for (int i = 0; i < n; i++)
        {
            scanf("%ld", &v[i]);
        }

        quick_sort(v, m, 0, n-1);

        for (int i = 0; i < n; i++)
        {
            printf("%ld\n", *(v+i));

        }

        scanf("%d %d", &n, &m);

        printf("%d %d\n", n, m);

    }

    return 0;
}