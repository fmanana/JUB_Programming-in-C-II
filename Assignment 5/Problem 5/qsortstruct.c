/*
	JTSK-320112
	a5 p5.c
	Fezile Manana
	f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[30];
	int age;
} Person;

//Compare function for floats for qsort
int compare_floats(const void *x, const void *y)
{
	float a = *(const float *)x;
	float b = *(const float *)y;
	
	if(a < b)
		return 1;
	else if(a > b)
		return -1;
		
	return 0;
}

/**Compare function for struct, ordering the names in
 * alphabetical order
 **/
int cmp_struct_name(const void *x, const void *y)
{
	Person a = *(Person *)x;
	Person b = *(Person *)y;
	
	return (strcmp(a.name, b.name));
}

/**Compare function for struct, ordering the age in
 * increasing order
 **/
int cmp_struct_age(const void *x, const void *y)
{
	Person a = *(Person *)x;
	Person b = *(Person *)y;
	
	if(a.age < b.age)
		return -1;
	else if(a.age > b.age)
		return 1;
	
	return 0;
}


int main()
{
	int n;
	float *num;
	Person *s;
		
	scanf("%d", &n);
	
	num = (float *) malloc(sizeof(float) * n);
	s = (Person *) malloc(sizeof(Person) * n);
	
	//Checking for proper allocation
	if(s == NULL || num == NULL)
	{
		printf("Error allocating memory\n");
		exit (1);
	}
	
	//Reading floats from keyboard
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%f", &num[i]);
		getchar();
	}
	
	//Reading the names and ages for each struct
	for(i = 0; i < n; i++)
	{
	 fgets((s+i)->name, 30, stdin);
	 (s+i)->name[strlen((s+i)->name)-1] = '\0';
	 scanf("%d", &(s+i)->age);
	 getchar();
	 
	}
	
	printf("Decreasingly sorted floats:\n");
	qsort(num, n, sizeof(float), &compare_floats);
	for(i = 0; i < n; i++)
	{
		printf("%.3f", num[i]);
		if(i < n - 1)
		  printf(" ");
	}
	
	printf("\nAlphabetically sorted structs (name):\n");
	qsort(s, n, sizeof(*s), &cmp_struct_name);
	for(i = 0; i < n; i++)
	{
		printf("%s:%d", s[i].name, s[i].age);
		if(i < n - 1)
		  printf(" ");
	}
	
	printf("\nIncreasingly sorted structs (age):\n");
	qsort(s, n, sizeof(*s), &cmp_struct_age);
	for(i = 0; i < n; i++)
	{
		printf("%s:%d", s[i].name, s[i].age);
		if(i < n - 1)
		  printf(" ");
	}
	printf("\n");
	
	free(num);
	free(s);
	return 0;
}