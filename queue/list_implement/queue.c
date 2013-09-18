#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;
#include "stack.h"

void printQueue (Queue Q);

int main (void)
{
    Queue q = CreateQueue();

    Enqueue( 3, q );
    Enqueue( 4, q );
    Enqueue( 5, q );
    Dequeue( q );
    Enqueue( 6, q );
    Dequeue( q );
    Enqueue( 7, q );
    Dequeue( q );
    Enqueue( 8, q );

    printQueue(q);
    return 0;

}

void printQueue ( Queue Q )
{
    PtrToNode tempCell;
    tempCell = Q;

    printf("start: \n");
    while (tempCell->Next != NULL) {
        printf("%d\n", tempCell->Next->Element);
        tempCell = tempCell->Next;
    }
}



