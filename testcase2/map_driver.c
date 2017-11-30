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

int main(){
    Player P1,P2;
  	addressunit X;
  	Unit CurrUnit1,CurrUnit2;
  	ListUnit LU1,LU2;
  	Stack S1,S2;
  	TurnQueue Q;
  	MATRIKS M;
    int B,K,CTurn; //Baris , Kolom, Current Turn
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
  			CTurn = 1;
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
					if (CurrUnit1.MOVEPTS > 0) {
						TulisMAPJarak(&M,CurrUnit1);
						fmove(&P1,&P2,&M,&Q,&CurrUnit1);
						Push(&S1,CurrUnit1);
					} else {
						printf("You ran out of movement points\n");
					}
					TulisMAP(&M,CurrUnit1.LOC.X,CurrUnit1.LOC.Y);
}
