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
void fchange_unit(Player * P1, Player * P2, TurnQueue *Q, addressunit *X);

#endif
