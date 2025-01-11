#include <stdio.h>
#include <stdlib.h>

typedef struct ilha{
    char nome[31];
    int envia;
    int recebe;
    struct ilha* prox;
}Ilha;


void copy_string(char* fonte, char* destino){

    int i = 0;
    for (i; fonte[i] != '\0'; i++)
    {
        destino[i] = fonte[i];
    }

    destino[i] = '\0';
}

int compare_string(char* a, char* b){

   
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    // Ambas devem terminar ao mesmo tempo
    return a[i] == b[i];

}



char** ilhas_na_frase(char* frase){
    int i = 0;

    char* ilha1 = (char*)malloc(sizeof(char)*31);
    char* ilha2 = (char*)malloc(sizeof(char)*31);

    for (i; frase[i] != ' '; i++)
    {
        (ilha1)[i] = frase[i];
        
    }

    ilha1[i] = '\0';


    int k = 0;

    for (i = i + 4; frase[i] != '\0'; i++)
    {
        ilha2[k] = frase[i];
        k++;
    }

    
    ilha2[k] = '\0';

    char** ilhas = (char**)malloc(sizeof(char**)*2);

    ilhas[0] = ilha1;
    ilhas[1] = ilha2;

    return ilhas;
}

Ilha* ilha_ja_existe(Ilha* lista, char* nome){
    while (lista != NULL)
    {
        if(compare_string(lista->nome, nome)){
            return lista;
        }

        lista = lista->prox;
    }

    return NULL;
}

Ilha* add_ilhas(char* frase, Ilha* lista, int* output){
    char** ilhas = ilhas_na_frase(frase);
 

    Ilha* ilha_fonte = ilha_ja_existe(lista, ilhas[0]);
    Ilha* ilha_destino = ilha_ja_existe(lista, ilhas[1]);

    if(ilha_fonte != NULL){
        ilha_fonte->envia += 1;
        if(ilha_fonte->envia > 1){
            *output = 2; //Not a function
        }
    }
    else{
        ilha_fonte = (Ilha*)malloc(sizeof(Ilha));
        copy_string(ilhas[0], ilha_fonte->nome);
        ilha_fonte->envia = 1;
        ilha_fonte->recebe = 0;
        ilha_fonte->prox = lista;
        lista = ilha_fonte;
    }

    if(ilha_destino != NULL){
        ilha_destino->recebe += 1;
        if(ilha_destino->recebe > 1 && *output != 2){
            *output = 1; //Not invertible
        }
    }
    else{
        ilha_destino = (Ilha*)malloc(sizeof(Ilha));
        copy_string(ilhas[1], ilha_destino->nome);
        ilha_destino->envia = 0;
        ilha_destino->recebe = 1;
        ilha_destino->prox = lista;
        lista = ilha_destino;
    }

    free(ilhas[0]);
    free(ilhas[1]);
    free(ilhas);



    return lista;
}


int main(){

    Ilha* lista_ilhas = NULL;

    int* output = malloc(sizeof(int));

    *output = 0;

    int n;

    scanf("%d", &n);

    char frase[66];


    while (n!=0){
        for (int i = 0; i < n; i++)
        {
        scanf(" %[^\n]", frase);
        lista_ilhas = add_ilhas(frase, lista_ilhas, output);
        }
        
        switch (*output)
            {
            case 0:
                printf("Invertible.\n");
                break;
            
            case 1:
                printf("Not invertible.\n");
                break;

            case 2:
                printf("Not a function.\n");
                break;

            }

            for (int i = 0; lista_ilhas != NULL; i++)
            {
                lista_ilhas = lista_ilhas->prox;
                free(lista_ilhas);
            }

        *output = 0;
            
        scanf("%d", &n);
    }
    
    free(output);
    return 0;
}