#include "gameproperty.h"
#include "turnqueue.h"
#include "boolean.h"
#include <stdlib.h>

/* Prototype manajemen memori */
void AlokasiQ (addressPlayer *P, Player X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (addressPlayer) malloc(sizeof(ElmtTurnQueue));
    if (*P != Nil) {
        InfoPlayer(*P) = X;
        NextPlayer(*P) = Nil;
    }
}

void DealokasiQ (addressPlayer P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

boolean IsQueueEmpty (TurnQueue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return HeadQueue(Q) == Nil && TailQueue(Q) == Nil;
}

int NbPlayer (TurnQueue Q)
/* Mengirimkan banyaknya player yang masih bermain. */
{
    addressPlayer P = HeadQueue(Q);
    int jlh = 0;
    while (P != Nil) {
        jlh++;
        P = NextPlayer(P);
    }
    return jlh;
}

/*** Kreator ***/
void InitializeTurnQueue(TurnQueue * Q)
/* I.S. sembarang */
/* F.S. Sebuah turn queue yang kosong */
{
    HeadQueue(*Q) = Nil;
    TailQueue(*Q) = Nil;
}

/*** Primitif Add/Delete ***/
void AddQ (TurnQueue * Q, Player X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    addressPlayer P;
    AlokasiQ(&P, X);
    if (IsQueueEmpty(*Q)) HeadQueue(*Q) = P;
    else NextPlayer(TailQueue(*Q)) = P;
    TailQueue(*Q) = P;
}

void DelQ(TurnQueue * Q, Player * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    addressPlayer P = HeadQueue(*Q);
    *X = InfoHeadQueue(*Q);
    if (HeadQueue(*Q) == TailQueue(*Q)) {
        HeadQueue(*Q) = Nil;
        TailQueue(*Q) = Nil;
    } else HeadQueue(*Q) = NextPlayer(P);
    DealokasiQ(P);
}

/** Primitif Game Lainnya **/
// int CurrentPlayerID(TurnQueue * Q)
// // /* Mengembalikan ID Player yang mendapat turn sekarang */
// {
//      return InfoHeadQueue(*Q).ID;
// }

void ChangeTurn(TurnQueue * Q)
/* Mengganti turn ke player selanjutnya. */
{
    Player P;
    DelQ(Q, &P);
    AddQ(Q, P);
}