/* File : listlinierunit.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infounit adalah tipe bentukan dari Unit */

#ifndef listlinierunit_H
#define listlinierunit_H

#include "gameproperty.h"
#include "boolean.h"

#define Nil NULL

struct tUnit{
	int MAXHP;
	int HP;
	int ATK;
	int MAXMOVE;
	int MOVEPTS; //Initial -> MOVEPTS = MAXMOVE
	POINT LOC;
	int PRC; //Price
	int RNG; //Range ATK | 1 untuk King dan Swordsman | x untuk Archer, x belum ditentukan
	char RNGTYP; //Range type, m = melee | r = ranged
	char TYP; //Jenis pasukan A, S, W, K
	int P;
	float CHN; //Chance to Attack
};

typedef struct tUnit Unit;
typedef struct tUnitlist *addressunit;
typedef struct tUnitlist { 
	Unit infounit;
	addressunit nextunit;
} UnitList;

typedef struct {
	addressunit FirstUnit;
} ListUnit;

/* Definisi list : */
/* List kosong : FirstUnit(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), NextUnit(P) */
/* Elemen terakhir list : jika addressnya Last, maka NextUnit(Last)=Nil */

#define InfoUnit(P) (P)->infounit
#define NextUnit(P) (P)->nextunit
#define FirstUnit(L) (L).FirstUnit

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (ListUnit L);
/* Mengirim true jika ListUnit kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (ListUnit *L);
/* I.S. sembarang             */
/* F.S. Terbentuk ListUnit kosong */

/****************** Manajemen Memori ******************/
addressunit Alokasi (Unit X);
/* Mengirimkan addressunit hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressunit tidak nil, dan misalnya */
/* menghasilkan P, maka InfoUnit(P)=X, NextUnit(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (addressunit *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressunit Search (ListUnit L, Unit X);
/* Mencari apakah ada elemen list dengan InfoUnit(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListUnit *L, Unit X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListUnit *L, Unit *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListUnit *L, addressunit P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListUnit *L, addressunit *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelAfter(ListUnit *L, addressunit *Pdel, addressunit Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus NextUnit(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelP (ListUnit *L, Unit X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan InfoUnit(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan InfoUnit(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (ListUnit L);
int NbElmt (ListUnit L);
/* Mengirimkan banyaknya unit pada list; mengirimkan 0 jika list kosong */
boolean IsUnitSama(Unit X, Unit Y);

#endif