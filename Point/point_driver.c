/*
NIM				= 13516068
Nama			= Seperayo
Tanggal			= 30 Agustus 2017
Topik Praktikum	= Pemanfaatan ADT
Deskripsi		= ADT Point
*/

#include <stdio.h>
#include "point.h"
#include "boolean.h"

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
{	
	//Algoritma
	printf("(%d,%d)",Absis(P),Ordinat(P));
}

int main()
{
	//KAMUS
	POINT P1,P2;
	int dx,dy;
	//Algoritma
	printf("Masukkan Titik 1 (x,y)\n"); BacaPOINT(&P1); 
	printf("Masukkan Titik 2 (x,y)\n"); BacaPOINT(&P2);
	printf("Titik 1 (x,y) = "); TulisPOINT(P1); printf("\n"); printf("Titik 2 (x,y) ="); TulisPOINT(P2); printf("\n");printf("\n");
	if(EQ(P1,P2)){printf("Titik 1 dan Titik 2 SAMA\n");}
	else {printf("Titik 1 dan Titik 2 TIDAK SAMA\n");}
	printf("Jarak Kedua Titik = %.2f\n", Panjang(P1,P2)); printf("\n");
	printf("Titik 1 + (1,0) = "); TulisPOINT(NextX(P1)); printf("\n");
	printf("Titik 2 + (0,1) = "); TulisPOINT(NextY(P2)); printf("\n");printf("\n");
	printf("Menggeser TITIK\n");
	printf("Masukan delta x = "); scanf ("%d", &dx);
	printf("Masukan delta y = "); scanf ("%d", &dy); printf("\n");
    Geser(&P1,dx,dy); Geser(&P2,dx,dy);
	printf("Hasil Penggeseran\n");
    printf("Titik 1  = "); TulisPOINT(P1); printf("\n");
	printf("Titik 2  = "); TulisPOINT(P2); printf("\n");printf("\n");
	printf("==PROGRAM SELESAI==");
	scanf("%d", &dx);
	return 0;
}

