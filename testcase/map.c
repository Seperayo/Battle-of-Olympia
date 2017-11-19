#include <stdio.h>
#include "boolean.h"
#include "map.h"
#include "point.h"
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include "pcolor.h"
#include <stdlib.h>
#include <time.h>

void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;
}

void InitializeMap (MATRIKS * M) {
	int B,K,i,j;
	B = NBrsEff(*M);
	K = NKolEff(*M);

	for (i=0;i<=B;i++) {
		for (j=0;j<=K;j++) {
			Elmt(*M,i,j).UNITINFO.TYP = EMP;
			Elmt(*M,i,j).UNITINFO.P = -1;
			Elmt(*M,i,j).BLDINFO.TYP = EMPB;
			Elmt(*M,i,j).BLDINFO.ID = -1;
		}
	}
	
	/* Player 1 */
	Elmt(*M,B-2,1).UNITINFO.P = 1;
	Elmt(*M,B-2,1).UNITINFO.TYP = KNG;
	Elmt(*M,B-2,1).UNITINFO.RNGTYP = MELEE;
	Elmt(*M,B-2,1).UNITINFO.PRB = PRB_KNG;
	Elmt(*M,B-2,1).UNITINFO.CHN = true;
	Elmt(*M,B-2,1).UNITINFO.PRC = PRC_OF_KNG;
	Elmt(*M,B-2,1).UNITINFO.LOC.X = B-2;
	Elmt(*M,B-2,1).UNITINFO.LOC.Y = 1;
	Elmt(*M,B-2,1).UNITINFO.MOVEPTS = MAX_MOVE_KNG;
	Elmt(*M,B-2,1).UNITINFO.MAXMOVE = MAX_MOVE_KNG;
	Elmt(*M,B-2,1).UNITINFO.ATK = ATK_KNG;
 	Elmt(*M,B-2,1).UNITINFO.HP = MAX_HP_KNG;
 	Elmt(*M,B-2,1).UNITINFO.MAXHP = MAX_HP_KNG;

 	Elmt(*M,B-2,1).BLDINFO.ID = 1;
 	Elmt(*M,B-2,1).BLDINFO.LOC.X = B-2;
 	Elmt(*M,B-2,1).BLDINFO.LOC.Y = 1;
 	Elmt(*M,B-2,1).BLDINFO.TYP = TWR;

 	Elmt(*M,B-2,0).BLDINFO.ID = 1;
 	Elmt(*M,B-2,0).BLDINFO.LOC.X = B-2;
 	Elmt(*M,B-2,0).BLDINFO.LOC.Y = 0;
 	Elmt(*M,B-2,0).BLDINFO.TYP = CST;

 	Elmt(*M,B-2,2).BLDINFO.ID = 1;
 	Elmt(*M,B-2,2).BLDINFO.LOC.X = B-2;
 	Elmt(*M,B-2,2).BLDINFO.LOC.Y = 2;
 	Elmt(*M,B-2,2).BLDINFO.TYP = CST;

 	Elmt(*M,B-1,1).BLDINFO.ID = 1;
 	Elmt(*M,B-1,1).BLDINFO.LOC.X = B-1;
	Elmt(*M,B-1,1).BLDINFO.LOC.Y = 1;
	Elmt(*M,B-1,1).BLDINFO.TYP = CST;

	Elmt(*M,B-3,1).BLDINFO.ID = 1;
 	Elmt(*M,B-3,1).BLDINFO.LOC.X = B-3;
	Elmt(*M,B-3,1).BLDINFO.LOC.Y = 1;
	Elmt(*M,B-3,1).BLDINFO.TYP = CST;

	/* Player 2 */
	Elmt(*M,1,K-2).UNITINFO.P = 2;
 	Elmt(*M,1,K-2).UNITINFO.TYP = KNG;
 	Elmt(*M,1,K-2).UNITINFO.RNGTYP = MELEE;
	Elmt(*M,1,K-2).UNITINFO.PRB = PRB_KNG;
	Elmt(*M,1,K-2).UNITINFO.CHN = true;
 	Elmt(*M,1,K-2).UNITINFO.PRC = PRC_OF_KNG;
 	Elmt(*M,1,K-2).UNITINFO.LOC.X = 1;
	Elmt(*M,1,K-2).UNITINFO.LOC.Y = K-2;
 	Elmt(*M,1,K-2).UNITINFO.MOVEPTS = MAX_MOVE_KNG;
 	Elmt(*M,1,K-2).UNITINFO.MAXMOVE = MAX_MOVE_KNG;
	Elmt(*M,1,K-2).UNITINFO.ATK = ATK_KNG;
 	Elmt(*M,1,K-2).UNITINFO.HP = MAX_HP_KNG;
	Elmt(*M,1,K-2).UNITINFO.MAXHP = MAX_HP_KNG;

	Elmt(*M,1,K-2).BLDINFO.ID = 2;
 	Elmt(*M,1,K-2).BLDINFO.LOC.X = 1;
 	Elmt(*M,1,K-2).BLDINFO.LOC.Y = K-2;
 	Elmt(*M,1,K-2).BLDINFO.TYP = TWR;

 	Elmt(*M,0,K-2).BLDINFO.ID = 2;
 	Elmt(*M,0,K-2).BLDINFO.LOC.X = 0;
 	Elmt(*M,0,K-2).BLDINFO.LOC.Y = K-2;
 	Elmt(*M,0,K-2).BLDINFO.TYP = CST;

 	Elmt(*M,2,K-2).BLDINFO.ID = 2;
 	Elmt(*M,2,K-2).BLDINFO.LOC.X = 2;
 	Elmt(*M,2,K-2).BLDINFO.LOC.Y = K-2;
 	Elmt(*M,2,K-2).BLDINFO.TYP = CST;

 	Elmt(*M,1,K-1).BLDINFO.ID = 2;
 	Elmt(*M,1,K-1).BLDINFO.LOC.X = 1;
	Elmt(*M,1,K-1).BLDINFO.LOC.Y = K-1;
	Elmt(*M,1,K-1).BLDINFO.TYP = CST;

	Elmt(*M,1,K-3).BLDINFO.ID = 2;
 	Elmt(*M,1,K-3).BLDINFO.LOC.X = 1;
	Elmt(*M,1,K-3).BLDINFO.LOC.Y = K-3;
	Elmt(*M,1,K-3).BLDINFO.TYP = CST;

	/* Generate Random Village */
	srand(time(0));
	int BV1 = rand() % (B-4 + 1 - 0) + 0;
	int KV1 = rand() % (2 + 1 - 0) + 0;
	int BV2 = rand() % (B + 1 - 4) + 3;
	int KV2 = rand() % (K + 1 - K-4) + K-4;
	int BV3 = rand() % (B + 1 - 0) + 0;
	int KV3 = rand() % (K-4 + 1 - 4) + 4;
	
	Elmt(*M,BV1,KV1).BLDINFO.ID = 0;
 	Elmt(*M,BV1,KV1).BLDINFO.LOC.X = BV1;
 	Elmt(*M,BV1,KV1).BLDINFO.LOC.Y = KV1;
	Elmt(*M,BV1,KV1).BLDINFO.TYP = VLG;
	
	Elmt(*M,BV2,KV2).BLDINFO.ID = 0;
 	Elmt(*M,BV2,KV2).BLDINFO.LOC.X = BV2;
 	Elmt(*M,BV2,KV2).BLDINFO.LOC.Y = KV2;
	Elmt(*M,BV2,KV2).BLDINFO.TYP = VLG;
	 
	Elmt(*M,BV3,KV3).BLDINFO.ID = 0;
 	Elmt(*M,BV3,KV3).BLDINFO.LOC.X = BV3;
 	Elmt(*M,BV3,KV3).BLDINFO.LOC.Y = KV3;
 	Elmt(*M,BV3,KV3).BLDINFO.TYP = VLG;
}

void TulisMAP (MATRIKS * M, int x, int y) {
	indeks i,j,nk,nb;
	indeks koordinatbrs = 0,koordinatkol = 0;
	
	nb = 4*NBrsEff(*M)+2; //jumlah total indeks baris untuk membuat Map 
	nk = 4*NKolEff(*M)+2; //jumlah total indeks kolom untuk membuat Map

	if(nk!=0 && nb !=0){
		for(i=1;i<=nb;i++){
			for(j=1;j<=nk;j++){
				if(i == 1){ //Mengeluarkan output angka-angka koordinat kolom
					if (j==1) {
						printf("  ");
					}
					if((j-1)%4 == 3){
						printf("%d",koordinatkol);
						if(koordinatkol/10 > 0){
							j++;
						}
						koordinatkol++;
					}
					else{
						printf(" ");
					}
				} else {
					// Menuliskan angka koordinat baris
					if( ((i-1)%4 == 3) && (j == 1) ){
						if (koordinatbrs<10) {
							printf("%d  ",koordinatbrs);
						} else {
							printf("%d ",koordinatbrs);
						}
						koordinatbrs++;
					}
					// Membentuk * di dalam MAP
					else if( (((i-1)%4 == 1) && (j!=1))  || ((j-1)%4 == 1) || (j == nk) || (i == nb) ){
						if ((i==nb)&&(j==1)) {
							printf("   ");
						}
						printf("*");
					}
					// Menuliskan Jenis Building
					else if ( (((j-1)%4 == 3) && ((i-1)%4 == 2)) ) {
						if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.ID == 1) {
							if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.TYP == TWR) {
								print_red('T');
							} else if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.TYP == CST) {
								print_red('C');
							} else if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.TYP == VLG) {
								printf("V");
							}
						} else if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.ID == 2) {
							if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.TYP == TWR) {
								print_blue('T');
							} else if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.TYP == CST) {
								print_blue('C');
							} else if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.TYP == VLG) {
								printf("V");
							}
						} else if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.ID == 0) {
							if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.TYP == VLG) {
								printf("V");
							}
						} else if (Elmt(*M,(i-3)/4,(j-4)/4).BLDINFO.ID == -1) {
							printf(" ");
						}
					}
					//Menuliskan Jenis Unit
					else if( (((j-1)%4 == 3) && ((i-1)%4 == 3)) ){
						if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.P == 1) {
							if ( (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.LOC.X == x) && (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.LOC.Y == y) ) {
								if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == KNG) {
									print_green('K');
								} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == ARC) {
									print_green('A');
								} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == SWD) {
									print_green('S');
								} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == WHT) {
									print_green('W');
								}
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == KNG) {
								print_red('K');
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == ARC) {
								print_red('A');
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == SWD) {
								print_red('S');
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == WHT) {
								print_red('W');
							}
						} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.P == 2) {
							if ( Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.LOC.X == x && Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.LOC.Y == y ) {
								if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == KNG) {
									print_green('K');
								} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == ARC) {
									print_green('A');
								} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == SWD) {
									print_green('S');
								} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == WHT) {
									print_green('W');
								}
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == KNG) {
								print_blue('K');
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == ARC) {
								print_blue('A');
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == SWD) {
								print_blue('S');
							} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.TYP == WHT) {
								print_blue('W');
							}
						} else if (Elmt(*M,((i-4)/4),(j-4)/4).UNITINFO.P == -1) {
							printf(" ");
						}
					}
					// Kosong
					else if (j==1) {
						printf("   ");
					}
					else {
						printf(" ");
					}
				}
			}
			printf("\n");
		}
	}
}

/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/*
int main(){
	MATRIKS M;
	
	MakeMATRIKS(12,41,&M);
	InitializeMap(&M);
	TulisMAP(&M);
	
	return 0;
}
*/