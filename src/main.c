#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "boolean.h"
#include "gameproperty.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "map.h"
#include "pcolor.h"
#include "stackunit.h"
#include "turnqueue.h"
#include <time.h>
#include "gamefunction.h"
#include <math.h>
#include "loadkar.h"
#include "loadkata.h"

void Credits(){
	printf("\nKelompok Seksi Gorengan\n");
	printf("Aldo Azali........13516125\n");
	printf("Ivan Jonathan.....13516059\n");
	printf("Shevalda..........13516134\n");
	printf("Seperayo..........13516068\n");
	printf("Hafizh Budiman....13516137\n\n");
	printf("Dosen   : Bu Yani\n");
	printf("Kelas   : 2\n");
	char junk;
	scanf("%c",&junk);
	printf("\n");
}


void EmptyToEksternal(){
	FILE * pita;
	pita = fopen("input.txt","w");
	putc('.',pita);
	fclose(pita);
}

void InputToEksternal(){
	FILE * pita;
	char ch;
	scanf("%c",&ch);
	pita = fopen("input.txt","w");
	while(ch!='\n'){
		if(!(ch=='1') && !(ch=='2') && !(ch=='3') && !(ch=='4') && !(ch=='5') && !(ch=='6') && !(ch=='7') & !(ch=='8') && !(ch=='9') && !(ch=='0')){
			ch&='_';
		}
		putc(ch,pita);
		scanf("%c",&ch);
	}
	putc('.',pita);
	fclose(pita);
}

void EksternalToInput(Kata *pilihan){ 	
	STARTKATA();
	*pilihan = CKata;
}

boolean IsKataSama(Kata K1, Kata K2){
	int i;
	boolean bool=false;
	
	if(K1.Length==0 && K2.Length==0){
		bool=true;
	}
	else if(K1.Length==K2.Length){
		bool=true;
		i=1;
		while(i<=K1.Length && bool){
			if(K1.TabKata[i]!=K2.TabKata[i]){
				bool=false;
			}
			i++;
		}
	}
	return bool;
}

void SaveGame(Player P1, Player P2, Unit CurrUnit1, Unit CurrUnit2, Stack S1, Stack S2, TurnQueue Q, MATRIKS M){
	FILE * save;
	save = fopen("load.txt","w");
	int B,K,i,j;
	addressunit P;
	addressbuilding V;
	int np,nq;
	// MAP
		fprintf(save,"%d %d",NBrsEff(M),NKolEff(M));
		B = NBrsEff(M);
		K = NKolEff(M);
		fprintf(save,"\n");
		for (i=0;i<=B;i++) {
			for (j=0;j<=K;j++) {
				//List Info Unit di titik i,j
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.P);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.TYP);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.RNGTYP);
				fprintf(save,"%f ",Elmt(M,i,j).UNITINFO.PRB);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.CHN);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.PRC);
				fprintf(save,"%d ",Absis(Elmt(M,i,j).UNITINFO.LOC));
				fprintf(save,"%d ",Ordinat(Elmt(M,i,j).UNITINFO.LOC));
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.MOVEPTS);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.MAXMOVE);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.ATK);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.HP);
				fprintf(save,"%d ",Elmt(M,i,j).UNITINFO.MAXHP);
				// List Info Building di titik i,j
				fprintf(save,"%d ",Elmt(M,i,j).BLDINFO.ID);
				fprintf(save,"%d ",Elmt(M,i,j).BLDINFO.LOC.X);
				fprintf(save,"%d ",Elmt(M,i,j).BLDINFO.LOC.Y);
				fprintf(save,"%d    ",Elmt(M,i,j).BLDINFO.TYP);
			}
			fprintf(save,"\n");
		}
		//fprintf(save,"%
		
		//Mark Pemisah MAP dan PLAYER
		fprintf(save,"\n\n");
		
	// PLAYER
		//Player1
		fprintf(save,"%d ",P1.ID);
		fprintf(save,"%d ",P1.GLD);
		fprintf(save,"%d ",P1.INC);
		fprintf(save,"%d ",P1.OUT);
		fprintf(save,"\n");
		
		//ListUnitPlayer1
		P=FirstUnit(P1.UNTLST);
		np=NbElmt(P1.UNTLST);
		fprintf(save,"%d\n",np);
		for (i=1;i<=np;i++) {
			fprintf(save,"%d ",InfoUnit(P).MAXHP);
			fprintf(save,"%c ",InfoUnit(P).HP);
			fprintf(save,"%d ",InfoUnit(P).ATK);
			fprintf(save,"%d ",InfoUnit(P).MAXMOVE);
			fprintf(save,"%d ",InfoUnit(P).MOVEPTS);
			fprintf(save,"%d ",Absis(InfoUnit(P).LOC));
			fprintf(save,"%d ",Ordinat(InfoUnit(P).LOC));
			fprintf(save,"%d ",InfoUnit(P).PRC);
			fprintf(save,"%c ",InfoUnit(P).RNGTYP);
			fprintf(save,"%c ",InfoUnit(P).TYP);
			fprintf(save,"%d ",InfoUnit(P).P);
			fprintf(save,"%d ",InfoUnit(P).CHN);
			fprintf(save,"%f ",InfoUnit(P).PRB);
			fprintf(save,"\n");
			P=NextUnit(P);
		}
		//ListBuildingPlayer1
		V = FirstBuilding(P1.VLGLST);
		nq = NbElmtB(P1.VLGLST);
		fprintf(save,"%d\n",nq);
		for(i=1;i<=nq;i++){
			fprintf(save,"%d ",infobuilding(V).ID); 
			fprintf(save,"%d ",infobuilding(V).LOC.X);
			fprintf(save,"%d ",infobuilding(V).LOC.Y);
			fprintf(save,"%d ",infobuilding(V).TYP); 
			fprintf(save,"\n");
			V = nextbuilding(V);
		}
		fprintf(save,"\n\n");
		
		//Player2
		fprintf(save,"%d ",P2.ID);
		fprintf(save,"%d ",P2.GLD);
		fprintf(save,"%d ",P2.INC);
		fprintf(save,"%d ",P2.OUT);
		fprintf(save,"\n");
		
		//ListUnitPlayer1
		P=FirstUnit(P2.UNTLST);
		np=NbElmt(P2.UNTLST);
		fprintf(save,"%d\n",np);
		for (i=1;i<=np;i++) {
			fprintf(save,"%d ",InfoUnit(P).MAXHP);
			fprintf(save,"%c ",InfoUnit(P).HP);
			fprintf(save,"%d ",InfoUnit(P).ATK);
			fprintf(save,"%d ",InfoUnit(P).MAXMOVE);
			fprintf(save,"%d ",InfoUnit(P).MOVEPTS);
			fprintf(save,"%d ",Absis(InfoUnit(P).LOC));
			fprintf(save,"%d ",Ordinat(InfoUnit(P).LOC));
			fprintf(save,"%d ",InfoUnit(P).PRC);
			fprintf(save,"%c ",InfoUnit(P).RNGTYP);
			fprintf(save,"%c ",InfoUnit(P).TYP);
			fprintf(save,"%d ",InfoUnit(P).P);
			fprintf(save,"%d ",InfoUnit(P).CHN);
			fprintf(save,"%f ",InfoUnit(P).PRB);
			fprintf(save,"\n");
			P=NextUnit(P);
		}
		//ListBuildingPlayer2
		V = FirstBuilding(P2.VLGLST);
		nq = NbElmtB(P2.VLGLST);
		fprintf(save,"%d\n",nq);
		for(i=1;i<=nq;i++){
			fprintf(save,"%d ",infobuilding(V).ID); 
			fprintf(save,"%d ",infobuilding(V).LOC.X);
			fprintf(save,"%d ",infobuilding(V).LOC.Y);
			fprintf(save,"%d ",infobuilding(V).TYP); 
			fprintf(save,"\n");
			V = nextbuilding(V);
		}
		
		fprintf(save,"\n");
	// Cetak Current Unit 1
		fprintf(save,"%d ",CurrUnit1.MAXHP);
			fprintf(save,"%c ",CurrUnit1.HP);
			fprintf(save,"%d ",CurrUnit1.ATK);
			fprintf(save,"%d ",CurrUnit1.MAXMOVE);
			fprintf(save,"%d ",CurrUnit1.MOVEPTS);
			fprintf(save,"%d ",Absis(CurrUnit1.LOC));
			fprintf(save,"%d ",Ordinat(CurrUnit1.LOC));
			fprintf(save,"%d ",CurrUnit1.PRC);
			fprintf(save,"%c ",CurrUnit1.RNGTYP);
			fprintf(save,"%c ",CurrUnit1.TYP);
			fprintf(save,"%d ",CurrUnit1.P);
			fprintf(save,"%d ",CurrUnit1.CHN);
			fprintf(save,"%f",CurrUnit1.PRB);
			fprintf(save,"\n");
			
			fprintf(save,"\n");
	// Cetak Current Unit 2
			fprintf(save,"%d ",CurrUnit2.MAXHP);
			fprintf(save,"%c ",CurrUnit2.HP);
			fprintf(save,"%d ",CurrUnit2.ATK);
			fprintf(save,"%d ",CurrUnit2.MAXMOVE);
			fprintf(save,"%d ",CurrUnit2.MOVEPTS);
			fprintf(save,"%d ",Absis(CurrUnit2.LOC));
			fprintf(save,"%d ",Ordinat(CurrUnit2.LOC));
			fprintf(save,"%d ",CurrUnit2.PRC);
			fprintf(save,"%c ",CurrUnit2.RNGTYP);
			fprintf(save,"%c ",CurrUnit2.TYP);
			fprintf(save,"%d ",CurrUnit2.P);
			fprintf(save,"%d ",CurrUnit2.CHN);
			fprintf(save,"%f",CurrUnit2.PRB);
			fprintf(save,"\n");		
		
	fprintf(save,"%d\n",InfoHead(Q).ID);	
	
	putc('!',save);
	fclose(save);
	printf("Saving Success !!!\n");
	
}
/*if(!(ch=='1') && !(ch=='2') && !(ch=='3') && !(ch=='4') && !(ch=='5') && !(ch=='6') && !(ch=='7') & !(ch=='8') && !(ch=='9') && !(ch=='0')){
			ch&='_';
		}*/

int KataToAngka(LKata LCKata){
	int i,a,angka=0;
	int minus =1;
	//printf("%d\n",LCKata.Length);
	for (i=1;i<=LCKata.Length;i++){
		a = 0;
		if(LCKata.TabKata[i] != '-'){
			a = LCKata.TabKata[i] - '0';
		}
		else if (minus != -1){
			minus = -1;
		}
		//printf("%c ",LCKata.TabKata[i]);
		angka=angka*10+a;
	}
	//printf("\n%d\n",angka); untuk debugging aja kalo2 ada yang salah
	return minus*angka;
}
/* Konversi dari Kata Eksternal menjadi angka integer
*/

float KataToFloat(LKata LCKata){
	int i,minus = 1;
	long bagi = 1; //bagi sbg bilangan pembagi 10
	float a,angka=0;
	boolean koma = false;
	//printf("%d\n\n",LCKata.Length);
	for (i=1;i<=LCKata.Length;i++){
		a = 0;
		if(!koma){
			if (LCKata.TabKata[i] == '.'){
				koma = true;
			}
			else if(LCKata.TabKata[i] != '-'){
				a = LCKata.TabKata[i] - '0';
				angka=angka*10+a;
			}
			else if (minus != -1){
				minus = -1;
			}
		}
		else{
			if(LCKata.TabKata[i] != '-'){
				a = LCKata.TabKata[i]- '0';
				bagi = bagi*10;
				angka = angka + (a/bagi);
			}
		}
		//printf("%c    ",LCKata.TabKata[i]);
		//printf("%f\n",angka);
	}
	//printf("\n%d\n",angka); //untuk debugging aja kalo2 ada yang salah
	return minus*angka;
}

char KataToChar(LKata LCKATA){
	return(LCKATA.TabKata[1]);
}

void LoadGame(Player *P1, Player *P2, Unit *CurrUnit1, Unit *CurrUnit2, Stack *S1, Stack *S2, TurnQueue *Q, MATRIKS *M){
	
	LSTARTKATA();
	int B,K,i,j;
	Unit P;
	BLD V;
	int np,nq;

	// MAP
		LSTARTKATA();
		B = KataToAngka(LCKata);
		//printf("%d\n",B);
		LADVKATA();
		K = KataToAngka(LCKata);
		//printf("%d\n",K); 
		
		NBrsEff(*M) = B;
		NKolEff(*M) = K;
		
		for (i=0;i<=B;i++) {
			for (j=0;j<=K;j++) {
				//List Info Unit di titik i,j
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.P = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.P);
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.TYP = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.TYP);
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.RNGTYP = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.RNGTYP); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.PRB = KataToFloat(LCKata);
				//printf("%f ",Elmt(*M,i,j).UNITINFO.PRB); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.CHN = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.CHN); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.PRC = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.PRC); 
				LADVKATA();
				Absis(Elmt(*M,i,j).UNITINFO.LOC) = KataToAngka(LCKata);
				//printf("%d ",Absis(Elmt(*M,i,j).UNITINFO.LOC)); 
				LADVKATA();
				Ordinat(Elmt(*M,i,j).UNITINFO.LOC) = KataToAngka(LCKata);
				//printf("%d ",Ordinat(Elmt(*M,i,j).UNITINFO.LOC)); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.MOVEPTS = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.MOVEPTS); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.MAXMOVE = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.MAXMOVE); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.ATK = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.ATK); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.HP = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.HP); 
				LADVKATA();
				Elmt(*M,i,j).UNITINFO.MAXHP = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).UNITINFO.MAXHP); 
				
				// List Info Building di titik i,j
				LADVKATA();
				Elmt(*M,i,j).BLDINFO.ID = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).BLDINFO.ID); 
				LADVKATA();
				Elmt(*M,i,j).BLDINFO.LOC.X = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).BLDINFO.LOC.X); 
				LADVKATA();
				Elmt(*M,i,j).BLDINFO.LOC.Y = KataToAngka(LCKata);
				//printf("%d ",Elmt(*M,i,j).BLDINFO.LOC.Y); 
				LADVKATA();
				Elmt(*M,i,j).BLDINFO.TYP = KataToAngka(LCKata); 
				//printf("%d ",Elmt(*M,i,j).BLDINFO.TYP); 
				//printf("\n");
			}
			//printf("\n");
		}
		
		// PLAYER
		//Player1
		LADVKATA();
		(*P1).ID = KataToAngka(LCKata);
		//printf("%d ",(*P1).ID); 
		LADVKATA();
		(*P1).GLD = KataToAngka(LCKata);
		//printf("%d ",(*P1).GLD); 
		LADVKATA();
		(*P1).INC = KataToAngka(LCKata);
		//printf("%d ",(*P1).INC); 
		LADVKATA();
		(*P1).OUT = KataToAngka(LCKata);
		//printf("%d ",(*P1).OUT); 
		//printf("\n");
		
		//ListUnitPlayer1
		LADVKATA();
		np = KataToAngka(LCKata);
		//printf("%d\n",np);
		CreateEmpty(&(*P1).UNTLST);
		
		for (i=1;i<=np;i++) {
			LADVKATA();
			P.MAXHP= KataToAngka(LCKata);
			//printf("%d ",P.MAXHP);
			LADVKATA();
			P.HP = KataToChar(LCKata);
			//printf("%c ",P.HP);
			LADVKATA();
			P.ATK = KataToAngka(LCKata);
			//printf("%d ",P.ATK);
			LADVKATA();
			P.MAXMOVE = KataToAngka(LCKata);
			//printf("%d ",P.MAXMOVE);
			LADVKATA();
			P.MOVEPTS = KataToAngka(LCKata);
			//printf("%d ",P.MOVEPTS);
			LADVKATA();
			Absis(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Absis(P.LOC));
			LADVKATA();
			Ordinat(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Ordinat(P.LOC));
			LADVKATA();
			P.PRC = KataToAngka(LCKata);
			//printf("%d ",P.PRC);
			LADVKATA();
			P.RNGTYP = KataToChar(LCKata);
			//printf("%c ",P.RNGTYP);
			LADVKATA();
			P.TYP = KataToChar(LCKata);
			//printf("%c ",P.TYP);
			LADVKATA();
			P.P = KataToAngka(LCKata);
			//printf("%d ",P.P);
			LADVKATA();
			P.CHN = KataToAngka(LCKata);
			//printf("%d ",P.CHN);
			LADVKATA();
			P.PRB = KataToFloat(LCKata);
			//printf("%f ",P.PRB);
			//printf("\n");
			InsVFirst(&(*P1).UNTLST,P);
		}
		
		//ListBuildingPlayer1
		CreateEmptyB(&(*P1).VLGLST);
		LADVKATA();
		nq = KataToAngka(LCKata);
		//printf("%d\n",nq);
		for(i=1;i<=nq;i++){
			LADVKATA();
			V.ID = KataToFloat(LCKata);
			//printf("%d ",V.ID); 
			LADVKATA();
			V.LOC.X = KataToFloat(LCKata);
			//printf("%d ",V.LOC.X);
			LADVKATA();
			V.LOC.Y = KataToFloat(LCKata);
			//printf("%d ",V.LOC.Y);
			LADVKATA();
			V.TYP = KataToFloat(LCKata);
			//printf("%d ",V.TYP); 
			//printf("\n");
			InsVFirstB(&(*P1).VLGLST,V);
		}
		//printf("\n\n");
		
		//Player2
		LADVKATA();
		(*P2).ID = KataToAngka(LCKata);
		//printf("%d ",(*P2).ID); 
		LADVKATA();
		(*P2).GLD = KataToAngka(LCKata);
		//printf("%d ",(*P2).GLD); 
		LADVKATA();
		(*P2).INC = KataToAngka(LCKata);
		//printf("%d ",(*P2).INC); 
		LADVKATA();
		(*P2).OUT = KataToAngka(LCKata);
		//printf("%d ",(*P2).OUT); 
		//printf("\n");
		
		//ListUnitPlayer2
		LADVKATA();
		np = KataToAngka(LCKata);
		//printf("%d\n",np);
		CreateEmpty(&(*P2).UNTLST);
		
		for (i=1;i<=np;i++) {
			LADVKATA();
			P.MAXHP= KataToAngka(LCKata);
			//printf("%d ",P.MAXHP);
			LADVKATA();
			P.HP = KataToChar(LCKata);
			//printf("%c ",P.HP);
			LADVKATA();
			P.ATK = KataToAngka(LCKata);
			//printf("%d ",P.ATK);
			LADVKATA();
			P.MAXMOVE = KataToAngka(LCKata);
			//printf("%d ",P.MAXMOVE);
			LADVKATA();
			P.MOVEPTS = KataToAngka(LCKata);
			//printf("%d ",P.MOVEPTS);
			LADVKATA();
			Absis(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Absis(P.LOC));
			LADVKATA();
			Ordinat(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Ordinat(P.LOC));
			LADVKATA();
			P.PRC = KataToAngka(LCKata);
			//printf("%d ",P.PRC);
			LADVKATA();
			P.RNGTYP = KataToChar(LCKata);
			//printf("%c ",P.RNGTYP);
			LADVKATA();
			P.TYP = KataToChar(LCKata);
			//printf("%c ",P.TYP);
			LADVKATA();
			P.P = KataToAngka(LCKata);
			//printf("%d ",P.P);
			LADVKATA();
			P.CHN = KataToAngka(LCKata);
			//printf("%d ",P.CHN);
			LADVKATA();
			P.PRB = KataToFloat(LCKata);
			//printf("%f ",P.PRB);
			//printf("\n");
			InsVFirst(&(*P2).UNTLST,P);
		}
		
		//ListBuildingPlayer2
		CreateEmptyB(&(*P2).VLGLST);
		LADVKATA();
		nq = KataToAngka(LCKata);
		//printf("%d\n",nq);
		
		for(i=1;i<=nq;i++){
			LADVKATA();
			V.ID = KataToFloat(LCKata);
			//printf("%d ",V.ID); 
			LADVKATA();
			V.LOC.X = KataToFloat(LCKata);
			//printf("%d ",V.LOC.X);
			LADVKATA();
			V.LOC.Y = KataToFloat(LCKata);
			//printf("%d ",V.LOC.Y);
			LADVKATA();
			V.TYP = KataToFloat(LCKata);
			//printf("%d ",V.TYP); 
			//printf("\n");
			InsVFirstB(&(*P2).VLGLST,V);
		} 
		
		
		// Current Unit1
			LADVKATA();
			np = KataToAngka(LCKata);
			//printf("%d\n",np);	
			LADVKATA();
			P.MAXHP= KataToAngka(LCKata);
			//printf("%d ",P.MAXHP);
			LADVKATA();
			P.HP = KataToChar(LCKata);
			//printf("%c ",P.HP);
			LADVKATA();
			P.ATK = KataToAngka(LCKata);
			//printf("%d ",P.ATK);
			LADVKATA();
			P.MAXMOVE = KataToAngka(LCKata);
			//printf("%d ",P.MAXMOVE);
			LADVKATA();
			P.MOVEPTS = KataToAngka(LCKata);
			//printf("%d ",P.MOVEPTS);
			LADVKATA();
			Absis(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Absis(P.LOC));
			LADVKATA();
			Ordinat(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Ordinat(P.LOC));
			LADVKATA();
			P.PRC = KataToAngka(LCKata);
			//printf("%d ",P.PRC);
			LADVKATA();
			P.RNGTYP = KataToChar(LCKata);
			//printf("%c ",P.RNGTYP);
			LADVKATA();
			P.TYP = KataToChar(LCKata);
			//printf("%c ",P.TYP);
			LADVKATA();
			P.P = KataToAngka(LCKata);
			//printf("%d ",P.P);
			LADVKATA();
			P.CHN = KataToAngka(LCKata);
			//printf("%d ",P.CHN);
			LADVKATA();
			P.PRB = KataToFloat(LCKata);
			//printf("%f ",P.PRB);
			//printf("\n");
			*CurrUnit1 = P;
			
		// Current Unit 2
			LADVKATA();
			np = KataToAngka(LCKata);
			//printf("%d\n",np);	
			LADVKATA();
			P.MAXHP= KataToAngka(LCKata);
			//printf("%d ",P.MAXHP);
			LADVKATA();
			P.HP = KataToChar(LCKata);
			//printf("%c ",P.HP);
			LADVKATA();
			P.ATK = KataToAngka(LCKata);
			//printf("%d ",P.ATK);
			LADVKATA();
			P.MAXMOVE = KataToAngka(LCKata);
			//printf("%d ",P.MAXMOVE);
			LADVKATA();
			P.MOVEPTS = KataToAngka(LCKata);
			//printf("%d ",P.MOVEPTS);
			LADVKATA();
			Absis(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Absis(P.LOC));
			LADVKATA();
			Ordinat(P.LOC) = KataToAngka(LCKata);
			//printf("%d ",Ordinat(P.LOC));
			LADVKATA();
			P.PRC = KataToAngka(LCKata);
			//printf("%d ",P.PRC);
			LADVKATA();
			P.RNGTYP = KataToChar(LCKata);
			//printf("%c ",P.RNGTYP);
			LADVKATA();
			P.TYP = KataToChar(LCKata);
			//printf("%c ",P.TYP);
			LADVKATA();
			P.P = KataToAngka(LCKata);
			//printf("%d ",P.P);
			LADVKATA();
			P.CHN = KataToAngka(LCKata);
			//printf("%d ",P.CHN);
			LADVKATA();
			P.PRB = KataToFloat(LCKata);
			//printf("%f ",P.PRB);
			//printf("\n");
			*CurrUnit2 = P;
		
		
		// InitializeQueue
		InitializeTurnQueue(Q);
		AddQ(Q,*P1);
		AddQ(Q,*P2);
		
		
		LADVKATA();
		InfoHead(*Q).ID = KataToAngka(LCKata);

		
		CreateEmptyS(S1);
		CreateEmptyS(S2);
		//*CurrUnit1 = InfoUnit(FirstUnit((*P1).UNTLST));
		//*CurrUnit2 = InfoUnit(FirstUnit((*P2).UNTLST));
		Push(S1,*CurrUnit1);
		Push(S2,*CurrUnit2);
		printf("loading..\n");
		
		
		printf("Load Previous Games Success !!\n");
		printf("Press Any Key to Continue \n");
		char junk;
		scanf("%c",&junk);
}


void Display(){
    printf("                                --------------\n");
	printf("                                  Welcome to\n");
    printf("                                --------------\n");
	printf("           _-_ _,,           ,    ,  ,,               /\\             \n");
    printf("              -/  )    _    ||   ||  ||              ||              \n");
    printf("             ~||_<    < \\, =||= =||= ||  _-_        =||=  /'\\\\ ,._-_ \n");
    printf("              || \\\\   /-||  ||   ||  || || \\\\        ||  || ||  ||  \n");
    printf("              ,/--|| (( ||  ||   ||  || ||/          ||  || ||  ||  \n");
    printf("             _--_-'   \\/\\\\  \\\\,  \\\\, \\\\ \\\\,/         \\\\, \\\\,/   \\\\, \n");
    printf("           ( \n");

    printf("                     __ \n");
    printf("                   ,-||-,   ,, \n");
    printf("                  ('|||  )  ||                        '   _ \n");
    printf("                 (( |||--)) || '\\\\/\\\\ \\\\/\\\\/\\\\ -_-_  \\\\  < \\, \n");
    printf("                 (( |||--)) ||  || ;' || || || || \\\\ ||  /-|| \n");
    printf("                  ( / |  )  ||  ||/   || || || || || || (( || \n");
    printf("                   -____-   \\\\  |/    \\\\ \\\\ \\\\ ||-'  \\\\  \\/\\\\ \n");
    printf("                               (               |/ \n");
    printf("                                -_-            ' \n");
}

void Menu(int *option){
	Kata pilihan;
	Kata start,load,exit,satu,dua,tiga;
	Kata credit,empat;
	char junk;
	
	//BAGIAN ASSIGN STRING PILIHAN
	start.TabKata[1]='S';
	start.TabKata[2]='T';
	start.TabKata[3]='A';
	start.TabKata[4]='R';
	start.TabKata[5]='T';
	start.Length=5;
	load.TabKata[1]='L';
	load.TabKata[2]='O';
	load.TabKata[3]='A';
	load.TabKata[4]='D';
	load.Length=4;
	exit.TabKata[1]='E';
	exit.TabKata[2]='X';
	exit.TabKata[3]='I';
	exit.TabKata[4]='T';
	exit.Length=4;
	credit.TabKata[1]='C';
	credit.TabKata[2]='R';
	credit.TabKata[3]='E';
	credit.TabKata[4]='D';
	credit.TabKata[5]='I';
	credit.TabKata[6]='T';
	credit.Length=6;
	
	satu.TabKata[1]='1';
	satu.Length=1;
	dua.TabKata[1]='2';
	dua.Length=1;
	tiga.TabKata[1]='3';
	tiga.Length=1;
	empat.TabKata[1]='4';
	empat.Length=1;

	scanf("%c",&junk); // Membuang karakter enter berlebihan dari user agar Input menu tidak error
	//BAGIAN MENU PROGRAM
	printf("********************\n");
	printf("* START........[1] *\n* LOAD.........[2] *\n* CREDIT.......[3] *\n* EXIT.........[4] *\n"); //Menu Pilihan
	printf("********************\n");
	printf("\nGame Command : ");
	InputToEksternal();
	EksternalToInput(&pilihan);
	if(IsKataSama(start,pilihan) || IsKataSama(satu,pilihan)){
		printf("\nStarting Game\n\n");
		*option = 1;
	}
	else if(IsKataSama(load,pilihan) || IsKataSama(dua,pilihan)){
		printf("\nLoading Previous Game\n\n");
		*option = 2;
	}
	else if(IsKataSama(credit,pilihan) || IsKataSama(tiga,pilihan)){
		*option = 3;
	}
	else if(IsKataSama(exit,pilihan) || IsKataSama(empat,pilihan)){
		*option = 0;
	}
	else{
		printf("Input ERROR !!!\n");
		scanf("%c",&junk);
		printf("\n\n");
		Menu(option);
	}
}

void NewGame(Player *P1, Player *P2, Unit *CurrUnit1, Unit *CurrUnit2, Stack *S1, Stack *S2, TurnQueue *Q, MATRIKS *M){
	
	int B,K; //Baris , Kolom, Current Turn
	char junk;
	
	printf("* Insert Map Row Size    = ");
	scanf("%d",&B);
	scanf("%c",&junk); // Membuang karakter enter berlebihan dari user agar Input menu tidak error
	printf("* Insert Map Column Size = ");
	scanf("%d",&K);
	scanf("%c",&junk); // Membuang karakter enter berlebihan dari user agar Input menu tidak error
	
	MakeMATRIKS(B,K,M);
	InitializeMap(&(*M));
	InitializeQueue(&(*P1),&(*P2),&(*M),&(*Q));
	
	CreateEmptyS(S1);
	CreateEmptyS(S2);
	*CurrUnit1 = InfoUnit(FirstUnit((*P1).UNTLST));
	*CurrUnit2 = InfoUnit(FirstUnit((*P2).UNTLST));
	Push(S1,*CurrUnit1);
	Push(S2,*CurrUnit2);
}

void Gamein(Player *P1, Player *P2, Unit *CurrUnit1, Unit *CurrUnit2, Stack *S1, Stack *S2, TurnQueue *Q, MATRIKS *M){
	
	// printf("Starting Game\n\n");
	
	/*Player RP1 = *P1, RP2 = *P2;
				MATRIKS RM = *M;
				TurnQueue RQ = *Q; */
	
	//BAGIAN ASSIGN STRING Game Command
	Kata save, menu, move, undo, recruit, change_unit, attack, map, info, end_turn;
	char junk;

	save.TabKata[1]='S';
	save.TabKata[2]='A';
	save.TabKata[3]='V';
	save.TabKata[4]='E';
	save.Length=4;
	move.TabKata[1]='M';
	move.TabKata[2]='O';
	move.TabKata[3]='V';
	move.TabKata[4]='E';
	move.Length=4;
	undo.TabKata[1]='U';
	undo.TabKata[2]='N';
	undo.TabKata[3]='D';
	undo.TabKata[4]='O';
	undo.Length=4;
	recruit.TabKata[1]='R';
	recruit.TabKata[2]='E';
	recruit.TabKata[3]='C';
	recruit.TabKata[4]='R';
	recruit.TabKata[5]='U';
	recruit.TabKata[6]='I';
	recruit.TabKata[7]='T';
	recruit.Length=7;
	change_unit.TabKata[1]='C';
	change_unit.TabKata[2]='H';
	change_unit.TabKata[3]='A';
	change_unit.TabKata[4]='N';
	change_unit.TabKata[5]='G';
	change_unit.TabKata[6]='E';
	change_unit.TabKata[7]='_';
	change_unit.TabKata[8]='U';
	change_unit.TabKata[9]='N';
	change_unit.TabKata[10]='I';
	change_unit.TabKata[11]='T';
	change_unit.Length=11;
	attack.TabKata[1]='A';
	attack.TabKata[2]='T';
	attack.TabKata[3]='T';
	attack.TabKata[4]='A';
	attack.TabKata[5]='C';
	attack.TabKata[6]='K';
	attack.Length=6;
	map.TabKata[1]='M';
	map.TabKata[2]='A';
	map.TabKata[3]='P';
	map.Length=3;
	info.TabKata[1]='I';
	info.TabKata[2]='N';
	info.TabKata[3]='F';
	info.TabKata[4]='O';
	info.Length=4;
	end_turn.TabKata[1]='E';
	end_turn.TabKata[2]='N';
	end_turn.TabKata[3]='D';
	end_turn.TabKata[4]='_';
	end_turn.TabKata[5]='T';
	end_turn.TabKata[6]='U';
	end_turn.TabKata[7]='R';
	end_turn.TabKata[8]='N';
	end_turn.Length=8;
	menu.TabKata[1]='M';
	menu.TabKata[2]='E';
	menu.TabKata[3]='N';
	menu.TabKata[4]='U';
	menu.Length=4;
	
	Kata pilihan;
	int CTurn;
	
	*CurrUnit1 = InfoUnit(FirstUnit((*P1).UNTLST));

	*CurrUnit2 = InfoUnit(FirstUnit((*P2).UNTLST));
	while (!IsKataSama(menu,pilihan)) {
		while (!IsKataSama(end_turn,pilihan) && !IsKataSama(menu,pilihan)) {
			CTurn = InfoHead(*Q).ID;
			if (CTurn==1) {
				printf("\nPlayer %d's Turn\n",(*P1).ID);
				printf("Cash			: ");printf("%d\n",(*P1).GLD);
				printf("Income			: ");printf("%d\n",(*P1).INC);
				printf("Upkeep			: ");printf("%d\n",(*P1).OUT);
				printf("Unit			: ");
				if ((*CurrUnit1).TYP == 'K') {
					printf("King \n");
				} else if ( (*CurrUnit1).TYP == 'A' ) {
					printf("Archer \n");
				} else if ( (*CurrUnit1).TYP == 'S' ) {
					printf("Swordsman \n");
				} else if ( (*CurrUnit1).TYP == 'W' ) {
					printf("White Mage \n");
				}
				printf("Health			: ");printf("%d\n",(*CurrUnit1).HP);
				printf("Movement Point	: ");printf("%d\n",(*CurrUnit1).MOVEPTS);
				printf("Can Attack? ");
				if ((*CurrUnit1).CHN) {
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			} else if (CTurn==2) {
				printf("\nPlayer %d's Turn\n",(*P2).ID);
				printf("Cash			: ");printf("%d\n",(*P2).GLD);
				printf("Income			: ");printf("%d\n",(*P2).INC);
				printf("Upkeep			: ");printf("%d\n",(*P2).OUT);
				printf("Unit			: ");
				if ((*CurrUnit2).TYP == 'K') {
					printf("King \n");
				} else if ( (*CurrUnit2).TYP == 'A' ) {
					printf("Archer \n");
				} else if ( (*CurrUnit2).TYP == 'S' ) {
					printf("Swordsman \n");
				} else if ( (*CurrUnit2).TYP == 'W' ) {
					printf("White Mage \n");
				}
				printf("Health			: ");printf("%d\n",(*CurrUnit2).HP);
				printf("Movement Point		: ");printf("%d\n",(*CurrUnit2).MOVEPTS);
				printf("Can Attack? ");
				if ((*CurrUnit2).CHN) {
					printf("Yes\n");
				}
				else {
					printf("No\n");
				}
			}
			
			/* COBA-COBA */
			/* END OF COBA-COBA */

			printf("\nGame Command : ");
			InputToEksternal();
			EksternalToInput(&pilihan);
			if (IsKataSama(move,pilihan)) {
				if (CTurn==1) {
					if ((*CurrUnit1).MOVEPTS > 0) {
						TulisMAPJarak(M,*CurrUnit1);
						fmove(P1,P2,M,Q,CurrUnit1);
						Push(S1,*CurrUnit1);
					} else {
						printf("You ran out of movement points\n");
					}
				} else if (CTurn==2) {
					if ((*CurrUnit2).MOVEPTS > 0) {
						TulisMAPJarak(M,*CurrUnit2);
						fmove(P2,P1,M,Q,CurrUnit2);
						Push(S2,*CurrUnit2);
					} else {
						printf("You ran out of movement points\n");
					}
				} 
			} else if (IsKataSama(undo,pilihan)) {
				if (CTurn==1) {
					if (IsOneS(*S1)) {
						printf("No previous move, unable to undo.");
					} else {
						printf("You have succesfully undo the move.");
						Pop(S1,M,CurrUnit1);
					}
				} else if (CTurn==2) {
					if (IsOneS(*S2)) {
						printf("No previous move, unable to undo.");
					} else {
						printf("You have succesfully undo the move.");
						Pop(S2,M,CurrUnit2);
					}
				}
			} else if (IsKataSama(recruit,pilihan)) {
				
				
				frecruit(&(*P1),&(*P2),&(*M),&(*Q));
				//scanf("%c",&junk);
			} else if (IsKataSama(change_unit,pilihan)) {
				if (CTurn == 1) {
					CreateEmptyS(S1);
					*CurrUnit1 = fchange_unit(*P1);
					Push(S1,*CurrUnit1);
					DelP(&(*P1).UNTLST, *CurrUnit1);
					InsVFirst(&(*P1).UNTLST, *CurrUnit1);
				}
				else if (CTurn == 2) {
					CreateEmptyS(S2);
					*CurrUnit2 = fchange_unit(*P2);
					Push(S2,*CurrUnit2);
					DelP(&(*P2).UNTLST, *CurrUnit2);
					InsVFirst(&(*P2).UNTLST, *CurrUnit2);
				}
			} else if (IsKataSama(attack,pilihan)) {
				if (CTurn == 1) {
					fattack(P1, P2, M, Q, CurrUnit1);
				}
				else if (CTurn == 2) {
					fattack(P1, P2, M, Q, CurrUnit2);
				}
				*CurrUnit1 = InfoUnit(FirstUnit((*P1).UNTLST));
				*CurrUnit2 = InfoUnit(FirstUnit((*P2).UNTLST));
			} else if (IsKataSama(map,pilihan)) {
				if (CTurn==1) {
					TulisMAP(M,(*CurrUnit1).LOC.X,(*CurrUnit1).LOC.Y);
				} else if (CTurn==2) {
					TulisMAP(M,(*CurrUnit2).LOC.X,(*CurrUnit2).LOC.Y);
				}
			} else if (IsKataSama(info,pilihan)) {
				printf("\n");
				finfo(*M);
				scanf("%c",&junk);
			} 
			else if (IsKataSama(save,pilihan)) {
				printf("\n");
				SaveGame(*P1,*P2,*CurrUnit1,*CurrUnit2,*S1,*S2,*Q,*M);
			} 
			else if(IsKataSama(menu,pilihan)){
				printf("\n");
			}
			else if(IsKataSama(end_turn,pilihan)){
				printf("\n");
				ChangeTurn(Q);
				EmptyToEksternal();
				EksternalToInput(&pilihan);
			}
			else {
				printf("Warning : Masukan anda salah! Ulangi!\n");
			}
		}
		
	} 
}

int main(){
	int option; //Variabel untuk Menu
	/*Variabel untuk start game */
	Player P1,P2;
	Unit CurrUnit1,CurrUnit2;
	Stack S1,S2;
	TurnQueue Q;
	MATRIKS M;
	
	
	do{
		Display();
		Menu(&option);
		if(option == 1){
			NewGame(&P1,&P2,&CurrUnit1,&CurrUnit2,&S1,&S2,&Q,&M);
			Gamein(&P1,&P2,&CurrUnit1,&CurrUnit2,&S1,&S2,&Q,&M);
		}
		else if(option == 2){
			LoadGame(&P1,&P2,&CurrUnit1,&CurrUnit2,&S1,&S2,&Q,&M);
			//CurrUnit1 = InfoUnit(FirstUnit((P1).UNTLST));
			//CurrUnit2 = InfoUnit(FirstUnit((P2).UNTLST));
			//NewGame(&P1,&P2,&CurrUnit1,&CurrUnit2,&S1,&S2,&Q,&M);
			Gamein(&P1,&P2,&CurrUnit1,&CurrUnit2,&S1,&S2,&Q,&M);
			char junk;
			scanf("%c",&junk);
		}
		else if(option == 3){
			Credits();
		}
		else{
			option = 0;
		}
	} while(option != 0);
	printf("Exiting the Game\n");
	return 0;
}
