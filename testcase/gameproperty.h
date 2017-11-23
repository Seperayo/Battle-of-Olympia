#ifndef _GAME_PROPERTY_
#define _GAME_PROPERTY_

#include "boolean.h"
#include "point.h"
#include "listlinierunit.h"
#include "listlinierbuilding.h"

/*Definisi constant property unit
* Untuk yang masih kosong harus lihat game dulu
*/

#define Nil NULL

typedef struct {
	int ID; //ID player, player 1,2,...,n
	int GLD;
    ListUnit UNTLST; //Units List
	ListBuilding VLGLST; //Villages List
	int INC; //Income
	int OUT; //UpKeep atau Outcome
	char CLR[8]; //Color, Lihat pcolor.h
} Player;

void Display();
void Menu(int *option);

#endif