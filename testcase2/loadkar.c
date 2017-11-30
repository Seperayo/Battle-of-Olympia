#include "loadkar.h"
#include <stdio.h>

char LCC;
boolean LEOP;

static FILE * lpita;
static int lretval;

void LSTART() {
	/* Algoritma */
	lpita = fopen("load.txt","r");
	LADV();
}

void LADV() {
	/* Algoritma */
	lretval = fscanf(lpita,"%c",&LCC);
	LEOP = (LCC == LMARK);
	if (LEOP) {
       fclose(lpita);
 	}
}
