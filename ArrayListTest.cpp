#include <stdio.h>
#include <stdlib.h>
#define N 5
#define MAXSIZE 20 
typedef struct ArrayList
{
	int Data[MAXSIZE];
	int Last;	
}ArrayList, *PArrayList;

PArrayList MakeEmpty()
{
	PArrayList p;
	p = (PArrayList)malloc(sizeof(ArrayList));
	if (p == 0)
		return 0;
	p->Last = -1;
	return p;
}
int Find(int X, PArrayList p)
{
	int length = p->Last;
	for (int i = 0; i < length; ++i)
	{
		if (p->Data[i] == X)
			return i;
	}
	return -1;
}
int FindKth(int position, PArrayList p)
{
	return p->Data[position-1];
}
void Insert(int X, int position, PArrayList p)
{
	if (p->Last + 1 == MAXSIZE)
		return;
	else if (position < 1 || position > p->Last + 1)
		return;
	else{
		for (int i = p->Last; i >= position - 1; --i)
			p->Data[i+1] = p->Data[i];
		p->Data[position - 1] = X;
		++(p->Last);
		return;
		
	}
}
void Delete(int position, PArrayList p)
{
	if (p == 0)
		return;
	else if (position > p->Last + 1 || position < 1)
		return;
	else{
		int length = p->Last + 1;
		for (int i = position - 1; i < length; ++i)
			p->Data[i] = p->Data[i+1];
		--(p->Last);
		return;
	}
}
void PrintList(PArrayList p)
{
	int length = p->Last+1;
	for (int i = 0; i < length; ++i)
		printf("%d ", p->Data[i]);
	printf("\n");
}
void PrintSep()
{
	printf("---------------\n");
}
int main()
{
	PArrayList p = MakeEmpty();
	for (int i = 0; i < N; ++i)
		p->Data[i] = i + 10;
	p->Last = N-1;
	PrintSep();
	PrintList(p);
	PrintSep();
	int index = Find(12, p);
	printf("12 is in %dth in ArrayList\n", index);
	PrintSep();
	int value = FindKth(4, p);
	printf("%d\n", value);
	PrintSep();
	Insert(50, 2, p);
	PrintList(p);
	PrintSep();
	Delete(3, p);
	PrintSep();
	PrintList(p);
	
	return 0;
}
