#include <stdio.h>
#include "gameproperty.h"
#include "turnqueue.h"
#include "boolean.h"
#include <stdlib.h>
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include "point.h"
#include "map.h"
#include "pcolor.h"
#include "gamefunction.h"

void frecruit(Player * P1, Player * P2, MATRIKS *M, TurnQueue *Q) {
	int x,y,i,PlayerID;
	Unit A;
	PlayerID = InfoHead(*Q).ID;

    if (PlayerID==1) {
        printf("Enter the coordinate of empty castle = ");
        scanf("%d %d",&x,&y);
        while ((Elmt(*M,x,y).UNITINFO.TYP != EMP)||(Elmt(*M,x,y).BLDINFO.ID != 1)){
            printf("That castle is occupied!!!\n");
            printf("Enter the coordinate of empty castle = ");
            scanf("%d %d",&x,&y);
        }
    } else if (PlayerID==2) {
        printf("Enter the coordinate of empty castle = ");
        scanf("%d %d",&x,&y);
        while ((Elmt(*M,x,y).UNITINFO.TYP != EMP)||(Elmt(*M,x,y).BLDINFO.ID != 2)){
            printf("That castle is occupied!!!\n");
            printf("Enter the coordinate of empty castle = ");
            scanf("%d %d",&x,&y);
        }
    }

	if (Elmt(*M,x,y).UNITINFO.TYP == EMP && Elmt(*M,x,y).BLDINFO.ID == PlayerID) {
        printf("= = = = = = LIST OF RECRUITS = = = = = = \n");
        printf("1. Archer       | Health 29 | ATK 5 | 17G \n");
        printf("2. Swordsman    | Health 33 | ATK 4 | 14G \n");
        printf("3. White Mage   | Health 26 | ATK 2 | 15G \n");
        printf("Enter the number of unit you want to recruit = ");

        do {
            scanf("%d",&i);
            if (i==1) {
                printf("You have recruited an Archer \n");
            } else if (i==2) {
                printf("You have recruited a Swordsman \n");
            } else if (i==3) {
                printf("You have recruited a White Mage \n");
            } else {
                printf("ERROR. Enter the number again = \n");
            }
        } while (i<1 && i>3);

        if (i==1) {
            Elmt(*M,x,y).UNITINFO.P = PlayerID;
	        Elmt(*M,x,y).UNITINFO.TYP = ARC;
	        Elmt(*M,x,y).UNITINFO.RNGTYP = RANGE;
	        Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_ARC;
            Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_ARC;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = MAX_MOVE_ARC;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_ARC;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_ARC;
			Elmt(*M,x,y).UNITINFO.CHN = true;
			Elmt(*M,x,y).UNITINFO.PRB = PRB_ARC;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_ARC;
            
            A.MAXHP = MAX_HP_ARC;
            A.HP = MAX_HP_ARC;
            A.ATK = ATK_ARC;
            A.MAXMOVE = MAX_MOVE_ARC;
            A.MOVEPTS = MAX_MOVE_ARC;
            A.PRC = PRC_OF_ARC;
            A.RNGTYP = RANGE;
            A.TYP = ARC;
            A.CHN = true;
			A.PRB = PRB_ARC;
            A.P = PlayerID;
            A.LOC.X = x;
            A.LOC.Y = y;

			if (PlayerID==1) {
                (*P1).GLD -= PRC_OF_ARC;
                InsVFirst(&(*P1).UNTLST,A);
			} else if (PlayerID==2) {
                (*P2).GLD -= PRC_OF_ARC;
                InsVFirst(&(*P2).UNTLST,A);
            }
            
        } else if (i==2) {
            Elmt(*M,x,y).UNITINFO.P = PlayerID;
	        Elmt(*M,x,y).UNITINFO.TYP = SWD;
	        Elmt(*M,x,y).UNITINFO.RNGTYP = MELEE;
            Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_SWD;
	        Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_SWD;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = MAX_MOVE_SWD;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_SWD;
			Elmt(*M, x, y).UNITINFO.PRB = PRB_SWD;
			Elmt(*M, x, y).UNITINFO.CHN = true;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_SWD;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_SWD;
            
            A.MAXHP = MAX_HP_SWD;
            A.HP = MAX_HP_SWD;
            A.ATK = ATK_SWD;
            A.MAXMOVE = MAX_MOVE_SWD;
            A.MOVEPTS = MAX_MOVE_SWD;
            A.PRC = PRC_OF_SWD;
            A.RNGTYP = RANGE;
            A.TYP = SWD;
			A.CHN = true;
			A.PRB = PRB_SWD;
            A.P = PlayerID;
            A.LOC.X = x;
            A.LOC.Y = y;

			if (PlayerID==1) {
                (*P1).GLD -= PRC_OF_SWD;
                InsVFirst(&(*P1).UNTLST,A);
			} else if (PlayerID==2) {
                (*P2).GLD -= PRC_OF_SWD;
                InsVFirst(&(*P2).UNTLST,A);
            }

        } else if (i==3) {
            Elmt(*M,x,y).UNITINFO.P = PlayerID;
	        Elmt(*M,x,y).UNITINFO.TYP = WHT;
	        Elmt(*M,x,y).UNITINFO.RNGTYP = RANGE;
            Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_WHT;
	        Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_WHT;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = MAX_MOVE_WHT;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_WHT;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_WHT;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_WHT;
			Elmt(*M, x, y).UNITINFO.CHN = true;
			Elmt(*M, x, y).UNITINFO.PRB = PRB_WHT;
            
            A.MAXHP = MAX_HP_WHT;
            A.HP = MAX_HP_WHT;
            A.ATK = ATK_WHT;
            A.MAXMOVE = MAX_MOVE_WHT;
            A.MOVEPTS = MAX_MOVE_WHT;
            A.PRC = PRC_OF_WHT;
            A.RNGTYP = RANGE;
			A.PRB = PRB_WHT;
            A.TYP = WHT;
            A.CHN = true;
            A.P = PlayerID;
            A.LOC.X = x;
            A.LOC.Y = y;

			if (PlayerID==1) {
                (*P1).GLD -= PRC_OF_WHT;
                InsVFirst(&(*P1).UNTLST,A);
			} else if (PlayerID==2) {
                (*P2).GLD -= PRC_OF_WHT;
                InsVFirst(&(*P2).UNTLST,A);
            }
        }
	}
}

void InitializeQueue(Player * A, Player * B, MATRIKS * M, TurnQueue * Q)
{
    Unit KNG1,KNG2;
    address K,L;

    InitializeTurnQueue(Q);

    CreateEmpty(&(*A).UNTLST);
    CreateEmptyB(&(*A).VLGLST);
    KNG1.MAXHP = MAX_HP_KNG;
    KNG1.HP = MAX_HP_KNG;
    KNG1.ATK = ATK_KNG;
    KNG1.MAXMOVE = MAX_MOVE_KNG;
    KNG1.MOVEPTS = MAX_MOVE_KNG;
    KNG1.PRC = PRC_OF_KNG;
    KNG1.RNGTYP = MELEE;
    KNG1.TYP = KNG;
	KNG1.PRB = PRB_KNG;
	KNG1.CHN = true;
    KNG1.P = 1;
    KNG1.LOC.X = NBrsEff(*M)-2;
    KNG1.LOC.Y = 1;
    InsVFirst(&(*A).UNTLST,KNG1);
    (*A).ID = 1;
    (*A).GLD = 123;
    (*A).INC = 0;
    (*A).OUT = 0;
    AlokasiQ(&K,(*A));

    CreateEmpty(&(*B).UNTLST);
    CreateEmptyB(&(*B).VLGLST);
    KNG2.MAXHP = MAX_HP_KNG;
    KNG2.HP = MAX_HP_KNG;
    KNG2.ATK = ATK_KNG;
    KNG2.MAXMOVE = MAX_MOVE_KNG;
    KNG2.MOVEPTS = MAX_MOVE_KNG;
    KNG2.PRC = PRC_OF_KNG;
    KNG2.RNGTYP = MELEE;
    KNG2.TYP = KNG;
    KNG2.PRB = PRB_KNG;
    KNG2.P = 2;
    KNG2.LOC.X = 1;
    KNG2.LOC.Y = NKolEff(*M)-2;
    InsVFirst(&(*B).UNTLST,KNG2);
    (*B).ID = 2;
    (*B).GLD = 123;
    (*B).INC = 0;
    (*B).OUT = 0;
    AlokasiQ(&L,(*B));

    AddQ(Q,*A);
    AddQ(Q,*B);
}

Unit fchange_unit(Player * P1, Player * P2, TurnQueue * Q) {
    int x,y,i,PlayerID;

    PlayerID = InfoHead(*Q).ID;
    printf("\n====== LIST OF UNITS ======\n");
    if (PlayerID==1) {
        PrintInfo((*P1).UNTLST);
    } else if (PlayerID==2) {
        PrintInfo((*P2).UNTLST);
    }
    printf("Please enter the no. of unit you want to select: ");
    scanf("%d",&x);
    if (PlayerID==1) {
        return SearchX((*P1).UNTLST,x);
    } else if (PlayerID==2) {
        return SearchX((*P2).UNTLST,x);
    }
}
