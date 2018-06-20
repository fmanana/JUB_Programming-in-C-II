/*
    JTSK-320112
    a6_p5.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char filename[50];
	char name[50];
	char check[50];
	int bytes;//Number of bytes in the file
	FILE *fp;

	scanf("%s", filename);
	getchar();
	fp = fopen(filename, "r");
	if(!fp)
	{
		fprintf(stderr, "Error opening file.\n");
		exit (1);
	}

	scanf("%s", name);
	getchar();
	//Getting size of txt file and storing in size
	fseek(fp, 0, SEEK_END);
    bytes = ftell(fp);
    fseek(fp, 0, SEEK_SET);
	while(1)
	{
	    if(strcmp(name, "exit") == 0)
        {
            printf("Exiting...");
            break;
        }
		while((ftell(fp)) != bytes)
        {
            fscanf(fp, "%s", check);
            if(strcmp(name, check) == 0)
            {
                printf("Age and city of %s:\n", name);
                //This is used to get the '\n'
                fseek(fp, 1, SEEK_CUR);
                char age_city[50];
                fscanf(fp, "%s", age_city);
                fseek(fp, 1, SEEK_CUR);
                printf("%s\n", age_city);
                fscanf(fp, "%s", age_city);
                fseek(fp, 1, SEEK_CUR);
                printf("%s\n", age_city);
                fseek(fp ,0, SEEK_SET);
                break;
            }
        }
        scanf("%s", name);
        getchar();
	}

	fclose(fp);
	return 0;
}