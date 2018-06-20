/*
    JTSK-320112
    a5 p2.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

int main()
{
    struct stack s;

    long int decimal;
    scanf("%ld", &decimal);
	
    int hex;
	hex = (decimal%16);
    s.count = 0;
	
	while(decimal >= 16)
	{
		if(hex < 10)
		{
			//The + 48 is translating the char into decimal for ANSII values
			push(&s, (hex +48));
			decimal = floor(decimal/16);
			//The floor function returns the lowest int i.e. the remainder
		}
		else if(hex == 10)
		{
			push(&s, 'A');
			decimal = floor(decimal/16);
		}
		else if(hex == 11)
		{
			push(&s, 'B');
			decimal = floor(decimal/16);
		}
		else if(hex == 12)
		{
			push(&s, 'C');
			decimal = floor(decimal%16);
		}
		else if(hex == 13)
		{
			push(&s, 'D');
			decimal = floor(decimal/16);
		}
		else if(hex == 14)
		{
			push(&s, 'E');
			decimal = floor(decimal/16);
		}
		else if(hex == 15)
		{
			push(&s, 'F');
			decimal = floor(decimal/16);
		}
		
		else if(hex == 0)
		{
			push(&s, (hex + 48));
			decimal = floor(decimal/16);
		}
		
		hex = decimal%16;
	}
	
	push(&s, (decimal + 48));
	
	printf("The hexadecimal representation is:\n");
	int max, i = 0;
	max = s.count;
	//Popping elements and printing them
	while(i < max)
	{
		pop(&s);
		i++;
	}
	printf("\n");
	
	return 0;
}