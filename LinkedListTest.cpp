#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct Node
{
	int Data;
	struct Node *next;
}Node, *PNode;
PNode MakeEmpty()
{
	PNode p = (PNode)malloc(sizeof(Node));
	p->next = 0;
	return p;
}
int Length(PNode p)
{
	int i = 0;
	PNode t = p->next;
	while (t != 0)
	{
		++i;
		t = t->next;
	}
	return i;
}
int IsEmpty(PNode p)
{
	if (p->next == 0)
		return 1;
	else 
		return 0;
}
PNode FindKth(PNode p, int position)
{
	if (position == 0)
		return p;
	else if (position > Length(p))
		return 0;
	int i = 1;
	PNode t = p->next;
	while (i < position)
	{
		t = t->next;
		++i;
	}
	return t;
}
PNode Find(PNode p, int X)
{
	PNode t = p->next;
	while (t->Data != X && t != 0)
	{
		t = t->next;
	}
	return t;
}
void Insert(PNode p, int X, int position)
{
	PNode s, t;
	t = (PNode)malloc(sizeof(Node));
	if (t == 0)
		return;
	else{
		s = FindKth(p, position - 1);
		t ->next = s->next;
		s->next = t;
		t->Data = X;
		return;
	}
}
void Delete(PNode p, int position)
{
	PNode s,t ;
	if (position > Length(p) || position < 1)
		return;
	s = FindKth(p, position - 1);
	t = s->next;
	s->next = t->next;
	free(t);
	
}
void PrintList(PNode p)
{
	if (IsEmpty(p))
		return;
	else{
		PNode t = p->next;
		while (t != 0)
		{
			printf("%d ", t->Data);
			t = t->next;
		}
		printf("\n");
		return;
	}
}
void PrintSep()
{
	printf("------------------\n");
}
int main()
{
	PNode p = MakeEmpty();
	int length = Length(p);
	printf("length of the LinkedList now is %d\n", length);
	for (int i = 0; i < N; ++i)
		Insert(p, i+10, i + 1);
	PrintList(p);
	PrintSep();
	length = Length(p);
	printf("length of the LinkedList now is %d\n", length);
	PrintSep();
	PNode t = Find(p, 12);
	printf("%d\n", t->Data);
	PrintSep();
	Delete(p, 3);
	PrintList(p);
	return 0;
}
