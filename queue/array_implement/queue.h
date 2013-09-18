#ifndef _Queue_h
struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty ( Queue Q );
int IsFull ( Queue Q );
Queue CreateQueue ( int MaxElements );
void DisposeQueue ( Queue Q );
void MakeEmpty ( Queue Q );
void Enqueue ( ElementType X, Queue Q );
ElementType Front ( Queue Q );
void Dequeue ( Queue Q );

#endif

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int
IsEmpty ( Queue Q )
{
    return Q->Size == 0;
}

int
IsFull ( Queue Q )
{
    return Q->Size >= Q->Capacity;
}

Queue
CreateQueue ( int MaxElements )
{
    Queue q;

    q = (Queue)malloc(sizeof(struct QueueRecord));
    assert(q);

    q->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    assert(q->Array);

    q->Capacity = MaxElements;
    MakeEmpty(q);

    return q;
}

void
DisposeQueue ( Queue Q )
{
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

void
MakeEmpty ( Queue Q )
{
    Q->Rear = 0;
    Q->Front = 1;
    Q->Size = 0;
}
void
Enqueue ( ElementType X, Queue Q )
{
    assert(!IsFull(Q));
    Q->Array[Q->Rear = Q->Rear == Q->Capacity - 1 ? 0 : Q->Rear + 1] = X;
    (Q->Size)++;
}

ElementType
Front (Queue Q)
{
    assert(!IsFull(Q));
    return Q->Array[Q->Front];
}

void
Dequeue ( Queue Q )
{
    assert(!IsEmpty(Q));
    Q->Front = Q->Front == Q->Capacity ? 0 : Q->Front + 1;
    (Q->Size)--;
}
