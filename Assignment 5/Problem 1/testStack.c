/*
    JTSK-320112
    a5 p1.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct stack s;

    int command = 0;
    scanf("%d", &command);
    getchar();
    char item;
    s.count = 0;
    while(command != 4)
    {
        switch(command)
        {
            case 1:
                scanf("%c", &item);
                getchar();
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                empty(&s);
                break;
        }
        scanf("%d", &command);
        getchar();
    }

    if(command == 4)
    {
        printf("Quit\n");
    }
    return 0;
}