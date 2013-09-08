#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;
#include "stack.h"

void printStack (Stack S);

int main (void)
{

    Stack s = CreateStack();

    Push( 3, s );
    Push( 4, s );
    Push( 3, s );
    Push( 4, s );
    Push( 3, s );
    Push( 4, s );

    printStack(s);
    return 0;

}

void printStack (Stack S)
{
    PtrToNode tempCell;
    tempCell = S;

    printf("start: \n");
    while (tempCell->Next != NULL) {
        printf("%d\n", tempCell->Next->Element);
        tempCell = tempCell->Next;
    }
}



