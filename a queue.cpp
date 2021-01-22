#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int infotype;
typedef struct Node* alamat;
typedef struct Node {
    infotype x;
    alamat next;
}Gerbong;
typedef struct {
    alamat head;
    alamat tail;
}Queue;

void buat(Queue *Q) {
    Q->head= NULL;
    Q->tail= NULL;
}

alamat alokasi (infotype x) {
    alamat P = alamat(malloc(sizeof(Gerbong)));

    if(P!=NULL) {
        P->x = x;
        P->next = NULL;
    }

    return P;
}

void dealok(alamat P) {
    P->next = NULL;
    free(P);
}

void enQ(Queue *Q, infotype x) {
    alamat P = alokasi(x);
    if(P!=NULL) {
        if(Q->head==NULL && Q->tail==NULL) Q->head = P;
        else Q->tail->next=P;
        Q->tail = P;
    }
}

void deQ(Queue *Q, infotype *x) {
    if(Q->head != NULL && Q->tail != NULL){
        *x = Q->head->x;
        if(Q->head == Q->tail){
            dealok(Q->head);
            buat(Q);
            return;
        }
        alamat P = Q->head;
        Q->head = Q->head->next;
        dealok(P);
    }
}

void cetak(Queue Q) {
    alamat P = Q.head;
    cout << '[';
    if(P!=NULL) {
        while(P->next != NULL) {
            cout << P->x << ",";
            P = P->next;
        }
        cout << P->x;
    }
    cout <<"]\n";
}

int main () {
    int ambil;
       int n, a, b, c=0, d=0, e=-1, e1 = -2, e2 = -1;
       cin >> n;
       Queue Q[n];

       for(int i=0; i<n; i++) {
           buat(&Q[i]);
           cin >> a;
           c = c + a;
           for(int j=0; j<a; j++) {
               cin >> b;
               enQ(&Q[i], b);
           }
       }

       while(c>0) {
            if(d==n) {
                   cout << "X\n";
                   d=0;
            }
            int ulang = 0;
            alamat P = NULL;
            int min = 999999;
            while(ulang<n) {
                if(ulang != e && Q[ulang].head != NULL) {
                    if(Q[ulang].head->x < min){
                        e1 = ulang;
                        min = Q[ulang].head->x;
                        P = Q[ulang].head;
                    }
                }
                ulang++;
            }
            int simpan = e1;
            if(e1==e2) {
                d = d+1;
                if(d == n) {
                    e = e1;
                    e1 = -2;
                    e2 = -1;
                }
            } else {
                d = 1;
                e = -1;
                e2 = e1;
            }
            cout << P->x << endl;
            deQ(&Q[simpan], &ambil);
            c--;
       }
}
