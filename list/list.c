#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#include "list.h"

int main(void)
{
    List list;
    list->Next = NULL;

    int isEmpty;

    Insert( 123, list, list );
    Insert( 65, list, list );
    Insert( 25, list, list );
    isEmpty = IsEmpty(list);

    printf("isEmpty=%d\n", isEmpty);
    printf("[0]=%d\n", Retrieve(list->Next));
    printf("[1]=%d\n", Retrieve(list->Next->Next));
    printf("[2]=%d\n", Retrieve(list->Next->Next->Next));

    Delete( 123 , list );
    printf("[0]=%d\n", Retrieve(list->Next));
    printf("[1]=%d\n", Retrieve(list->Next->Next));
    printf("[2]=%d\n", Retrieve(list->Next->Next->Next));

    return 0;
}


