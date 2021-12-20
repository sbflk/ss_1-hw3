#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30
#define true 1
#define false 0

int gematric_value(char);
int word_gematric_val(char []);
char abtash_of_char(char);
int abtash_of_word(char [], char []);

int main()
{
    char cmd[WORD] = {0};
    char text[TXT] = {0};
    scanf("%s",cmd);
    scanf("%[^~]s",text);

    int word_val = word_gematric_val(cmd);

    printf("Gematria Sequences: ");



    char last_word[TXT] = {0};//to know what is the last word to not print extra ~
    for(int i = 1; i < strlen(text); i++)
    {
        if(gematric_value(text[i]) != 0)
        {
            int over = false;
            char word[TXT] = {0};
            for(int j = i; j < strlen(text); j++)
            {
                if(over == false)
                {
                    char tmp[2] = {0};
                    strcpy(tmp,(char[2]){text[j]});
                    strcat(word,tmp);
                    if(word_gematric_val(word) == word_val)
                    {
                        if(strlen(last_word) == 0)
                        {
                            strcpy(last_word,word);
                        }
                        else
                        {
                            printf("%s~", last_word);
                            strcpy(last_word,word);
                        }
                        over = true;
                    }
                }
            
            }   
        }
    }
    printf("%s",last_word);
    printf("\n");

    printf("Atbash Sequences: ");

    char last_word1[TXT] = {0};
    for(int i = 0; i < strlen(text); i++)
    {
        if(gematric_value(text[i]) != 0)
        {
            int over = false;
            char word[TXT] = {0};
            for(int j = i; j < strlen(text); j++)
            {
                if(over == false)
                {
                    char tmp[2] = {0};
                    strcpy(tmp,(char[2]){text[j]});
                    strcat(word,tmp);
                    if(abtash_of_word(cmd,word))
                    {
                        if(strlen(last_word1) == 0)
                        {
                            strcpy(last_word1,word);
                        }
                        else
                        {
                            printf("%s~", last_word1);
                            strcpy(last_word1,word);
                        }
                        over = true;
                    }
                }
            }
        }
        
    }
    if(strlen(last_word1) != 0)
    {
        printf("%s",last_word1);
    }
    printf("\n");




    






}



int gematric_value(char c)
{
    int val = c;
    if(val >= 65 && val <= 90){
        return val - 64;
    }
    if(val >= 97 && val <= 122){
        return val - 96;
    }
    return 0;
}

int word_gematric_val(char a [])
{
    int word_gematric_val = 0;
    for(int i = 0; i < strlen(a); i++){
        word_gematric_val += gematric_value(a[i]);
    }
    return word_gematric_val;
}

char abtash_of_char(char c)
{
    int val = c;
    if(val >= 65 && val <= 90){
        return (char)(65+(90-val));
    }
    if(val >= 97 && val <= 122){
        return (char)(97+(122-val));
    }
    return '/';

}

int abtash_of_word(char w [], char s [])
{
    char word_abtash[TXT] = {0};
    for(int i = 0; i < strlen(s); i++)
    {
        if(abtash_of_char(s[i]) != '/')
        {
            char tmp[2] = {0};
            strcpy(tmp,(char[2]){abtash_of_char(s[i])});
            strcat(word_abtash,tmp);
        }
    }
    if(strcmp(word_abtash,w) == 0)
    {
        return true;
    }
    
    int size = strlen(w);
    char r[TXT] = {0};
    for(int i = 0; i < size; i++) 
    {
        r[i] = w[size - 1 - i];
    }
    if(strcmp(word_abtash,r) == 0)
    {
        return true;
    }
    return false;
}
