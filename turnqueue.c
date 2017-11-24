#include "gameproperty.h"
#include "turnqueue.h"
#include "boolean.h"
#include <stdlib.h>
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include "point.h"
#include "map.h"
#include "pcolor.h"
#include <stdio.h>

/* Prototype manajemen memori */
void AlokasiQ (address *P, Player X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (address) malloc(sizeof(ElmtTurnQueue));
    if (*P != Nil) {
        Info(*P).ID = X.ID;
        Next(*P) = Nil;
    }
}

void DealokasiQ (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

boolean IsQueueEmpty (TurnQueue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return Head(Q) == Nil && Tail(Q) == Nil;
}

int NbPlayer (TurnQueue Q)
/* Mengirimkan banyaknya player yang masih bermain. */
{
    address P = Head(Q);
    int jlh = 0;
    while (P != Nil) {
        jlh++;
        P = Next(P);
    }
    return jlh;
}

/*** Kreator ***/
void InitializeTurnQueue(TurnQueue * Q)
/* I.S. sembarang */
/* F.S. Sebuah turn queue yang kosong */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/*** Primitif Add/Delete ***/
void AddQ (TurnQueue * Q, Player X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    address P;
    AlokasiQ(&P, X);
    if (IsQueueEmpty(*Q)) Head(*Q) = P;
    else Next(Tail(*Q)) = P;
    Tail(*Q) = P;
}

void DelQ(TurnQueue * Q, Player * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    address P = Head(*Q);
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else Head(*Q) = Next(P);
    DealokasiQ(P);
}

/** Primitif Game Lainnya **/
int CurrentPlayerID(TurnQueue * Q)
// /* Mengembalikan ID Player yang mendapat turn sekarang */
{
     return InfoHead(*Q).ID;
}

void ChangeTurn(TurnQueue * Q)
/* Mengganti turn ke player selanjutnya. */
{
    Player P;
    DelQ(Q, &P);
    AddQ(Q, P);
}