/* File : listlinierBLD.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infobuilding adalah tipe bentukan dari BLD */

#ifndef listlinierBLD_H
#define listlinierBLD_H

#include "gameproperty.h"
#include "boolean.h"

#define Nil NULL

struct tBuilding {
	int ID;
	POINT LOC;
	char TYP;
};

typedef struct tBuilding BLD;
typedef struct tBuildingList *addressbuilding;
typedef struct tBuildingList { 
	addressbuilding nextbuilding;
	BLD infobuilding;
} BLDList;

typedef struct {
	addressbuilding FirstBuilding;
} ListBuilding;

/* Definisi list : */
/* List kosong : FirstBuilding(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), nextbuilding(P) */
/* Elemen terakhir list : jika addressnya Last, maka nextbuilding(Last)=Nil */

#define infobuilding(P) (P)->infobuilding
#define nextbuilding(P) (P)->nextbuilding
#define FirstBuilding(L) (L).FirstBuilding

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyB (ListBuilding L);
/* Mengirim true jika ListBuilding kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyB (ListBuilding *L);
/* I.S. sembarang             */
/* F.S. Terbentuk ListBuilding kosong */

/****************** Manajemen Memori ******************/
addressbuilding AlokasiB (BLD X);
/* Mengirimkan addressbuilding hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressbuilding tidak nil, dan misalnya */
/* menghasilkan P, maka infobuilding(P)=X, nextbuilding(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiB (addressbuilding *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressbuilding SearchB (ListBuilding L, BLD X);
/* Mencari apakah ada elemen list dengan infobuilding(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstB (ListBuilding *L, BLD X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstB (ListBuilding *L, BLD *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstB (ListBuilding *L, addressbuilding P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstB (ListBuilding *L, addressbuilding *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelPB(ListBuilding *L, BLD X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan infobuilding(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan infobuilding(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelAfterB (ListBuilding *L, addressbuilding *Pdel, addressbuilding Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmtB (ListBuilding L);
/* Mengirimkan banyaknya BLD pada list; mengirimkan 0 jika list kosong */

boolean isBLDSama(BLD X, BLD Y);
#endif