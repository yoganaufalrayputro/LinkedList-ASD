#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tNode *address;
typedef struct tNode {
	infotype info;
	address left;
	address right;
} Node;

typedef address BinTree;

#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

void CreateEmpty(BinTree *P) {
	*P = NULL;
}

address Allocation(infotype X) {
	address nodeBaru;
	nodeBaru = (Node*) malloc (sizeof(Node));
	
	Akar(nodeBaru) = X;
	Left(nodeBaru) = NULL;
	Right(nodeBaru) = NULL;
	
	return nodeBaru;
}

BinTree Tree (infotype Akar, BinTree L, BinTree R) {
	BinTree T;

	T = Allocation(Akar);
	if (T != NULL) {
		Left(T) = L;
		Right(T) = R;	
	}
	return T;
}

bool IsTreeEmpty(BinTree P) {
	return (P == NULL);
}

bool IsTreeOneElmt(BinTree P) {
	if (P!=NULL) {
		return (Left(P)==NULL && Right(P)==NULL);
	} else {
		return false;
	}
}

bool IsUnerLeft(BinTree P) {
	if (P!=NULL) {
		return (Left(P)!=NULL && Right(P)==NULL);
	} else {
		return false;
	}
}

bool IsUnerRight(BinTree P) {
	if (P!=NULL) {
		return (Left(P)==NULL && Right(P)!=NULL);
	} else {
		return false;
	}
}

void InsertNum(BinTree *P, infotype X) {
	address NodeBaru;
	
	if (IsTreeEmpty(*P)) {
		*P = Tree(X, NULL, NULL);
	} else if (X<Akar(*P) && Left(*P)!=NULL) {
		InsertNum(&Left(*P), X);
	} else if (X<Akar(*P) && Left(*P)==NULL) {
		NodeBaru = Tree(X, NULL, NULL);
		Left(*P) = NodeBaru;
	} else if (X>Akar(*P) && Right(*P)!=NULL) {
		InsertNum(&Right(*P), X);
	} else if (X>Akar(*P) && Right(*P)==NULL) {
		NodeBaru = Tree(X, NULL, NULL);
		Right(*P) = NodeBaru;
	}
}

void PrintInOrder(BinTree P) {
	if (!IsTreeEmpty(P)) {
		PrintInOrder(Left(P));
		cout << Akar(P) << endl;
		PrintInOrder(Right(P));
	}
}

int NbDaun(BinTree P) {
	if (IsTreeOneElmt(P)) {
		return 1;
	} else {
		if (IsUnerLeft(P)) {
			return (NbDaun(Left(P)));
		} else if (IsUnerRight(P)) {
			return (NbDaun(Right(P)));
		} else {
			return (NbDaun(Left(P)) + NbDaun(Right(P)));
		}
	}
}

int NbElmt(BinTree P) {
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		return (1 + NbElmt(Left(P)) +NbElmt(Right(P)));
	}
}

int Tinggi(BinTree P) {
	int tLeft, tRight;
	
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		tLeft = Tinggi(Left(P));
		tRight = Tinggi(Right(P));
		
		if (tLeft > tRight) {
			return (1 + tLeft);
		} else {
			return (1 + tRight);
		}
	}
}

bool SearchTree(BinTree P, infotype X) {
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (Akar(P) == X) {
			return true;
		} else {
			return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
		}
	}
}

int LevelSearch(BinTree P, infotype X) {
	if (SearchTree(P, X)) {
		if (Akar(P) == X) {
			return 1;
		} else {
			if (X < Akar(P)) {
				return (1+LevelSearch(Left(P),X));
			} else {
				return (1+LevelSearch(Right(P),X));
			}
		}
	} else {
		return 0;
	}
}

int main() {
	BinTree PohonAngka;
	
	CreateEmpty(&PohonAngka);
	InsertNum(&PohonAngka, 7);
	InsertNum(&PohonAngka, 3);
	InsertNum(&PohonAngka, 4);	
	InsertNum(&PohonAngka, 1);
	InsertNum(&PohonAngka, 8);
	InsertNum(&PohonAngka, 9);
	InsertNum(&PohonAngka, 12);
	InsertNum(&PohonAngka, 10);
	PrintInOrder(PohonAngka);
	
	cout << endl << endl << "Jumlah daun = " << NbDaun(PohonAngka) << endl;
	cout << "Jumlah elemen = " << NbElmt(PohonAngka) << endl;
	cout << "Tinggi Pohon = " << Tinggi(PohonAngka) << endl;
	
	int AngkaDicari = 20;
	cout << endl << "Data dengan angka " << AngkaDicari;
	int hasil = LevelSearch(PohonAngka, AngkaDicari);
	if (hasil == 0) {
		cout << " tidak ada dalam pohon" << endl;
	} else {
		cout << " berada pada level ke-" << hasil << endl;
	}
	
	return 0;
}
