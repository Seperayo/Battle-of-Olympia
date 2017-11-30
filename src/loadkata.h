#ifndef __LOADKATA_H__
#define __LOADKATA_H__

#include "boolean.h"
#include "loadkar.h"

#define LNMax 50
#define LBLANK ' '
#define LNEWLINE '\n'
#define LMINUS '-'
#define LFLOAT '.'

typedef struct {
	char TabKata[LNMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} LKata;

/* State Mesin Kata */
extern boolean LEndKata;
extern LKata LCKata;

void LIgnoreBlank();
void LSTARTKATA();
void LADVKATA();
void LSalinKata();
#endif
