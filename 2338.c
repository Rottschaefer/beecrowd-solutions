#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char caractere;
    struct lista* prox;
}Lista;

char morse_to_char(char* morse) {
    if (strcmp(morse, ".-") == 0) return 'a';
    else if (strcmp(morse, "-...") == 0) return 'b';
    else if (strcmp(morse, "-.-.") == 0) return 'c';
    else if (strcmp(morse, "-..") == 0) return 'd';
    else if (strcmp(morse, ".") == 0) return 'e';
    else if (strcmp(morse, "..-.") == 0) return 'f';
    else if (strcmp(morse, "--.") == 0) return 'g';
    else if (strcmp(morse, "....") == 0) return 'h';
    else if (strcmp(morse, "..") == 0) return 'i';
    else if (strcmp(morse, ".---") == 0) return 'j';
    else if (strcmp(morse, "-.-") == 0) return 'k';
    else if (strcmp(morse, ".-..") == 0) return 'l';
    else if (strcmp(morse, "--") == 0) return 'm';
    else if (strcmp(morse, "-.") == 0) return 'n';
    else if (strcmp(morse, "---") == 0) return 'o';
    else if (strcmp(morse, ".--.") == 0) return 'p';
    else if (strcmp(morse, "--.-") == 0) return 'q';
    else if (strcmp(morse, ".-.") == 0) return 'r';
    else if (strcmp(morse, "...") == 0) return 's';
    else if (strcmp(morse, "-") == 0) return 't';
    else if (strcmp(morse, "..-") == 0) return 'u';
    else if (strcmp(morse, "...-") == 0) return 'v';
    else if (strcmp(morse, ".--") == 0) return 'w';
    else if (strcmp(morse, "-..-") == 0) return 'x';
    else if (strcmp(morse, "-.--") == 0) return 'y';
    else if (strcmp(morse, "--..") == 0) return 'z';
    return '\0';
}

Lista* add_lista(Lista* lista, char c){
    Lista* novo_item = (Lista*)malloc(sizeof(Lista));
    novo_item->caractere = c;
    novo_item->prox = lista;
    
    return novo_item;
}
void code_to_morse(char codigo[1000]){

    Lista* lista = NULL;

    char caractere_atual[50] = "Teste";
    char frase[1000];
    int f = 0;
    int k = 0;
    int qtd_pontos = 0;
    int qtd_iguais = 0;
    for (int i = 0; codigo[i] != '\0'; i++){

        // printf("i+1: %c\n", codigo[i+1]);

        if(codigo[i] == '=') {
            qtd_iguais++; 
            qtd_pontos = 0;
            
        }
        else if( codigo[i] == '.'){ 
            qtd_pontos++; 
            qtd_iguais = 0;
            // printf("%c", codigo[i]);

            }

        
        if (qtd_iguais == 3){
            caractere_atual[k] = '-';
            // printf("%s\n", caractere_atual);

            qtd_iguais = 0;
            k++;
            }
        
        else if(qtd_iguais == 1 && codigo[i+1] != '='){
            caractere_atual[k] = '.';
            // printf("%s\n", caractere_atual);

            qtd_iguais = 0;
            k++;
        }
        // printf("%d ", qtd_iguais);
        // printf("%d\n", qtd_pontos);

        // printf("%s\n", caractere_atual);


        if (qtd_pontos == 7)
        {   
            qtd_pontos = 0;

            caractere_atual[k] = '\0';
            frase[f] = morse_to_char(caractere_atual);
            f++;
            frase[f] = ' ';
            f++;
            k=0;
        }
        else if ((codigo[i+1] == '\0') || (qtd_pontos == 3 && (codigo[i+1] != '.')))
        {   
            caractere_atual[k] = '\0';
            // printf("%c", morse_to_char(caractere_atual));
            frase[f] = morse_to_char(caractere_atual);
            f++;
            k=0;
        }
      
        
    }

    frase[f] = '\0';

    printf("%s\n", frase);
    
}

int main(){
    
    char word[1000];

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", word);
        code_to_morse(word);
    }
    


    return 0;
}

