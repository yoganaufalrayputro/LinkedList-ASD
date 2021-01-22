#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype     info;
    address     next;
} ElmtList;

typedef struct {
    address    first;
} List;


//SELEKTOR
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info


bool isEmpty (List L){
    return First(L)==NULL;
}

void createList (List *L){
    First(*L) = NULL;
}

address alokasi (infotype X){
    address NewElmt = address(malloc(sizeof(ElmtList)));
    if( NewElmt==NULL){
        return NULL;
    }

    Info(NewElmt)=X ;
    Next(NewElmt)=NULL;
    return NewElmt;

}

void dealokasi (address P){
    free(P);
}

void InsertFirst (List *L, infotype x){
    address NewElmt = alokasi (x);
    address P=First(*L);

    if(isEmpty(*L)) {
        First(*L) = NewElmt;
        Next(NewElmt) = First(*L);
    } else {
        Next(NewElmt) = First(*L);

        while(Next(P)!=First(*L)) {
            P = Next(P);
        }
        Next(P) = NewElmt;
        First(*L)=NewElmt;
    }

}

void InsertAfter (address Prec, infotype x) {
    address newElmt = alokasi(x);

    Next(newElmt)=Next(Prec);
    Next(Prec)=newElmt;

}

void InsertLast (List *L, infotype x) {
    address New=alokasi(x);
    address P = First(*L);

    if(isEmpty(*L)) {
        InsertFirst(L,x);
    }else{
        while(Next(P)!= First(*L)){
               P = Next(P);
          }
        Next(P)=New;
        Next(New)= First(*L);
    }
}

void printInfo (List L) {

    if(!isEmpty(L)) {
        address temp = First(L);
        while(Next(temp)!=First(L)) {
            cout << Info(temp)<< ", ";
            temp = Next(temp);
        }
        cout << Info(temp);
    }

}

void DeleteFirst (List *L) {
    address P = First(*L);
    address temp;

    if(!isEmpty(*L)){

        while(Next(P)!= First(*L)){
               P = Next(P);
          }
          if(Next(P)== P){
            Next(P)=NULL;
            dealokasi(P);
        }
          temp = First(*L);
          First(*L)=Next(First(*L));
        Next(P)=First(*L);
        temp=NULL;
        dealokasi(temp);
    }
}
void deleteAfter(address *pred){
        address p = Next(*pred);
        Next(*pred) = Next(p);
        Next(p) = NULL;
        dealokasi(p);
}

void DeleteLast (List *L) {
    address P = First(*L);
    address temp;
    if(!isEmpty(*L)){
        while(Next(P)!= First(*L)){
            temp=P;
            P = Next(P);
          }
          if(P == (*L).first) {
              DeleteFirst(L);
        }else{
          Next(temp)= First(*L);
          P=NULL;

        dealokasi(P);
        }
    }
}
infotype max (List L){
    int max = 0;
    address P = First(L);
    while(Next(P)!=First(L)){
        if(max<Info(P)) max=Info(P);
        P=Next(P);
    }
    if(max<Info(P)) max=Info(P);
    return max;
}
infotype min (List L){
    int min = 99999;
    address P = First(L);
    while(Next(P)!=First(L)){
        if(min>Info(P)) min=Info(P);
        P=Next(P);
    }
    if(min>Info(P)) min=Info(P);
    return min;
}
int main () {
    List L;
    createList(&L);
    int n,x,mins=99999, maxs=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        InsertLast(&L, x);
    }
    maxs=max(L);
    mins=min(L);
    cout<<maxs<<endl<<mins;
    return 0;

}
