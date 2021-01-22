#include <iostream>
#include <stdlib.h>
/* Konstanta */
#define Nil NULL


using namespace std;

/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;
typedef struct tElmtQueue {
    infotype Info;
    address Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info



/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
/* Kamus Lokal */
    /* Algoritma */
    //Algortima
    *P = (address)malloc(sizeof(ElmtQueue));
    if (P != Nil) {
    Info(*P) = X;
    Next(*P) = Nil;
    }
    else
    *P = Nil;
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
bool IsEmpty (Queue Q) {
    /* Kamus Lokal */

    /* Algoritma */
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
/* Kamus Lokal */
    int count;
    address P;
    /* Algoritma */
    count=0;
    P=Head(Q);
    while(P!=Nil) {
    count=count+1;
    P=Next(P);
    }
    return(count);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q){
     /* Algoritma */
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X){
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    Alokasi(&P,X);
    if (P!=Nil) {
        if (IsEmpty(*Q)) {
            Head(*Q) = P;
        } else {
            Next(Tail(*Q)) = P;
        }
    Tail(*Q) = P;
    } /* else: alokasi gagal, Q tetap */
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil{} jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Del(Queue * Q, infotype * X){

    /* Kamus Lokal */
    address P;
    /* Algoritma */
    *X = InfoHead(*Q);
    P = Head(*Q);
    Head(*Q) = Next(Head(*Q));
    if (Head(*Q)==Nil) {
    Tail(*Q) = Nil;
    }
    Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */



void OutQueue(Queue Q){
    int X;
    while(!IsEmpty(Q)){
        Del(&Q, &X);
        cout<<X<<" ";
    }
    cout<<endl;
}


int main(){
    Queue Q;

    int N,X,bagi;
    cin>>N;
    cin>>bagi;

    CreateEmpty(&Q);

    for (int i=0;i<N;i++){
        cin>>X;
        Add (&Q,X);
    }

    for(int j=0;j<bagi;j++){
    for(int i=0;i<N/bagi;i++){
        Del(&Q, &X);
        cout<<X<<" ";
    }
    cout<<endl;
}

    return 0;
}
