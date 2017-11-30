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
#include <math.h>

void fattack(Player *P1, Player *P2, MATRIKS *M, TurnQueue *Q) {
	int x, y, x1, y1, x2, y2, x3, y3, x4, y4, PlayerID;
	int countEnemy = 1;
	boolean isCanRetaliate = false;
	Unit Enemy;
	PlayerID = InfoHead(*Q).ID;
	if ((PlayerID == 1) && (InfoUnit(FirstUnit((*P1).UNTLST))).CHN) {
		/*Determine CurrUnit1 location (x,y) untuk mlihat sekitar Unit apakah ada
		* musuh disekitarnya
		*/
		x = InfoUnit(FirstUnit((*P1).UNTLST)).LOC.X;
		y = InfoUnit(FirstUnit((*P1).UNTLST)).LOC.Y;
		x2 = x - 1; y2 = y;
		x1 = x + 1; y1 = y;
		x4 = x, y4 = y - 1;
		x3 = x, y3 = y + 1;
		printf("\nPlease select enemy you want to attack : \n");

		/*Check di map*/
		if ((x - 1) >= 0) { //check di atas CurrUnit1, ada musuh atau tidak
			if ((Elmt((*M), x - 1, y).UNITINFO.P != 1) && (Elmt((*M), x - 1, y).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x - 1, y).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P1).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
		/*Check di map*/
		if ((x + 1) <= NKolEff(*M)) { //check di bawah CurrUnit1, ada musuh atau tidak
			if ((Elmt((*M), x + 1, y).UNITINFO.P != 1) && (Elmt((*M), x + 1, y).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x + 1, y).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P1).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
		/*Check di map*/
		if ((y - 1) >= 0) { //check di kiri CurrUnit1, ada musuh atau tidak
			if ((Elmt((*M), x, y - 1).UNITINFO.P != 1) && (Elmt((*M), x, y - 1).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x, y - 1).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P1).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
		/*Check di map*/
		if ((y + 1) <= NBrsEff(*M)) { //check di kanan CurrUnit1, ada musuh atau tidak
			if ((Elmt((*M), x, y + 1).UNITINFO.P != 1) && (Elmt((*M), x, y + 1).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x, y + 1).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P1).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P1).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
	}
	else if ((PlayerID == 2) && (InfoUnit(FirstUnit((*P2).UNTLST))).CHN) {
		x = InfoUnit(FirstUnit((*P2).UNTLST)).LOC.X;
		y = InfoUnit(FirstUnit((*P2).UNTLST)).LOC.Y;
		x1 = x - 1; y1 = y;
		x2 = x + 1; y2 = y;
		x3 = x, y3 = y - 1;
		x4 = x, y4 = y + 1;
		printf("\nPlease select enemy you want to attack : \n");

		if ((x - 1) >= 0) {
			if ((Elmt((*M), x - 1, y).UNITINFO.P != 2) && (Elmt((*M), x - 1, y).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x - 1, y).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P2).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
		/*Check di map*/
		if ((x + 1) <= NKolEff(*M)) { //check di bawah CurrUnit2, ada musuh atau tidak
			if ((Elmt((*M), x + 1, y).UNITINFO.P != 2) && (Elmt((*M), x + 1, y).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x + 1, y).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P2).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
		/*Check di map*/
		if ((y - 1) >= 0) { //check di kiri CurrUnit2, ada musuh atau tidak
			if ((Elmt((*M), x, y - 1).UNITINFO.P != 2) && (Elmt((*M), x, y - 1).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x, y - 1).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P2).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
		/*Check di map*/
		if ((y + 1) <= NBrsEff(*M)) { //check di kanan CurrUnit2, ada musuh atau tidak
			if ((Elmt((*M), x, y + 1).UNITINFO.P != 2) && (Elmt((*M), x, y + 1).UNITINFO.TYP != EMP)) {
				Enemy = Elmt((*M), x, y + 1).UNITINFO;
				printf("%d. ", countEnemy);
				countEnemy++;
				if (Enemy.TYP == ARC) {
					printf("Archer | ");
				}
				else if (Enemy.TYP == SWD) {
					printf("Swordsman | ");
				}
				else if (Enemy.TYP == WHT) {
					printf("Whitemage | ");
				}
				else {
					printf("King | ");
				}
				printf("Health ");
				printf("%d/", Enemy.HP);
				printf("%d ", Enemy.MAXHP);
				if ((Enemy.RNGTYP == InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP) || (Enemy.TYP == KNG) || (Enemy.TYP == ARC)) {
					if ((Enemy.HP - InfoUnit(FirstUnit((*P2).UNTLST)).ATK) <= 0) {
						printf("(No Retaliates)\n");
						isCanRetaliate = false;
					}
					else {
						printf("(Retaliates)\n");
						isCanRetaliate = true;
					}
				}
				else if ((Enemy.RNGTYP != InfoUnit(FirstUnit((*P2).UNTLST)).RNGTYP)) {
					printf("(No Retaliates)\n");
					isCanRetaliate = false;
				}
			}
		}
	}
	else {
		printf("\nYour current unit doesn't have any chance to attack. \n");
	}

	if (((InfoUnit(FirstUnit((*P1).UNTLST))).CHN && (InfoUnit(FirstUnit((*P2).UNTLST))).CHN) && ((countEnemy - 1) == 0)) {
		printf("\nThere are no enemy(s) in a nearby. \n");
	}
	else if (((InfoUnit(FirstUnit((*P1).UNTLST))).CHN && (InfoUnit(FirstUnit((*P2).UNTLST))).CHN) && ((countEnemy - 1) <= 4)) {
		int choice;
		printf("Input your choice use number format : ");
		scanf("%d", &choice);
		while ((choice > (countEnemy - 1)) || (choice < 1)) {
			printf("Input your choice use number format : ");
			scanf("%d", &choice);
		}
		switch (choice) {
		case 1:
			calculateAttack(x1, y1, P1, P2, M, PlayerID, isCanRetaliate);
			break;
		case 2:
			calculateAttack(x2, y2, P1, P2, M, PlayerID, isCanRetaliate);
			break;
		case 3:
			calculateAttack(x3, y3, P1, P2, M, PlayerID, isCanRetaliate);
			break;
		case 4:
			calculateAttack(x4, y4, P1, P2, M, PlayerID, isCanRetaliate);
			break;
		}
	}
}

void calculateAttack(int x, int y, Player *P1, Player *P2, MATRIKS *M, int PlayerID, boolean isCanRetaliate) {
	//srand(time(0)) int x = rand() % (max+1-min)+min;
	srand(time(0));
	int prob = rand() % (1 + 1 - 0) + 0;
	Unit Enemy = Elmt((*M), x, y).UNITINFO;
	Unit MyUnit;
	if (PlayerID == 1) {
		MyUnit = InfoUnit(FirstUnit((*P1).UNTLST));
		int PRBInt = 1 - ((int)MyUnit.PRB);

		if (prob >= PRBInt) {
			/*Berhasil serang, lebih dari probabilty yang ada*/
			Elmt((*M), x, y).UNITINFO.HP -= MyUnit.ATK;
			printf("Your unit attack the enemy successfully. \n");
			printf("Enemy's HP reduced by %d. \n", MyUnit.ATK);
			if (Elmt((*M), x, y).UNITINFO.HP <= 0) {
				printf("You kill the enemy's unit! Good Job!. \n");
				isCanRetaliate = false;
				/*jika dipukul dan darahnya habis hapus di map dan di unit Player 2*/
				Elmt((*M), x, y).UNITINFO.TYP = EMP;
				Elmt((*M), x, y).UNITINFO.P = -1;
				DelP(&(*P2).UNTLST, Enemy);
			} else {
				if (NbElmt((*P2).UNTLST) > 1){
					DelP(&(*P2).UNTLST, Enemy);
					Enemy = Elmt((*M), x, y).UNITINFO;
					InsVFirst(&(*P2).UNTLST, Enemy);
				} else {
					InfoUnit(FirstUnit((*P2).UNTLST)) = Elmt((*M), x, y).UNITINFO;
				}
			}
		} else {
			printf("Oh no! Your unit missed that chance!. \n");
			isCanRetaliate = false;
		}

		if (isCanRetaliate) {
			MyUnit.HP -= Enemy.ATK;
			Elmt((*M), MyUnit.LOC.X, MyUnit.LOC.Y).UNITINFO.HP -= Enemy.ATK;
			printf("Enemy's unit retaliates. \n");
			printf("Your unit's HP reduced by %d. \n", Enemy.ATK);
			if (MyUnit.HP <= 0) {
				//jika diretiliate dan mati dan delete unit pada P1
				Elmt((*M), MyUnit.LOC.X, MyUnit.LOC.Y).UNITINFO.TYP = EMP;
				Elmt((*M), MyUnit.LOC.X, MyUnit.LOC.Y).UNITINFO.P = - 1;
				printf("Your unit is down...\n");
				DelVFirst(&(*P1).UNTLST, &MyUnit);
			}
			else {
				if (NbElmt((*P1).UNTLST) > 1){
					DelVFirst(&(*P1).UNTLST, &Enemy); //ENEMY sudah tidak terpakai
					InsVFirst(&(*P1).UNTLST, MyUnit);
				} else {
					InfoUnit(FirstUnit((*P1).UNTLST)) = MyUnit;
				}
			}
		}
		if (!IsEmpty((*P1).UNTLST)) {
			(InfoUnit(FirstUnit((*P1).UNTLST))).CHN = false;
		}
	}
	else {
		MyUnit = InfoUnit(FirstUnit((*P2).UNTLST));
		int PRBInt = 1 - ((int)MyUnit.PRB);

		if (prob >= PRBInt) {
			/*Berhasil serang, lebih dari probabilty yang ada*/
			Elmt((*M), x, y).UNITINFO.HP -= MyUnit.ATK;
			printf("Your unit attack the enemy successfully. \n");
			printf("Enemy's HP reduced by %d. \n", MyUnit.ATK);
			if (Elmt((*M), x, y).UNITINFO.HP <= 0) {
				printf("You kill the enemy's unit! Good Job!. \n");
				isCanRetaliate = false;
				/*jika dipukul dan darahnya habis hapus di map dan di unit Player 1*/
				Elmt((*M), x, y).UNITINFO.TYP = EMP;
				Elmt((*M), x, y).UNITINFO.P = -1;
				DelP(&(*P1).UNTLST, Enemy);
			} else {
				if (NbElmt((*P1).UNTLST) > 1){
					DelP(&(*P1).UNTLST, Enemy);
					Enemy = Elmt((*M), x, y).UNITINFO;
					InsVFirst(&(*P1).UNTLST, Enemy);
				} else {
					InfoUnit(FirstUnit((*P1).UNTLST)) = Elmt((*M), x, y).UNITINFO;
				}
			}
		}
		else {
			printf("Oh no! Your unit missed that chance!. \n");
			isCanRetaliate = false;
		}

		if (isCanRetaliate) {
			MyUnit.HP -= Enemy.ATK;
			Elmt((*M), MyUnit.LOC.X, MyUnit.LOC.Y).UNITINFO.HP -= Enemy.ATK;
			printf("Enemy's unit retaliates. \n");
			printf("Your unit's HP reduced by %d. \n", Enemy.ATK);
			if (MyUnit.HP <= 0) {
				//jika diretiliate dan mati dan delete unit pada P2
				Elmt((*M), MyUnit.LOC.X, MyUnit.LOC.Y).UNITINFO.TYP = EMP;
				Elmt((*M), MyUnit.LOC.X, MyUnit.LOC.Y).UNITINFO.P = -1;
				printf("Your unit is down...\n");
				DelVFirst(&(*P2).UNTLST, &MyUnit);
			}
			else {
				if (NbElmt((*P2).UNTLST) > 1){
					DelVFirst(&(*P2).UNTLST, &Enemy); //ENEMY sudah tidak terpakai
					InsVFirst(&(*P2).UNTLST, MyUnit);
				} else {
					InfoUnit(FirstUnit((*P2).UNTLST)) = MyUnit;
				}
			}
		}
		if (!IsEmpty((*P2).UNTLST)) {
			(InfoUnit(FirstUnit((*P2).UNTLST))).CHN = false;
		}
	}
}

void RefreshAll(Player * P) { //Refresh all dari movement, income, outcome
	addressunit Q;
	addressbuilding R;
	int countVlg = 0;
	int countUnit = 0;
	/*refresh income,outcome,movement
	* setiap ada village +incomenya 10/vlg
	* kalo upkeep -jmlunit 1Gold/Unit
	*/

	if (!IsEmptyB((*P).VLGLST)) {
		R = FirstBuilding((*P).VLGLST);
		while (nextbuilding(R) != Nil){
				if (infobuilding(R).TYP == VLG){
					countVlg++;
				}
		}
	}

	Q = FirstUnit((*P).UNTLST);

	for (int i=1;i<=NbElmt((*P).UNTLST);i++) {
		InfoUnit(Q).MOVEPTS = 2;
		countUnit++;
		Q = NextUnit(Q);
	}

	(*P).INC = (countVlg*INCOME);
	(*P).OUT =  countUnit;
	(*P).GLD += ((*P).INC - (*P).OUT);
}

void finfo(MATRIKS M)
/* M adalah matriks Peta Permainan */
{
    POINT P;

    printf("Enter the coordinate of the cell : ");
    BacaPOINT(&P);

    /* --- BUILDING --- */
    printf("== Cell Info ==\n");

    if (Elmt(M,Absis(P),Ordinat(P)).BLDINFO.TYP == EMPB) {              // tidak ada building
        printf("Normal\n");
    } else {
        if (Elmt(M,Absis(P),Ordinat(P)).BLDINFO.TYP == TWR) {           // Jenis building "Tower"
            printf("Tower\n");
        } else if (Elmt(M,Absis(P),Ordinat(P)).BLDINFO.TYP == CST) {    // Jenis building "Castle"
            printf("Castle\n");
        } else if (Elmt(M,Absis(P),Ordinat(P)).BLDINFO.TYP == VLG) {    // Jenis building "Village"
            printf("Village\n");
        }
        if (Elmt(M,Absis(P),Ordinat(P)).BLDINFO.ID == 0) {              // Jika building tidak dimiliki oleh siapapun
            printf("Not owned by any player\n");
        } else {                                                        // Jika building dimiliki oleh seorang player
            printf("Owned by Player %d\n", Elmt(M,Absis(P),Ordinat(P)).BLDINFO.ID);
        }
    }

    /* --- UNIT --- */
    printf("\n== Unit Info ==\n");
    if (Elmt(M,Absis(P),Ordinat(P)).UNITINFO.TYP == EMP) {              // Tidak ada unit di petak yang dipilih
        printf("No unit\n");
    } else {
        if (Elmt(M,Absis(P),Ordinat(P)).UNITINFO.TYP == KNG) printf("King\n");
        else if (Elmt(M,Absis(P),Ordinat(P)).UNITINFO.TYP == ARC) printf("Archer\n");
        else if(Elmt(M,Absis(P),Ordinat(P)).UNITINFO.TYP == SWD) printf("Swordman\n");
        else if (Elmt(M,Absis(P),Ordinat(P)).UNITINFO.TYP == WHT) printf("White Mage\n");

        // "Owned by Player " (kepemilikan di siapa)
        printf("Owned by Player %d\n", Elmt(M,Absis(P),Ordinat(P)).UNITINFO.P);

        // Health (current health)/(max health) | ATK (Damage)
        printf("Health %d/%d | ATK %d\n", Elmt(M,Absis(P),Ordinat(P)).UNITINFO.HP,
                                        Elmt(M,Absis(P),Ordinat(P)).UNITINFO.MAXHP,
                                        Elmt(M,Absis(P),Ordinat(P)).UNITINFO.ATK);
    }
}

void fmove(Player * P1, Player * P2, MATRIKS * M, TurnQueue * Q, Unit * U) {
    addressunit Ptemp;
    int MX,MY,Jarak;
    POINT IN;
    boolean valid;
	Unit Temp;

	if ((*U).MOVEPTS == 2) {
		while (!valid) { 
			printf("\nPlease enter cell's coordinate x y : ");
			scanf("%d %d",&MX,&MY);
			IN.X = MX;
			IN.Y = MY;  

			if (IN.X == (*U).LOC.X && IN.Y - (*U).LOC.Y == 2) {
				if ((Elmt(*M,IN.X,(IN.Y)-1).UNITINFO.P == (*U).P || Elmt(*M,IN.X,(IN.Y)-1).UNITINFO.P == -1)&&(Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)){
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X && IN.Y - (*U).LOC.Y == 1 ) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X - (*U).LOC.X == -2 && IN.Y == (*U).LOC.Y) {
				if ((Elmt(*M,(IN.X)+1,IN.Y).UNITINFO.P == (*U).P || Elmt(*M,(IN.X)+1,IN.Y).UNITINFO.P == -1)&&(Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)){
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X - (*U).LOC.X == -1 && IN.Y == (*U).LOC.Y) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X && (*U).LOC.Y - IN.Y == 2 ) {
				if ((Elmt(*M,IN.X,(IN.Y)+1).UNITINFO.P == (*U).P || Elmt(*M,IN.X,(IN.Y)+1).UNITINFO.P == -1)&&(Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)){
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X && (*U).LOC.Y - IN.Y == 1) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X - (*U).LOC.X == 2 && IN.Y == (*U).LOC.Y) {
				if ((Elmt(*M,(IN.X)-1,IN.Y).UNITINFO.P == (*U).P || Elmt(*M,(IN.X)-1,IN.Y).UNITINFO.P == -1)&&(Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)){
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X - (*U).LOC.X == 1 && IN.Y == (*U).LOC.Y) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X + 1 && IN.Y == (*U).LOC.Y + 1) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X + 1 && IN.Y == (*U).LOC.Y - 1) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X - 1 && IN.Y == (*U).LOC.Y - 1) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X - 1 && IN.Y == (*U).LOC.Y + 1) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else {
				valid = false;
			}
			if (valid == false) {
				printf("\nYou can't move there\n");
			}
		}
	} else if ((*U).MOVEPTS == 1) {
		while (!valid) { 
			printf("\nPlease enter cell's coordinate x y : ");
			scanf("%d %d",&MX,&MY);
			IN.X = MX;
			IN.Y = MY;  

			if (IN.X == (*U).LOC.X && IN.Y - (*U).LOC.Y == 1 ) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X - (*U).LOC.X == -1 && IN.Y == (*U).LOC.Y) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X == (*U).LOC.X && (*U).LOC.Y - IN.Y == 1) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else if (IN.X - (*U).LOC.X == 1 && IN.Y == (*U).LOC.Y) {
				if ((Elmt(*M,IN.X,IN.Y).UNITINFO.P == -1) && (Elmt(*M,IN.X,IN.Y).UNITINFO.TYP == EMP)) {
					valid = true;
				} else {
					valid = false;
				}
			} else {
				valid = false;
			}
			if (valid == false) {
				printf("\nYou can't move there\n");
			}
		}
	}

    if (valid==true) {
		Jarak = Panjang(IN,(*U).LOC);
        Elmt(*M,IN.X,IN.Y).UNITINFO.LOC.X = IN.X;
	    Elmt(*M,IN.X,IN.Y).UNITINFO.LOC.Y = IN.Y;
        Elmt(*M,IN.X,IN.Y).UNITINFO.P = (*U).P;
	    Elmt(*M,IN.X,IN.Y).UNITINFO.TYP = (*U).TYP;
        Elmt(*M,IN.X,IN.Y).UNITINFO.RNGTYP = (*U).RNGTYP;
	    Elmt(*M,IN.X,IN.Y).UNITINFO.PRC = (*U).PRC;
	    Elmt(*M,IN.X,IN.Y).UNITINFO.MOVEPTS = (*U).MOVEPTS;
        Elmt(*M,IN.X,IN.Y).UNITINFO.MAXMOVE = (*U).MAXMOVE;
	    Elmt(*M,IN.X,IN.Y).UNITINFO.ATK = (*U).ATK;
 	    Elmt(*M,IN.X,IN.Y).UNITINFO.HP = (*U).HP;
		Elmt(*M,IN.X,IN.Y).UNITINFO.CHN = (*U).CHN;
		Elmt(*M,IN.X,IN.Y).UNITINFO.PRB = (*U).PRB;
		Elmt(*M,IN.X,IN.Y).UNITINFO.MAXHP = (*U).MAXHP;

		/*
        //If landed on a village.
        if (Elmt(*M,IN.X,IN.Y).BLDINFO.TYP == VLG && Elmt(*M,IN.X,IN.Y).BLDINFO.ID == 0) {
            BLD Vil;
			
			Elmt(*M,IN.X,IN.Y).BLDINFO.TYP = VLG;
			Elmt(*M,IN.X,IN.Y).BLDINFO.ID = Elmt(*M,IN.X,IN.Y).UNITINFO.P;
			
			Vil.TYP = VLG;
			Vil.ID = Elmt(*M,IN.X,IN.Y).UNITINFO.P;
			Vil.LOC = Elmt(*M,IN.X,IN.Y).UNITINFO.LOC;

			if (Elmt(*M,IN.X,IN.Y).UNITINFO.P==1) {
				InsVFirstB(&(*P1).VLGLST,Vil);
				(*P1).INC = NbElmtB((*P1).VLGLST)*5;
			} else if (Elmt(*M,IN.X,IN.Y).UNITINFO.P==2) {
				InsVFirstB(&(*P2).VLGLST,Vil);
				(*P2).INC = NbElmtB((*P2).VLGLST)*5;
			}
        } else if (Elmt(*M,IN.X,IN.Y).BLDINFO.TYP == VLG && (Elmt(*M,IN.X,IN.Y).BLDINFO.ID != Elmt(*M,IN.X,IN.Y).UNITINFO.P)) {
            BLD VilN,VilB;
			
			//Village Before
			VilB.TYP = VLG;
			VilB.ID = Elmt(*M,IN.X,IN.Y).BLDINFO.ID;
			VilB.LOC = Elmt(*M,IN.X,IN.Y).BLDINFO.LOC;

			Elmt(*M,IN.X,IN.Y).BLDINFO.TYP = VLG;
			Elmt(*M,IN.X,IN.Y).BLDINFO.ID = Elmt(*M,IN.X,IN.Y).UNITINFO.P;
			Elmt(*M,IN.X,IN.Y).BLDINFO.LOC = Elmt(*M,IN.X,IN.Y).UNITINFO.LOC;

			//Village after taken by other player
			VilN.TYP = VLG;
			VilN.ID = Elmt(*M,IN.X,IN.Y).UNITINFO.P;
			VilN.LOC = Elmt(*M,IN.X,IN.Y).UNITINFO.LOC;
			if (Elmt(*M,IN.X,IN.Y).UNITINFO.P==1) {
				InsVFirstB(&(*P1).VLGLST,VilN);
				DelPB(&(*P2).VLGLST,VilB);
			} else if (Elmt(*M,IN.X,IN.Y).UNITINFO.P==2) {
				InsVFirstB(&(*P2).VLGLST,VilN);
				DelPB(&(*P1).VLGLST,VilB);
			}
			(*P1).INC = NbElmtB((*P1).VLGLST)*5;
			(*P2).INC = NbElmtB((*P2).VLGLST)*5;
        } 
		*/

        //Emptying the place before moved.
        Elmt(*M,(*U).LOC.X,(*U).LOC.Y).UNITINFO.TYP = EMP;
        Elmt(*M,(*U).LOC.X,(*U).LOC.Y).UNITINFO.P = -1;

        //Updating unit location
		Temp.LOC.X = IN.X;
		Temp.LOC.Y = IN.Y;
		Temp.P = (*U).P;
	    Temp.TYP = (*U).TYP;
        Temp.RNGTYP = (*U).RNGTYP;
	    Temp.PRC = (*U).PRC;
	    Temp.MOVEPTS = (*U).MOVEPTS - Jarak;
        Temp.MAXMOVE = (*U).MAXMOVE;
	    Temp.ATK = (*U).ATK;
 	    Temp.HP = (*U).HP;
		Temp.CHN = (*U).CHN;
		Temp.PRB = (*U).PRB;
		Temp.MAXHP = (*U).MAXHP;
		if ((*U).P==1) {
			DelP(&(*P1).UNTLST,(*U));
			InsVFirst(&(*P1).UNTLST,Temp);
		} else if ((*U).P==2) {
			DelP(&(*P2).UNTLST,(*U));
			InsVFirst(&(*P2).UNTLST,Temp);
		}

		(*U) = Temp;
        printf("You have successfully moved to (%d, %d)",MX,MY);
    } 
}

void frecruit(Player * P1, Player * P2, MATRIKS *M, TurnQueue *Q) {
	int x,y,i,PlayerID,B,K;
	boolean valid,validin;
	Unit A;
	PlayerID = InfoHead(*Q).ID;

	B = NBrsEff(*M);
	K = NKolEff(*M);

	valid = false;
	validin = false;

    if ((PlayerID==1)&&(Elmt(*M,NBrsEff(*M)-2,1).UNITINFO.TYP == KNG)&&(Elmt(*M,B-2,0).UNITINFO.P==-1)&&(Elmt(*M,B-2,2).UNITINFO.P==-1)&&(Elmt(*M,B-1,1).UNITINFO.P==-1)&&(Elmt(*M,B-3,1).UNITINFO.P==-1)) {
        printf("Enter the coordinate of empty castle = ");
        scanf("%d %d",&x,&y);
        while ((Elmt(*M,x,y).UNITINFO.TYP != EMP)||(Elmt(*M,x,y).BLDINFO.ID != 1)){
            printf("That castle is occupied!!!\n");
            printf("Enter the coordinate of empty castle = ");
            scanf("%d %d",&x,&y);
        }
    } else if ((PlayerID==2)&&(Elmt(*M,1,NKolEff(*M)-2).UNITINFO.TYP == KNG) && (Elmt(*M,0,K-2).UNITINFO.P==-1) && (Elmt(*M,2,K-2).UNITINFO.P==-1) && (Elmt(*M,1,K-1).UNITINFO.P==-1) && (Elmt(*M,1,K-3).UNITINFO.P==-1) ) {
        printf("Enter the coordinate of empty castle = ");
        scanf("%d %d",&x,&y);
        while ((Elmt(*M,x,y).UNITINFO.TYP != EMP)||(Elmt(*M,x,y).BLDINFO.ID != 2)){
            printf("That castle is occupied!!!\n");
            printf("Enter the coordinate of empty castle = ");
            scanf("%d %d",&x,&y);
        }
    } else {
		printf("You can't recruit.\n");
	}

	if ((Elmt(*M,x,y).UNITINFO.TYP == EMP && Elmt(*M,x,y).BLDINFO.ID == PlayerID && PlayerID==1 && Elmt(*M,NBrsEff(*M)-2,1).UNITINFO.TYP == KNG)
		||(Elmt(*M,x,y).UNITINFO.TYP == EMP && Elmt(*M,x,y).BLDINFO.ID == PlayerID && PlayerID==2 && Elmt(*M,1,NKolEff(*M)-2).UNITINFO.TYP == KNG)) {

        printf("= = = = = = LIST OF RECRUITS = = = = = = \n");
        printf("1. Archer       | Health 29 | ATK 5 | 17G \n");
        printf("2. Swordsman    | Health 33 | ATK 4 | 14G \n");
        printf("3. White Mage   | Health 26 | ATK 2 | 15G \n");
        printf("Enter the number of unit you want to recruit = ");

        scanf("%d",&i);

		if (PlayerID == 1) {
			if (i==1) {
				if ((*P1).GLD - PRC_OF_ARC < 0) {
					valid = false;
				} else {
					valid = true;
				}
			} else if (i==2) {
				if ((*P1).GLD - PRC_OF_SWD < 0) {
					valid = false;
				} else {
					valid = true;
				}
			} else if (i==3) {
				if ((*P1).GLD - PRC_OF_WHT < 0) {
					valid = false;
				} else {
					valid = true;
				}
			}
		} else if (PlayerID == 2) {
			if (i==1) {
				if ((*P2).GLD - PRC_OF_ARC < 0) {
					valid = false;
				} else {
					valid = true;
				}
			} else if (i==2) {
				if ((*P2).GLD - PRC_OF_SWD < 0) {
					valid = false;
				} else {
					valid = true;
				}
			} else if (i==3) {
				if ((*P2).GLD - PRC_OF_WHT < 0) {
					valid = false;
				} else {
					valid = true;
				}
			}
		}
	}

	if (valid == true) {
        if (i==1) {
            Elmt(*M,x,y).UNITINFO.P = PlayerID;
	        Elmt(*M,x,y).UNITINFO.TYP = ARC;
	        Elmt(*M,x,y).UNITINFO.RNGTYP = RANGE;
	        Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_ARC;
            Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = 0;
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
            A.MOVEPTS = 0;
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
			printf("You have recruited an Archer \n");
            
        } else if (i==2) {
            Elmt(*M,x,y).UNITINFO.P = PlayerID;
	        Elmt(*M,x,y).UNITINFO.TYP = SWD;
	        Elmt(*M,x,y).UNITINFO.RNGTYP = MELEE;
            Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_SWD;
	        Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_SWD;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = 0;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_SWD;
			Elmt(*M, x, y).UNITINFO.PRB = PRB_SWD;
			Elmt(*M, x, y).UNITINFO.CHN = true;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_SWD;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_SWD;
            
            A.MAXHP = MAX_HP_SWD;
            A.HP = MAX_HP_SWD;
            A.ATK = ATK_SWD;
            A.MAXMOVE = MAX_MOVE_SWD;
            A.MOVEPTS = 0;
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
			printf("You have recruited a Swordsman \n");

        } else if (i==3) {
            Elmt(*M,x,y).UNITINFO.P = PlayerID;
	        Elmt(*M,x,y).UNITINFO.TYP = WHT;
	        Elmt(*M,x,y).UNITINFO.RNGTYP = RANGE;
            Elmt(*M,x,y).UNITINFO.PRC = PRC_OF_WHT;
	        Elmt(*M,x,y).UNITINFO.LOC.X = x;
	        Elmt(*M,x,y).UNITINFO.LOC.Y = y;
	        Elmt(*M,x,y).UNITINFO.MOVEPTS = MAX_MOVE_WHT;
            Elmt(*M,x,y).UNITINFO.MAXMOVE = 0;
	        Elmt(*M,x,y).UNITINFO.ATK = ATK_WHT;
 	        Elmt(*M,x,y).UNITINFO.HP = MAX_HP_WHT;
			Elmt(*M,x,y).UNITINFO.MAXHP = MAX_HP_WHT;
			Elmt(*M, x, y).UNITINFO.CHN = true;
			Elmt(*M, x, y).UNITINFO.PRB = PRB_WHT;
            
            A.MAXHP = MAX_HP_WHT;
            A.HP = MAX_HP_WHT;
            A.ATK = ATK_WHT;
            A.MAXMOVE = MAX_MOVE_WHT;
            A.MOVEPTS = 0;
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
			printf("You have recruited a White Mage \n");
        }
	} else {
        printf("You can't recruit.");
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

Unit fchange_unit(Player P) {
    int x,y,i,PlayerID;

    printf("\n====== LIST OF UNITS ======\n");
    PrintInfo((P).UNTLST);
    printf("Please enter the no. of unit you want to select: ");
    scanf("%d",&x);
    return SearchX((P).UNTLST,x);
    
}
