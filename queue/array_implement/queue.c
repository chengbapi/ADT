#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;
#include "queue.h"

void printQueue (Queue Q);

int main (void)
{

    Queue q = CreateQueue(100);

    Enqueue( 3, q );
    Enqueue( 4, q );
    Enqueue( 5, q );
    Enqueue( 6, q );

    printf("%d\n", Front(q));
    Dequeue(q);
    printf("%d\n", Front(q));
    Dequeue(q);
    printf("%d\n", Front(q));
    Dequeue(q);
    printf("%d\n", Front(q));
    Dequeue(q);

    return 0;

}




