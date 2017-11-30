#include <stdio.h>
#include <stdlib.h>
#include "gameproperty.h"
#include "listlinierunit.h"
#include "boolean.h"
#include "point.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (ListUnit L)
/* Mengirim true jika ListUnit kosong */
{
	return(FirstUnit(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (ListUnit *L)
/* I.S. sembarang             */
/* F.S. Terbentuk ListUnit kosong */
{
	FirstUnit(*L)=Nil;
}
/****************** Manajemen Memori ******************/
addressunit Alokasi (Unit X)
/* Mengirimkan addressunit hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressunit tidak nil, dan misalnya */
/* menghasilkan P, maka InfoUnit(P)=X, NextUnit(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	addressunit P = (addressunit) malloc (sizeof(UnitList));

	if (P!=Nil) {
        InfoUnit(P) = X;
	} else {
		return Nil;
	}
	return P;
}
void Dealokasi (addressunit *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressunit Search (ListUnit L, Unit X)
/* Mencari apakah ada elemen list dengan InfoUnit(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	addressunit P;

	if (IsEmpty(L)) {
		return Nil;
	} else {
		P=FirstUnit(L);
		while ( NextUnit(P)!=Nil && (!IsUnitSama(InfoUnit(P),X))) {
			P=NextUnit(P);
		}
		if (X.TYP==InfoUnit(P).TYP) { return P; }
		else { return Nil; }
	}
}

Unit SearchUnit (ListUnit L, Unit X)
/* Mencari apakah ada elemen list dengan InfoUnit(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	addressunit P;

	if (IsEmpty(L)) {
	} else {
		P=FirstUnit(L);
		while ( NextUnit(P)!=Nil && (!IsUnitSama(InfoUnit(P),X))) {
			P=NextUnit(P);
		}
		if (X.TYP==InfoUnit(P).TYP) { return InfoUnit(P); }
	}
}

Unit SearchX (ListUnit L, int X)
{
	addressunit P;
	int i,k;

	P=FirstUnit(L);
	k=1;
	for (i=1;i<=NbElmt(L);i++) {
        if (k==X) {
			return InfoUnit(P);
		}
		P=NextUnit(P);
		k++;
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListUnit *L, Unit X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	addressunit P;

	P = Alokasi(X);
	if (P!=Nil) {
		NextUnit(P)=FirstUnit(*L);
		FirstUnit(*L)=P;
	}
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListUnit *L, Unit *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{	
	addressunit P;

	P = FirstUnit(*L);
	*X = InfoUnit(P);
	FirstUnit(*L)=NextUnit(FirstUnit(*L));
	NextUnit(P)=Nil;
	Dealokasi(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListUnit *L, addressunit P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	NextUnit(P)=FirstUnit(*L);
	FirstUnit(*L)=P;
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListUnit *L, addressunit *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P=FirstUnit(*L);
	FirstUnit(*L)=NextUnit(FirstUnit(*L));
	NextUnit(*P)=Nil;
}
void DelP (ListUnit *L, Unit X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan InfoUnit(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan InfoUnit(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	addressunit Pdel,P;

	Pdel=Nil;
	P=FirstUnit(*L);
	if (InfoUnit(P).TYP==X.TYP) {
		DelFirst(*&L,&P);
	} else if (!IsEmpty(*L)) {
		while ((InfoUnit(NextUnit(P)).TYP!=X.TYP)&&(NextUnit(NextUnit(P))!=Nil)) {
			P=NextUnit(P);
		}
		Pdel=NextUnit(P);
		if (InfoUnit(Pdel).TYP==X.TYP) {
            Pdel = NextUnit(P);
	        NextUnit(P)=NextUnit(NextUnit(P));
	        NextUnit(Pdel)=Nil;
		}
	}
	Dealokasi(&Pdel);
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (ListUnit L)
{
	addressunit P;
	int i,k;

	P=FirstUnit(L);
	k=1;
	for (i=1;i<=NbElmt(L);i++) {
        printf("%d. ",k);
        if ( InfoUnit(P).TYP == 'K' ) {
            printf("King ");
        } else if ( InfoUnit(P).TYP == 'A' ) {
            printf("Archer ");
        } else if ( InfoUnit(P).TYP == 'S' ) {
            printf("Swordsman ");
        } else if ( InfoUnit(P).TYP == 'W' ) {
            printf("White Mage ");
        }
        TulisPOINT(InfoUnit(P).LOC);
        printf(" | Health %d/%d | Movement Point : %d | Attack Chance : ",InfoUnit(P).HP,InfoUnit(P).MAXHP,InfoUnit(P).MOVEPTS);
		if (InfoUnit(P).CHN == true) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		P=NextUnit(P);
		k++;
	}
}
int NbElmt (ListUnit L)
/* Mengirimkan banyaknya unit pada list; mengirimkan 0 jika list kosong */
{
	addressunit P;
	int i;
	
	P=FirstUnit(L);
	if (IsEmpty(L)) {
		return 0;
	} else {
		i=1;
		while (NextUnit(P)!=Nil) {
			P=NextUnit(P);
			i++;
		}
		return i;
	}
}
boolean IsUnitSama(Unit X, Unit Y) {
    if ( (X.MAXHP == Y.MAXHP) && (X.HP == Y.HP) &&  (X.ATK == Y.ATK) && (X.MAXMOVE==Y.MAXMOVE) && (X.MOVEPTS == Y.MOVEPTS) && (X.PRC==Y.PRC) && (X.RNGTYP==Y.RNGTYP) && (X.TYP==Y.TYP) && (X.CHN==Y.CHN) && (X.PRB == Y.PRB) && (X.P==Y.P) && (X.LOC.X==Y.LOC.X) && (X.LOC.Y==Y.LOC.Y) ) {
        return true;
    } else {
        return false;
    }
}