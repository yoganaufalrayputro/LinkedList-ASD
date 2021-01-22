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
	address last;
};

#define last(L) (L).last
#define first(L) (L).first
#define next(P) P->next
#define info(P) P->info

void CreateList(List *L){
	(*L).first = NULL;
	last(*L) = NULL;
}

bool IsEmpty(List L){
	return (first(L)==NULL);
}

address allocation(infotype x){
	address NewElmt = (Elmtlist*) malloc(sizeof(Elmtlist));
	
	info(NewElmt) = x;
	next(NewElmt) = NULL;
	
	return NewElmt;
}

void enqueue(List *L, infotype x){
	address NewElmt = allocation(x);
	
	if(IsEmpty(*L)) {
		first(*L) = NewElmt;
		last(*L) = NewElmt;
	} else{
		next(last(*L)) = NewElmt;
		last(*L) = NewElmt;
	}
}

void dequeue (List *L){
	address temp = first(*L);
	if(last(*L)==first(*L)) first(*L)=last(*L)=NULL;
	else {
		first(*L)=next(temp);
	}
	free(temp);
}

void printInfo(List L){
	address temp = first(L);
	while(temp != NULL){
		cout<<info(temp)<<" ";
		temp = next(temp);
	}
}

int main(){
	List L;
	CreateList(&L);
	
	enqueue(&L, 8);
	enqueue(&L, 3);
	enqueue(&L, 12);
	enqueue(&L, 7);
	
	cout<<"List : "; printInfo(L);
	
	dequeue(&L);
	
	cout<<"\nAfter Dequeue : "; printInfo(L);
}
