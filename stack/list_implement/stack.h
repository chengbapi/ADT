#ifndef _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty ( Stack S );
Stack CreateStack ( void );
void DisposeStack ( Stack S );
void MakeEmpty ( Stack S );
void Push ( ElementType X, Stack S );
ElementType Top ( Stack S );
void Pop ( Stack S );

#endif

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int
IsEmpty ( Stack S )
{
    return S->Next == NULL;
}

Stack
CreateStack (void)
{
    Stack tempCell;
    tempCell = (PtrToNode)malloc(sizeof(struct Node));
    assert(tempCell);

    tempCell->Next = NULL;

    MakeEmpty (tempCell);
    return tempCell;
}

void
MakeEmpty ( Stack S )
{
    assert(S);

    while (!IsEmpty(S)) {
        Pop(S);
    }
}

void
DisposeStack ( Stack S )
{

}

void
Push ( ElementType X, Stack S )
{
    PtrToNode tempCell;
    tempCell = (PtrToNode)malloc(sizeof(struct Node));
    if (tempCell == NULL) {
        printf("FatalError");
        exit;
    }
    tempCell->Element = X;

    tempCell->Next = S->Next;
    S->Next = tempCell;
}

ElementType
Top ( Stack S )
{
    assert(!IsEmpty(S));

    return S->Next->Element;
}

void
Pop ( Stack S )
{
    assert(!IsEmpty(S));

    PtrToNode tempCell;

    tempCell = S->Next;
    S->Next = S->Next->Next;
    free(tempCell);
}

