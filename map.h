/* MODIFIKASI DARI ADT MATRIKS */
#ifndef MAP_H
#define MAP_H

#include "boolean.h"
#include "point.h"
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include "pcolor.h"
#include <time.h>

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 8
#define BrsMax 100
#define KolMin 8
#define KolMax 100

typedef struct {
    BLD BLDINFO;
    Unit UNITINFO;
} INFO; 
typedef int indeks; /* indeks baris, kolom */
typedef INFO ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

void InitializeMap (MATRIKS * M);

void TulisMAP (MATRIKS * M, int x, int y);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis maP 3x3 (di akhir kolom dan baris akan ditambahkan bentuk * lagi)
************
* B * B * B
* U * U * U 
*   *   *   
************
* B * B*  B
* U * U * U 
*   *   *   
************
* B * B * B 
* U * U * U 
*   *   *   

*/

void TulisMAPJarak (MATRIKS * M, Unit U);
int SearchID(MATRIKS * M, int x, int y);

#endif

