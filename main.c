#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30
#define true 1
#define false 0

int gematric_value(char);
int word_gematric_val(char []);

int main()
{
    char cmd[WORD] = {0};
    char text[TXT] = {0};
    scanf("%s",cmd);
    scanf("%[^~]s",text);

    int word_val = word_gematric_val(cmd);

    printf("Gematria Sequences: ");



    char last_word[TXT] = {0};//to know what is the last word to not print extra~
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
