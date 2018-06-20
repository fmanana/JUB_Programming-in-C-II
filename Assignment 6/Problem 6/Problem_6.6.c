/*
    JTSK-320112
    a6_p6.c
    Fezile Manana
    f.manana@jacobs-university.de
*/


/*The code adds a .txt file extension to the input files
otherwise I cannot test the output on my system*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    char filename[50];
    char buffer[64];
    int bytes, i;

    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", filename);
        getchar();
        //Adding the '.txt' extension
        FILE* file = fopen(strcat(filename, ".txt"), "rb");
        //Checking to see if file was successfully opened
        if(!file)
        {
            printf("Error opening file.\n");
            exit(1);
        }

        /*Creating a new variable to store the file name
        and remove the '.txt' extension */
        char filename2 [50];
        memcpy(filename2, filename, strlen(filename) - 4);
        filename2[strlen(filename) - 4] = '\0';
        FILE* filecopy = fopen(strcat(filename2, "_copy.txt"), "wb");
        //Checking to see if file was successfully opened
        if(!filecopy)
        {
            printf("Error opening file copy.\n");
            exit(1);
        }

        //Storing the number of bytes of the file
        //in an int
        fseek(file, 0, SEEK_END);
        bytes = ftell(file);
        fseek(file, 0, SEEK_SET);

        //loop goes until the last byte is read
        //which is the EOF char
        while(ftell(file) < bytes)
        {
            fread(&buffer, sizeof(char) * 64, 1, file);
            fwrite(&buffer, 1, bytes, filecopy);
            //Removing the last 4 characters '.txt' to print to the output
            filename[strlen(filename) - 4] = '\0';
            printf("Copied %s into %s_copy.\n", filename, filename);
        }

        fclose(file);
        fclose(filecopy);
    }

    return 0;
}