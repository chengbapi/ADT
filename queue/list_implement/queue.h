#ifndef _Queue_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Queue;

int IsEmpty ( Queue Q );
Queue CreateQueue ( void );
void DisposeQueue ( Queue Q );
void MakeEmpty ( Queue Q );
void Enqueue ( ElementType X, Queue Q );
PtrToNode FindLast ( Queue Q );
ElementType Top ( Queue Q );
void Dequeue ( Queue Q );

#endif

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int
IsEmpty ( Queue Q )
{
    return Q->Next == NULL;
}

Queue
CreateQueue (void)
{
    Queue tempCell;
    tempCell = (PtrToNode)malloc(sizeof(struct Node));
    assert(tempCell);

    tempCell->Next = NULL;

    MakeEmpty (tempCell);
    return tempCell;
}

void
MakeEmpty ( Queue Q )
{
    assert(Q);

    while (!IsEmpty(Q)) {
        Dequeue(Q);
    }
}

void
Enqueue ( ElementType X, Queue Q )
{
    PtrToNode tempCell;
    tempCell = (PtrToNode)malloc(sizeof(struct Node));
    assert(tempCell);

    tempCell->Element = X;
    tempCell->Next = NULL;

    FindLast(Q)->Next = tempCell;
}

PtrToNode
FindLast ( Queue Q )
{
    while (Q->Next != NULL) {
        Q = Q->Next;
    }

    return Q;
}

void
Dequeue ( Queue Q )
{
    assert(!IsEmpty(Q));

    PtrToNode tempCell;

    tempCell = Q->Next;
    Q->Next = Q->Next->Next;
    free(tempCell);
}

