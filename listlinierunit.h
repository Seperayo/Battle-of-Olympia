/* File : listlinierunit.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infounit adalah tipe bentukan dari Unit */

#ifndef listlinierunit_H
#define listlinierunit_H

#include "boolean.h"
#include "point.h"

/* Definisi constant property unit */
#define MAX_HP_ARC 29
#define MAX_HP_SWD 33
#define MAX_HP_KNG 53
#define MAX_HP_WHT 26
#define MAX_MOVE_ARC 2
#define MAX_MOVE_SWD 2
#define MAX_MOVE_KNG 2
#define MAX_MOVE_WHT 2
#define PRC_OF_ARC 17
#define PRC_OF_SWD 13
#define PRC_OF_KNG 0
#define PRC_OF_WHT 15
#define ATK_ARC 5
#define ATK_SWD 5
#define ATK_KNG 7
#define ATK_WHT 3
#define MELEE 'm'
#define RANGE 'r'

#define PRB_KNG 0.8
#define PRB_SWD 0.6
#define PRB_ARC 0.5
#define PRB_WHT 0.5

/* Character in Game */
#define KNG 'K'
#define ARC 'A'
#define SWD 'S'
#define WHT 'W'
#define EMP ' ' 	// Jika di petak ga ada unit

//tambahin konstanta INCOME
#define INCOME 5

struct tUnit{
	int MAXHP;
	int HP;
	int ATK;
	int MAXMOVE;
	int MOVEPTS; 	// Initial -> MOVEPTS = MAXMOVE
	POINT LOC;
	int PRC; 		// Price
	char RNGTYP; 	// Range type, m = melee | r = ranged
	char TYP; 		// Jenis pasukan A, S, W, K
	int P;
	boolean CHN;	// Kesempatan serang bernilai true dan false
	float PRB; 		// Chance to Attack
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
Unit SearchUnit (ListUnit L, Unit X);
Unit SearchX (ListUnit L, int X);

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