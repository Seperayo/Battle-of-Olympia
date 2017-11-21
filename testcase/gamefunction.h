#ifndef _gamefunction_H
#define _gamefunction_H

#include "gameproperty.h"
#include "boolean.h"
#include "listlinierunit.h"
#include "listlinierbuilding.h"
#include <stdlib.h>
#include "map.h"
#include "pcolor.h"

void frecruit(Player * P1, Player * P2, MATRIKS *M, TurnQueue *Q);
void InitializeQueue(Player * A, Player * B, MATRIKS * M, TurnQueue *Q);
<<<<<<< HEAD
Unit fchange_unit(Player P);
void fmove(Player * P1, Player * P2, MATRIKS *M, TurnQueue *Q, Unit * U);
void fattack(Player *P1, Player *P2, MATRIKS *M, TurnQueue *Q);
void calculateAttack(int x, int y, Player *P1, Player *P2, MATRIKS *M, int PlayerID, boolean isCanRetaliate);
=======
Unit fchange_unit(Player * P1, Player * P2, TurnQueue *Q);
>>>>>>> aee4c82421c0974469463d1344ffa2d17989c418

#endif
