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

void InputToEksternal(){
	FILE * pita;
	char ch;
	pita = fopen("input.txt","w");
	while((ch = getchar())!='\n'){
		if(!(ch=='1') && !(ch=='2') && !(ch=='3') && !(ch=='4') && !(ch=='5') && !(ch=='6') && !(ch=='7') & !(ch=='8') && !(ch=='9') && !(ch=='0')){
			ch&='_';
		}
		putc(ch,pita);
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

void Display(){
	printf("\nWelcome to Battle For Olympia !!\n\n");
	Menu();
}

void Menu(){
	Kata pilihan;
	Kata start,load,save,exit,move,undo,recruit,change_unit,attack,map,info,end_turn;
	
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
	exit.TabKata[1]='E';
	exit.TabKata[2]='X';
	exit.TabKata[3]='I';
	exit.TabKata[4]='T';
	exit.Length=4;
	
	//BAGIAN MENU PROGRAM

	Player P1,P2;
	addressunit X;
	Unit CurrUnit1,CurrUnit2;
	ListUnit LU1,LU2;
	Stack S1,S2;
	TurnQueue Q;
	MATRIKS M;
	int B,K,CTurn; //Baris , Kolom, Current Turn
	printf("********************\n");
	printf("* START........[1] *\n* LOAD.........[2] *\n* CREDITS......[3] *\n* EXIT.........[4] *\n"); //Menu Pilihan
	printf("********************\n");

	printf("* Insert Map Row Size    = ");
	scanf("%d",&B);
	printf("* Insert Map Column Size = ");
	scanf("%d",&K);

	printf("\n\n");
	MakeMATRIKS(B,K,&M);
	InitializeMap(&M);
	InitializeQueue(&P1,&P2,&M,&Q);

	CreateEmptyS(&S1);
	CreateEmptyS(&S2);
	CurrUnit1 = InfoUnit(FirstUnit(P1.UNTLST));
	CurrUnit2 = InfoUnit(FirstUnit(P2.UNTLST));
	Push(&S1,CurrUnit1);
	Push(&S2,CurrUnit2);

	while (!IsKataSama(exit,pilihan)) {
		while (!IsKataSama(end_turn,pilihan)) {
			CTurn = InfoHead(Q).ID;
			if (CTurn==1) {
				printf("\nPlayer %d's Turn\n",P1.ID);
				printf("Cash			: ");printf("%d\n",P1.GLD);
				printf("Income			: ");printf("%d\n",P1.INC);
				printf("Upkeep			: ");printf("%d\n",P1.OUT);
				printf("Unit			: ");
				if (CurrUnit1.TYP == 'K') {
					printf("King \n");
				} else if ( CurrUnit1.TYP == 'A' ) {
					printf("Archer \n");
				} else if ( CurrUnit1.TYP == 'S' ) {
					printf("Swordsman \n");
				} else if ( CurrUnit1.TYP == 'W' ) {
					printf("White Mage \n");
				}
				printf("Health			: ");printf("%d\n",CurrUnit1.HP);
				printf("Movement Point		: ");printf("%d\n",CurrUnit1.MOVEPTS);
				printf("Can Attack? ");
				if (CurrUnit1.CHN) {
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			} else if (CTurn==2) {
				printf("\nPlayer %d's Turn\n",P2.ID);
				printf("Cash			: ");printf("%d\n",P2.GLD);
				printf("Income			: ");printf("%d\n",P2.INC);
				printf("Upkeep			: ");printf("%d\n",P2.OUT);
				printf("Unit			: ");
				if (CurrUnit2.TYP == 'K') {
					printf("King \n");
				} else if ( CurrUnit2.TYP == 'A' ) {
					printf("Archer \n");
				} else if ( CurrUnit2.TYP == 'S' ) {
					printf("Swordsman \n");
				} else if ( CurrUnit2.TYP == 'W' ) {
					printf("White Mage \n");
				}
				printf("Health			: ");printf("%d\n",CurrUnit2.HP);
				printf("Movement Point		: ");printf("%d\n",CurrUnit2.MOVEPTS);
				printf("Can Attack? ");
				if (CurrUnit2.CHN) {
					printf("Yes\n");
				}
				else {
					printf("No\n");
				}
			}
			if (IsKataSama(move,pilihan)) {
				if (CTurn==1) {
					if (CurrUnit1.MOVEPTS > 0) {
						TulisMAPJarak(&M,CurrUnit1);
						fmove(&P1,&M,&Q,&CurrUnit1);
						Push(&S1,CurrUnit1);
					} else {
						printf("You ran out of movement points\n");
					}
				} else if (CTurn==2) {
					if (CurrUnit2.MOVEPTS > 0) {
						TulisMAPJarak(&M,CurrUnit2);
						fmove(&P2,&M,&Q,&CurrUnit2);
						Push(&S2,CurrUnit2);
					} else {
						printf("You ran out of movement points\n");
					}
				}
			} else if (IsKataSama(undo,pilihan)) {
				if (CTurn==1) {
					if (IsOneS(S1)) {
						printf("No previous move, unable to undo.");
					} else {
						printf("You have succesfully undo the move.");
						Pop(&S1,&M,&CurrUnit1);
					}
				} else if (CTurn==2) {
					if (IsOneS(S2)) {
						printf("No previous move, unable to undo.");
					} else {
						printf("You have succesfully undo the move.");
						Pop(&S2,&M,&CurrUnit2);
					}
				}
			} else if (IsKataSama(recruit,pilihan)) {
				frecruit(&P1,&P2,&M,&Q);
			} else if (IsKataSama(change_unit,pilihan)) {
				if (CTurn == 1) {
					CreateEmptyS(&S1);
					CurrUnit1 = fchange_unit(P1);
					Push(&S1,CurrUnit1);
					DelP(&(P1.UNTLST), CurrUnit1);
					InsVFirst(&P1.UNTLST, CurrUnit1);
				}
				else if (CTurn == 2) {
					CreateEmptyS(&S2);
					CurrUnit2 = fchange_unit(P2);
					Push(&S2,CurrUnit2);
					DelP(&(P2.UNTLST), CurrUnit2);
					InsVFirst(&P2.UNTLST, CurrUnit2);
				}
			} else if (IsKataSama(attack,pilihan)) {
				fattack(&P1, &P2, &M, &Q);
				CurrUnit1 = InfoUnit(FirstUnit(P1.UNTLST));
				CurrUnit2 = InfoUnit(FirstUnit(P2.UNTLST));
			} else if (IsKataSama(map,pilihan)) {
				if (CTurn==1) {
					TulisMAP(&M,CurrUnit1.LOC.X,CurrUnit1.LOC.Y);
				} else if (CTurn==2) {
					TulisMAP(&M,CurrUnit2.LOC.X,CurrUnit2.LOC.Y);
				}
			} else if (IsKataSama(info,pilihan)) {
				printf("\n");
				finfo(M);
			}

			printf("\nGame Command : ");
			InputToEksternal();
			EksternalToInput(&pilihan);
		}

		CurrUnit1.CHN = true;
		CurrUnit2.CHN = true;
		InfoUnit(FirstUnit(P1.UNTLST)).CHN = CurrUnit1.CHN;
		InfoUnit(FirstUnit(P2.UNTLST)).CHN = CurrUnit2.CHN;
		/*note : chance nya jadi true*/
		ChangeTurn(&Q);
		RefreshAll(&P1);
		RefreshAll(&P2);
		CurrUnit1.MOVEPTS = 2;
		CurrUnit2.MOVEPTS = 2;

		printf("\nGame Command : ");
		InputToEksternal();
		EksternalToInput(&pilihan);
	}
}

int main(){
	Display();
	
	return 0;
}
