#ifndef _gamefunction_H
#define _gamefunction_H

#include "gameproperty.h"
#include "boolean.h"
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include <stdlib.h>
#include "map.h"
#include "pcolor.h"

boolean IsCastleFull(int P, MATRIKS M);
void frecruit(Player * P1, Player * P2, MATRIKS *M, TurnQueue *Q);
void InitializeQueue(Player * A, Player * B, MATRIKS * M, TurnQueue *Q);
Unit fchange_unit(Player P);
void fmove(Player * P1, Player * P2, MATRIKS *M, TurnQueue *Q, Unit * U);
void fattack(Player *P1, Player *P2, MATRIKS *M, TurnQueue *Q, Unit * U);
void RefreshAll(Player * P); 
void finfo(MATRIKS M);

void HealVillage(Player * P1, MATRIKS * M);
void HealWHT(Player * P1, MATRIKS * M);
void UpdatePlayer(Player * P);

boolean IsEndGame (Player P1, Player P2);
void WhoIsWinner(Player P1, Player P2);

#endif
