#include<iostream>
#include<cstdlib>
using namespace std;

typedef int infotype;
typedef struct TElmntList *address;
typedef struct TElmntList{
	infotype info;
	address next;
}Elmtlist;

struct List{
	address first;
};

#define first(L) (L).first
#define next(P) P->next
#define info(P) P->info

void CreateList(List *L){
	(*L).first = NULL;
}

bool IsEmpty(List L){
	return (first(L)==NULL);
}

address alocation(infotype x){
	address NewElmt = (Elmtlist*) malloc(sizeof(Elmtlist));
	
	info(NewElmt) = x;
	next(NewElmt) = NULL;
	
	return NewElmt;
}

void push(List *L, infotype x){
	address NewElmt = alocation(x);

	next(NewElmt) = first(*L);
	first(*L)=NewElmt;
}

void pop(List *L){
	//if((IsEmpty)) return;
	address temp = first(*L);
	first(*L) = next(temp);
	next(temp) = NULL;
	free(temp);
}

void top(List L){
	cout<<"top = "<<info(first(L))<<"\n";
}

void printStack(List *L){
	address temp = first(*L);
	cout<<"Pop =    ";
	while(temp!=NULL){
		cout<<info(temp)<<" ";
		temp=next(temp);
	}
}

int main(){
	List L;
	
	CreateList(&L);
	
	push(&L, 8);
	push(&L, 10);
	push(&L, 15);
	push(&L, 21);
	
	top(L);
	pop(&L);
	printStack(&L);
	
	return 0;
}
