/*
    JTSK-320112
    a6 p4.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *input, *output;
    //Create buffer of size 4. 1 for space, one for each char
    //and one for EOF
    char buffer[4];
    int result [1];
    input = fopen("chars.txt", "r");
    output = fopen("codesum.txt", "w");
    if(input == NULL)
    {
		fprintf(stderr, "Error opening 'chars.txt\n");
		exit (1);
    }
    if(output == NULL)
    {
        fprintf(stderr, "Error opneing codeum.txt\n");
        exit (1);
    }

    fread(&buffer, sizeof(char), 4, input);
    buffer[3] = 0;
    //Assigning first and third char to result
    result[0] = buffer[0] + buffer[2];
    if(fwrite(result  , sizeof(int), 1, output) != 1)
    {
        fprintf(stderr, "Error writing to file\n");
        exit (1);
    }

    fwrite(result, sizeof(int), 1, output);

    fclose(input);
    fclose(output);

    return 0;
}