struct TreeNode;
typedef struct TreeNode *Position;
typedef Position SearchTree;

void MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
ElementType Retrieve( Position P );

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

void
MakeEmpty ( SearchTree T )
{
    if ( T != NULL ) {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
}

Position
Find( ElementType X, SearchTree T )
{
    if ( T == NULL ) {
        return NULL;
    }
    if ( T->Element > X ) {
        return Find( X, T->Left );
    }
    if ( T->Element < X ) {
        return Find( X, T->Right );
    }
    return T;
}

Position
FindMin( SearchTree T )
{
    if ( T->Left != NULL ) {
        return FindMin( T->Left );
    }
    return T;
}

Position
FindMax( SearchTree T )
{
    if ( T->Right != NULL ) {
        return FindMax( T->Right );
    }
    return T;
}

SearchTree
Insert( ElementType X, SearchTree T )
{
    if ( T == NULL )
    {
        T = ( SearchTree )malloc( sizeof( struct TreeNode ) );
        assert( T );
        T->Element = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else
    if ( T->Element > X )
        T->Left = Insert( X, T->Left );
    else
    if ( T->Element < X )
        T->Right = Insert( X, T->Right );
    return T;
}

SearchTree
Delete( ElementType X, SearchTree T )
{
    Position temp;

    if ( T->Element > X )
    {
        T->Left = Delete( X, T->Left );
    }
    else
    if ( T->Element < X )
    {
        T->Right = Delete( X, T->Right );
    }
    else
    if ( T->Left && T->Right )
    {
        temp = FindMin( T->Right );
        T->Element = temp->Element;
        T->Right =  Delete( X, T->Right );
    }
    else
    {
        temp = T;
        if ( T->Left == NULL )
            T = T->Right;
        else
            T = T->Left;
        free(temp);
    }
    return T;
}

ElementType
Retrieve( Position P )
{
    return P->Element;
}
