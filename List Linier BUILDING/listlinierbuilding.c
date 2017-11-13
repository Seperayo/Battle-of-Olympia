#include "gameproperty.h"
#include <stdlib.h>
#include "listlinierbuilding.h"
#include "boolean.h"
#include "point.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyB(ListBuilding L) {
/* Mengirim true jika ListBuilding kosong */
	return (FirstBuilding(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyB(ListBuilding *L){
/* I.S. sembarang             */
/* F.S. Terbentuk ListBuilding kosong */
	FirstBuilding(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressbuilding AlokasiB(BLD X){
/* Mengirimkan addressbuilding hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressbuilding tidak nil, dan misalnya */
/* menghasilkan P, maka infobuilding(P)=X, nextbuilding(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	addressbuilding P = (addressbuilding)malloc(sizeof(BLDList));
	if (P != Nil) {
		infobuilding(P)->P.ID = X.P.ID;
		//infobuilding(P).LOC = ;
		infobuilding(P)->TYP = X.TYP;
	}
	return P;
}

void DealokasiB(addressbuilding *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
	free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressbuilding SearchB(ListBuilding L, BLD X){
/* Mencari apakah ada elemen list dengan infobuilding(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
	addressbuilding P;
	if (IsEmptyB(L)) {
		P = Nil;
	} else {
		P = FirstBuilding(L);
		while ((nextbuilding(P) != Nil) && (isBLDSama(infobuilding(P), X))) {
			P = nextbuilding(P);
		}
		if (isBLDSama(infobuilding(P), X)) {
			P = Nil;
		}
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstB(ListBuilding *L, BLD X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	addressbuilding P = AlokasiB(X);
	if (P != Nil) {
		InsertFirstB(L, P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstB(ListBuilding *L, BLD *X) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
	if (IsEmptyB(*L)) {
		addressbuilding P;
		DelFirstB(L, &P);
		*X = *infobuilding(P);
	}
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstB(ListBuilding *L, addressbuilding P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	nextbuilding(P) = FirstBuilding(*L);
	FirstBuilding(*L) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstB(ListBuilding *L, addressbuilding *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	*P = FirstBuilding(*L);
	FirstBuilding(*L) = nextbuilding(FirstBuilding(*L));
	nextbuilding(*P) = Nil;
}

void DelPB(ListBuilding *L, BLD X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan infobuilding(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan infobuilding(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	addressbuilding P = SearchB(*L, X);
	if (P == FirstBuilding(*L)) {
		DelFirstB(L, &P);
	} else {
		if (P != Nil) {
			addressbuilding prev_P = FirstBuilding(*L);
			while (nextbuilding(prev_P) != P) {
				prev_P = nextbuilding(prev_P);
			}
			DelAfterB(L, &P, prev_P);
		}
	}
	DealokasiB(&P);
}

void DelAfterB(ListBuilding *L, addressbuilding *Pdel, addressbuilding Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	*Pdel = nextbuilding(Prec);
	nextbuilding(Prec) = nextbuilding(nextbuilding(Prec));
	nextbuilding(*Pdel) = Nil;
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmtB(ListBuilding L) {
/* Mengirimkan banyaknya BLD pada list; mengirimkan 0 jika list kosong */
	int count = 0;
	if (!IsEmptyB(L)) {
		count = 1;
		addressbuilding i = FirstBuilding(L);
		while (nextbuilding(i) != Nil) {
			i = nextbuilding(i);
			count++;
		}
	}
	return count;
}

boolean isBLDSama(BLD *X, BLD Y) {
	return ((X->P.ID == Y.P.ID) && (X->TYP == Y.TYP) && (X->LOC.X == Y.LOC.X) && (X->LOC.Y == Y.LOC.Y));
}