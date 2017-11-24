/* File : stackt.c */
/* implementasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "boolean.h"
#include "stackunit.h"
#include "listlinierunit.h"
#include "point.h"
#include <stdio.h>
#include "map.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S)=Nils;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return(Top(S)==Nils);
}

boolean IsOneS (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    Top(S)--;
    return(Top(S)==Nils);
}

boolean IsFullS (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return(Top(S)==MaxEl);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Unit X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)=Top(*S)+1;
    InfoTop(*S)=X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, MATRIKS * M, Unit * Y)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    Unit X;
    int Jarak;
    X = InfoTop(*S);
    Top(*S)--;

    (*Y) = InfoTop(*S);

    Jarak = Panjang((X).LOC,(*Y).LOC);
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.P = (*Y).P;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.TYP = (*Y).TYP;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.RNGTYP = (*Y).RNGTYP;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.PRC = (*Y).PRC;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.MOVEPTS = X.MOVEPTS;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.MAXMOVE = (*Y).MAXMOVE + Jarak;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.ATK = (*Y).ATK;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.HP = (*Y).HP;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.CHN = (*Y).CHN;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.PRB = (*Y).PRB;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.MAXHP = (*Y).MAXHP;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.LOC.X = (*Y).LOC.X;
    Elmt(*M,(*Y).LOC.X,(*Y).LOC.Y).UNITINFO.LOC.Y = (*Y).LOC.Y;

    Elmt(*M,(X).LOC.X,(X).LOC.Y).UNITINFO.TYP = EMP;
    Elmt(*M,(X).LOC.X,(X).LOC.Y).UNITINFO.P = -1;
}