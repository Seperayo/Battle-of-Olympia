
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _turnqueue_H
#define _turnqueue_H

#include "gameproperty.h"
#include "boolean.h"
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include <stdlib.h>
#include "map.h"
#include "pcolor.h"

/* Konstanta */
#define Nil NULL

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;
typedef struct tElmtQueue {
	Player Info;      // sebelumnya infotype
	address Next;
} ElmtTurnQueue;    // sebelumnya ElmtQueue

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	address HEAD;
	address TAIL;
} TurnQueue;        // Sebelumnya Queue

/* Selektor */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->Info
#define Tail(Q) (Q).TAIL
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiQ (address *P, Player X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiQ (address  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsQueueEmpty (TurnQueue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbPlayer (TurnQueue Q);
/* Mengirimkan banyaknya player yang masih bermain. */

/*** Kreator ***/
void InitializeTurnQueue(TurnQueue * Q);
/* I.S. sembarang */
/* F.S. Sebuah turn queue yang kosong */

/*** Primitif Add/Delete ***/
void AddQ (TurnQueue * Q, Player X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelQ (TurnQueue * Q, Player * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

/** Primitif Game Lainnya **/
//int CurrentPlayerID(TurnQueue * Q)
/* Mengembalikan ID Player yang mendapat turn sekarang */
void ChangeTurn(TurnQueue * Q);
/* Mengganti turn ke player selanjutnya. */

#endif
