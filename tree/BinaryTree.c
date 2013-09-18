#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;

#include "BinaryTree.h"

void PrintTree( SearchTree T, int depth);

int main(void) {
    SearchTree tree;

    tree = Insert( 10, NULL );
    Insert( 15, tree );
    Insert( 25, tree );
    Insert( 7, tree );
    Insert( 8, tree );
    Delete( 8, tree );


    PrintTree( tree, 0 );

    return 0;
}

void PrintTree( SearchTree T , int depth)
{
    int Depth = depth;
    if ( T == NULL ) {
        return;
    }

    while( depth ) {
        printf("\t");
        depth--;
    }
    printf( "%d\n", T->Element );

    if ( T->Left ) {
        PrintTree( T->Left, Depth + 1 );
    }

    if ( T->Right ) {
        PrintTree( T->Right, Depth + 1 );
    }

}
