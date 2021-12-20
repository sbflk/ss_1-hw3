#include <stdio.h>
#include <string.h>

int main()
{
    char cmd;
    //char word[30];
    scanf(" %c",&cmd);

    while(cmd != ' ' && cmd != '\t' && cmd != '\n')
    {
        char c[] = {cmd};
        //strcat(word,c);
        printf("currently array: %s",c);
        printf("\n");
        if(cmd == 'a')
        {
            printf("got an a");
            printf("\n");
        }
        if(cmd == 'b')
        {
            printf("got a b");
            printf("\n");
        }
        scanf("%c",&cmd);
    }


    printf("DONE");
    printf("\n");
    while(cmd != '~')
    {
        scanf("%c",&cmd);
        char c1[] = {cmd};
        printf("currently array: %s",c1);
        printf("\n");
    }
    printf("DONE COMPLETLEY");
}