#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
    char item[21];
    struct lista* prox;

}Lista_de_compras;

Lista_de_compras* add_item(Lista_de_compras* lista, char item[21]){

    Lista_de_compras* atual = lista;
    Lista_de_compras* ant = NULL;

    int k;

    while(atual != NULL){
        k = strcmp(item, atual->item);
        if(k == 0){
            return lista; //Item igual, nao adicona na lista
        }
        else if(k < 0){
            break; //O novo item deve vir antes do item atual
        }
        else{
            //Item deve ficar depois do item atual
            ant = atual;
            atual = atual->prox;
        }
    }

    Lista_de_compras* novo_item = (Lista_de_compras*)malloc(sizeof(Lista_de_compras));
    strcpy(novo_item->item, item);
    novo_item->prox = atual;

    if(ant == NULL){ //Se ant = NULL, o novo item deve ficar no inicio da lista
        return novo_item;
    }
    else{ //Se nao o ant deve apontar pro novo item e retornar o inicio normal da lista
        ant->prox = novo_item;
        return lista;
    }


    
}


void print_lista(Lista_de_compras* lista){
    while(lista != NULL){
        if(lista->prox == NULL) printf("%s", lista->item);
    
        else printf("%s ", lista->item);

        lista = lista->prox;
    }
    printf("\n");
}

void free_lista(Lista_de_compras* lista){
    Lista_de_compras* ant;
    while(lista != NULL){
        ant = lista;
        free(lista);
        lista = lista->prox;
    }
}
int main(){
    Lista_de_compras* lista = NULL;

    char string[21];

    char x = ' ';

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {   

        lista = NULL;
        while(x != '\n'){
         scanf("%s", string);
         x = getchar(); //captura o \n do buffer

         lista = add_item(lista, string);
         }

        print_lista(lista);
        x = ' ';
        free_lista(lista);
    }
    
    
    return 0;
}