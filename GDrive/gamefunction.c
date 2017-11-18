#include "gameproperty.h"
#include "turnqueue.h"
#include "boolean.h"
#include <stdlib.h>
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include "point.h"
#include "map.h"
#include "pcolor.h"
#include <stdio.h>
#include "gamefunction.h"

void frecruit(Player * P1, Player * P2, MATRIKS *M, TurnQueue *Q) {
	int x,y,i,PlayerID;

	PlayerID = InfoHead(*Q).ID;

	if (PlayerID==1) {
		do {
			printf("Enter the coordinate of empty castle = ");
			scanf("%d %d",&x,&y);
			if ( (Elmt(*M,x,y).UNITINFO.P != 1 || Elmt(*M,x,y).UNITINFO.P != 2) && ( x!= NBrsEff(*M)-2 && y!= 0 ) && ( x!= NBrsEff(*M)-2 && y!= 2 ) && ( x!= NBrsEff(*M)-1 && y!= 1 ) && ( x!= NBrsEff(*M)-3 && y!= 1 ) ) {
				printf("That castle is occupied\n");
			}
		} while ( (Elmt(*M,x,y).UNITINFO.P != 1 || Elmt(*M,x,y).UNITINFO.P != 2) && ( x!= NBrsEff(*M)-2 && y!= 0 ) && ( x!= NBrsEff(*M)-2 && y!= 2 ) && ( x!= NBrsEff(*M)-1 && y!= 1 ) && ( x!= NBrsEff(*M)-3 && y!= 1 ) );
	} else if (PlayerID==2) {
		do {
			printf("Enter the coordinate of empty castle = ");
			scanf("%d %d",&x,&y);
			if ( (Elmt(*M,x,y).UNITINFO.P != 1 || Elmt(*M,x,y).UNITINFO.P != 2) && ( x!= 0 && y!= NKolEff(*M) - 2 ) && ( x!= 2 && y!= NKolEff(*M) - 2 ) && ( x!= 1 && y!= NKolEff(*M) - 1 ) && ( x!= 1 && y!= NKolEff(*M) - 3 ) ) {
				printf("That castle is occupied\n");
			}
		} while ( (Elmt(*M,x,y).UNITINFO.P != 1 || Elmt(*M,x,y).UNITINFO.P != 2) && ( x!= 0 && y!= NKolEff(*M) - 2 ) && ( x!= 2 && y!= NKolEff(*M) - 2 ) && ( x!= 1 && y!= NKolEff(*M) - 1 ) && ( x!= 1 && y!= NKolEff(*M) - 3 ) );
	}

	if (Elmt(*M,x,y).UNITINFO.P == 1 || Elmt(*M,x,y).UNITINFO.P == 2) {
		printf("That castle is occupied\n");
	} else {
        printf("= = = = = = LIST OF RECRUITS = = = = = = \n");
        printf("1. Archer | Health 29 | ATK 5 | DEF 1 | 17G \n");
        printf("2. Swordsman | Health 33 | ATK 4 | DEF 2 | 14G \n");
        printf("3. White Mage | Health 26 | ATK 2 | DEF 2 | 15G \n");
        printf("Enter the number of unit you want to recruit = ");

        do {
            scanf("%d",&i);
            if (i==1) {
                printf("You have recruited an Archer \n");
            } else if (i==2) {
                printf("You have recruited a Swordsman \n");
            } else if (i==3) {
                printf("You have recruited a Swordsman \n");
            } else {
                printf("ERROR. Enter the number again = \n");
            }
        } while (i<1 && i>3);

        if (i==1) {
            Elmt(*M,x,y).UNITINFO.P = PlayerID;
	        Elmt(*M,x,y).UNITINFO.TYP = ARC;
	        Elmt(*M,x,y).UNITINFO.RNGTYP = RANGE;
	        Elmt(*M,x,y).UNITINFO.RNG = 1;
	        Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_ARC;
            Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_ARC;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = MAX_MOVE_ARC;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_ARC;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_ARC;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_ARC;
            
            Unit A;
            
            A.MAXHP = MAX_HP_ARC;
            A.HP = MAX_HP_ARC;
            A.ATK = ATK_ARC;
            A.MAXMOVE = MAX_MOVE_ARC;
            A.MOVEPTS = MAX_MOVE_ARC;
            A.PRC = PRC_OF_ARC;
            A.RNG = 1;
            A.RNGTYP = RANGE;
            A.TYP = ARC;
            A.CHN = CHN_ARC;
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
	        Elmt(*M,x,y).UNITINFO.RNG = 1;
            Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_SWD;
	        Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_SWD;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = MAX_MOVE_SWD;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_SWD;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_SWD;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_SWD;

			Unit A;
            
            A.MAXHP = MAX_HP_SWD;
            A.HP = MAX_HP_SWD;
            A.ATK = ATK_SWD;
            A.MAXMOVE = MAX_MOVE_SWD;
            A.MOVEPTS = MAX_MOVE_SWD;
            A.PRC = PRC_OF_SWD;
            A.RNG = 1;
            A.RNGTYP = RANGE;
            A.TYP = SWD;
            A.CHN = CHN_SWD;
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
	        Elmt(*M,x,y).UNITINFO.RNG = 1;
            Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_WHT;
	        Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_WHT;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = MAX_MOVE_WHT;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_WHT;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_WHT;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_WHT;
					 
			Unit A;
            
            A.MAXHP = MAX_HP_WHT;
            A.HP = MAX_HP_WHT;
            A.ATK = ATK_WHT;
            A.MAXMOVE = MAX_MOVE_WHT;
            A.MOVEPTS = MAX_MOVE_WHT;
            A.PRC = PRC_OF_WHT;
            A.RNG = 1;
            A.RNGTYP = RANGE;
            A.TYP = WHT;
            A.CHN = CHN_WHT;
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
    AddQ(Q,*A);
    AddQ(Q,*B);

    CreateEmpty(&(*A).UNTLST);
    CreateEmptyB(&(*A).VLGLST);
    KNG1.MAXHP = 53;
    KNG1.HP = 53;
    KNG1.ATK = 7;
    KNG1.MAXMOVE = 13;
    KNG1.MOVEPTS = 13;
    KNG1.PRC = 1000;
    KNG1.RNG = 1;
    KNG1.RNGTYP = 'm';
    KNG1.TYP = 'K';
    KNG1.CHN = 0.8;
    KNG1.P = 1;
    KNG1.LOC.X = NBrsEff(*M)-2;
    KNG1.LOC.Y = 1;
    InsVFirst(&(*A).UNTLST,KNG1);

    (*A).ID = 1;
    (*A).GLD = 123;
    (*A).INC = 0;
    (*A).OUT = 1;
    AlokasiQ(&K,(*A));
    InfoHead(*Q) = (*A);

    CreateEmpty(&(*B).UNTLST);
    CreateEmptyB(&(*B).VLGLST);
    KNG2.MAXHP = 53;
    KNG2.HP = 53;
    KNG2.ATK = 7;
    KNG2.MAXMOVE = 13;
    KNG2.MOVEPTS = 13;
    KNG2.PRC = 1000;
    KNG2.RNG = 1;
    KNG2.RNGTYP = 'm';
    KNG2.TYP = 'K';
    KNG2.CHN = 0.8;
    KNG2.P = 1;
    KNG2.LOC.X = 1;
    KNG2.LOC.Y = NKolEff(*M)-2;
    InsVFirst(&(*B).UNTLST,KNG2);
    (*B).ID = 2;
    (*B).GLD = 123;
    (*B).INC = 0;
    (*B).OUT = 1;
    AlokasiQ(&L,(*B));
    InfoTail(*Q) = (*B);
}

void fchange_unit(Player * P1, Player * P2, TurnQueue * Q, addressunit * X) {
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
        *X = SearchX((*P1).UNTLST,x);
    } else if (PlayerID==2) {
        *X = SearchX((*P2).UNTLST,x);
    }
}