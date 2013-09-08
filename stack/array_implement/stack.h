#ifndef _Stack_h
struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty ( Stack S );
int IsFull ( Stack S );
Stack CreateStack ( int MaxElements );
void DisposeStack ( Stack S );
void MakeEmpty ( Stack S );
void Push ( ElementType X, Stack S );
ElementType Top ( Stack S );
void Pop ( Stack S );

#endif

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    int Max;
    ElementType *Array;
};

int IsEmpty ( Stack S )
{
    return S->TopOfStack == -1;
}

int IsFull ( Stack S )
{
    return S->TopOfStack >= (S->Max - 1);
}

Stack CreateStack ( int MaxElements )
{
    Stack s;

    s = (Stack)malloc(sizeof(struct StackRecord));
    assert(s);

    s->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    assert(s->Array);

    s->Max = MaxElements;
    s->TopOfStack = -1;
    return s;
}
void DisposeStack ( Stack S );
void MakeEmpty ( Stack S )
{
    S->TopOfStack = -1;
}
void Push ( ElementType X, Stack S )
{
    assert(!IsFull(S));
    S->Array[++(S->TopOfStack)] = X;
}
ElementType Top ( Stack S )
{
    return S->Array[S->TopOfStack];
}
void Pop ( Stack S )
{
    --(S->TopOfStack);
}
