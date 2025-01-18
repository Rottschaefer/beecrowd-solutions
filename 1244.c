#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char item[51];
    struct lista* prox;
}Lista_strings;

Lista_strings* add_string(Lista_strings* lista, char string[51]){


    Lista_strings* novo_item = (Lista_strings*)malloc(sizeof(Lista_strings));


    strcpy(novo_item->item, string);
    novo_item->prox = NULL;

    if(lista == NULL){
        return novo_item;
    }



    Lista_strings* atual = lista;
    Lista_strings* ant = NULL;



    while (atual != NULL && strlen(atual->item)>=strlen(string))
    {   

        ant = atual;
        atual = atual->prox;
    }

    novo_item->prox = atual;

    if(ant != NULL){
        ant->prox = novo_item;
        return lista;
    }

    return novo_item;
    
}

void print_lista(Lista_strings* lista){
    while(lista != NULL){
        if(lista->prox == NULL) printf("%s", lista->item);
    
        else printf("%s ", lista->item);

        lista = lista->prox;
    }
    printf("\n");
}

void free_lista(Lista_strings* lista){

    Lista_strings* temp;
    while (lista != NULL)
    {
        temp = lista->prox;
        free(lista);
        lista = temp;
    }
    
}

int main(){

    Lista_strings* lista = NULL;

    char string[51];
    char x = ' ';

    int n;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        lista = NULL;
        while (x != '\n')
        {   
        scanf("%s", string);

        x = getchar();

        lista = add_string(lista, string);
        }

        print_lista(lista);

        free_lista(lista);

        x = ' ';

    }
    
    
    


    return 0;
}