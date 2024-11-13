#include <stdio.h>

int str_len(char *word){

    int count = 0;

    for (int i = 0; i < i+1; i++)
    {
        if (*(word + i) == '\0'){
            break;
        }

        count++;
    }
    
    return count;

}

void get_most_frequent_letters(int*letters){

    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if(*(letters+i)>max){
            max = *(letters+i);
        }
    }

    int most_frequent[26];
    int j = 0;

    for (int i = 0; i < 26; i++)
    {
        if(*(letters+i)==max){
            printf("%c", i+'a');
        }
    }    
}

int calc_letters(char *word){

    int letters[26] = {0};
    int base_letter = 'a';
    int letter;

    for (int i = 0; i < str_len(word); i++)
    {   

        letter = *(word+i);

        if(letter <65 || (letter > 90 && letter<97) || letter>122){
            continue;
        }

        if(letter-'a' < 0){
            base_letter = 'A';
        }
        else{
            base_letter = 'a';
        }

        letters[letter-base_letter]++;

         }
    
    get_most_frequent_letters(letters);

    return 0;
    
}



int main(){


    char word[201];

    int n = 0;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        scanf("%201[^\n]", word);
        calc_letters(word);
        puts("");
        getchar();
    }
    
    return  0;
}