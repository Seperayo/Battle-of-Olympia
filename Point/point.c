#include <math.h>
#include <stdio.h>
#include "boolean.h"
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{	
	//Kamus
	POINT P;
	//Algoritma
	Absis(P)= X;
	Ordinat(P)= Y;
	return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{	
	//Kamus
	int X,Y;
	//Algoritma
	scanf("%d %d", &X, &Y);
	*P = MakePOINT(X,Y);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{	
	//Algoritma
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{	
	//Algoritma
	Absis(P)+=1;
	return P;
}

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{	
	//Algoritma
	Ordinat(P)+=1;
	return P;
}

float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{	
	//Algoritma
	return sqrt((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2))+(Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2)));
}

POINT Geser (POINT *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{	
	//Algoritma
	Absis(*P) += deltaX;
	Ordinat(*P) += deltaY;
	return *P;
}
