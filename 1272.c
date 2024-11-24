#include <stdio.h>

void secret_message(char *word){

    int new_word = 1; //If true, the next letter is the beggining of a new word

    for (int i = 0; *(word + i) != '\0'; i++)
    {
        if(new_word && *(word + i) != ' '){
            printf("%c", *(word + i));
            new_word = 0;
        }
        else if (!new_word && *(word + i) == ' ')
        {
            new_word = 1;
        }
        
    }

    printf("\n");
    

}

int main(){

    int n = 0;

    scanf("%d", &n);
    scanf("%*c");

    char word[51]; //51 because of '\0'

    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]", word);
        scanf("%*c"); //Consume the new line char

        secret_message(word);

    }
    
    
    return 0;
}