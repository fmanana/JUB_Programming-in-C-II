/*
    JTSK-320112
    a6 p1.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    FILE *fp;
    char name[50];
    char word[50];
    char check[50];
    char *separators = " ,?!.\t\r\n";
    char ch = ' ';
    int count = 0;
    int wcount = 0;
    int i;

    scanf("%s",name);
    getchar();

    fp = fopen(name,"r");
    if(!fp)
    {
        fprintf(stderr,"Error opening file.\n");
        exit(1);
    }

    scanf("%s", word);
    for(i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
    getchar();

    while(ch != EOF)
    {
        ch = getc(fp);
        char* position = strchr(separators, ch);

        //If not found
        if(!position)
        {
            //setting to lower case
            check[count] = tolower(ch);
            count++;
        }

        else
        {
            //If the substring is found
            if(strcmp(word, check) == 0)
            {
                wcount++;
                count = 0;
                memset(check, 0, sizeof(check));
            }
            //If the substring is not found, reset counter to 0
            else
            {
                count = 0;
                memset(check, 0, sizeof(check));
            }
        }
    }
    printf("The file contains the word '%s' %d times\n", word, wcount);

    fclose(fp);
    return 0;
}