#ifndef _GAME_PROPERTY_
#define _GAME_PROPERTY_

#include "boolean.h"
#include "point.h"
#include "listlinierunit.h"
#include "listlinierbuilding.h"

/*Definisi constant property unit
* Untuk yang masih kosong harus lihat game dulu
*/
#define MAX_HP_ARC 70
#define MAX_HP_SWD 90
#define MAX_HP_KNG 100
#define MAX_HP_WHT //*masih kosong
#define MAX_MOVE_ARC 7
#define MAX_MOVE_SWD 10
#define MAX_MOVE_KNG //*masih kosong
#define MAX_MOVE_WHT //*masih kosong
#define PRC_OF_ARC //*masih kosong
#define PRC_OF_SWD //*masih kosong
#define PRC_OF_KNG //*masih kosong
#define PRC_OF_WHT //*masih kosong
#define ATK_ARC //*masih kosong
#define ATK_SWD //*masih kosong
#define ATK_KNG //*masih kosong
#define ATK_WHT //*masih kosong
#define MELEE 'm'
#define RANGE 'r'

/*Character in Game*/
#define KNG 'K'
#define ARC 'A'
#define SWD 'S'
#define WHT 'W'
#define EMP ' ' //Jika di petak ga ada unit
/*Building in Game*/
#define TWR 'T'
#define CST 'C'
#define VLG 'V'
#define NRM 'N'

typedef struct {
	int ID; //ID player, player 1,2,...,n
	int GLD;
    ListUnit UNTLST; //Units List
	ListBuilding VLGLST; //Villages List
	int INC; //Income
	int OUT; //UpKeep atau Outcome
	char CLR[8]; //Color, Lihat pcolor.h
} Player;

struct tUnit{
	int MAXHP;
	int HP;
	int ATK;
	int MAXMOVE;
	int MOVEPTS; //Initial -> MOVEPTS = MAXMOVE
	POINT LOC;
	int PRC; //Price
	int RNG; //Range ATK | 1 untuk King dan Swordsman | x untuk Archer, x belum ditentukan
	char RNGTYP; //Range type, m = melee | r = ranged
	char TYP; //Jenis pasukan A, S, W, K
	Player P;
	float CHN; //Chance to Attack
};

struct tBuilding{
	Player P;
	POINT LOC;
	char TYP;
};

void Display();
void Menu();
#endif
