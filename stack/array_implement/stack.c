#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;
#include "stack.h"

void printStack (Stack S);

int main (void)
{

    Stack s = CreateStack(100);

    Push( 3, s );
    Push( 4, s );
    Push( 5, s );
    Push( 6, s );

    printf("%d\n", Top(s));
    Pop(s);
    printf("%d\n", Top(s));
    Pop(s);
    printf("%d\n", Top(s));
    Pop(s);
    printf("%d\n", Top(s));
    Pop(s);
    printf("%d\n", Top(s));
    Pop(s);

    return 0;

}




