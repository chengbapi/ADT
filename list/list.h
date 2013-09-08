#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious ( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );
#endif

struct Node
{
    ElementType Element;
    Position Next;
};


List
MakeEmpty( List L )
{

}

int
IsEmpty( List L )
{
    return L->Next == NULL;
}

int
IsLast( Position P, List L )
{
    return P->Next == NULL;
}

Position
Find( ElementType X, List L )
{
    Position P = L->Next;

    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

void
Delete( ElementType X, List L )
{
    Position curr;
    Position prev = FindPrevious(X, L);
    if (!IsLast(prev, L)) {
        curr = prev->Next;
        prev->Next = curr->Next;
        free(curr);
    }
}

Position
FindPrevious( ElementType X, List L )
{
    Position P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void
Insert( ElementType X, List L, Position P )
{
    Position tempCell;
    tempCell = (Position)malloc(sizeof(struct Node));
    tempCell->Element = X;
    tempCell->Next = P->Next;
    P->Next = tempCell;
}

void
DeleteList( List L )
{
    Position P, tempCell;
    P = L;
    while (P != NULL) {
        tempCell = P->Next;
        free(P);
        P = tempCell;
    }
}

Position
Header( List L )
{
    return L;
}

Position
First( List L )
{
    return L->Next;
}

Position
Advance( Position P )
{
    return P->Next;
}

ElementType
Retrieve( Position P )
{
    return P ? P->Element : -1;
}



