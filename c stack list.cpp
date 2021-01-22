#include <iostream>
#include <stdlib.h>
using namespace std;

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef char infotype;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address;
typedef struct tElmtStack {
    infotype Info;
    address Next;
} ElmtStack;

/* Type stack dengan ciri TOP : */
typedef struct {
    address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/*    ----- Prototype Manajemen Memori ----- */
void Alokasi (address * P, infotype X) {
    /* Kamus Lokal */

    /* Algoritma */
    (*P) = (address) malloc (sizeof (ElmtStack));
    if ((*P) != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address P) {
    /* Kamus Lokal */

    /* Algoritma */
    Next(P)=Nil;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
bool IsEmpty (Stack S) {
    /* Kamus Lokal */

    /* Algoritma */
    return (Top(S) == Nil);
}
void CreateEmpty (Stack * S) {
    /* Kamus Lokal */

    /* Algoritma */
    Top(*S) = Nil;
}
/*    ----- Operator Dasar Stack ----- */
void Push (Stack * S, infotype X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    Alokasi(&P,X);
    if (P != Nil) {
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack * S, infotype * X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Top(*S);
    *X= Info(P);
    if (!IsEmpty(*S)) {
        Top(*S)=Next(P);
        Dealokasi(P);
    }
}
void print(Stack *S){
    if(!IsEmpty(*S)){
        address temp=Top(*S);
        while(Next(temp)!=Nil){
            cout<<Info(temp)<<" ";
            temp=Next(temp);
        }cout<<Info(temp);
    }
}

int main(){
    Stack S;
    string kata;
    int n;

    CreateEmpty (&S);
    cin>>kata;

    for(int i=0; i<kata.length(); i++){
        if(kata[i]=='+' || kata[i]=='*' || kata[i]=='/' || kata[i]=='-'||kata[i]=='^'){
            Push(&S, kata[i]);
        }
        else if(kata[i]=='('){
        }else if(kata[i]==')'){
            Pop(&S,&kata[i]);
            cout<<kata[i];
        }else{
            cout<<kata[i];
        }
    }

}
