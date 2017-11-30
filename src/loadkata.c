#include "boolean.h"
#include "loadkar.h"
#include "loadkata.h"

boolean LEndKata;
LKata LCKata;

void LIgnoreBlank(){
	while (((LCC==LBLANK) || (LCC==LNEWLINE)) && (LCC!=LMARK)){
		LADV();
	}
}

void LSTARTKATA(){
	LSTART();
	LIgnoreBlank();
	if ((LCC==LMARK) || (LCC==LNEWLINE)){
		LSalinKata();
		LEndKata=true;
	}
	else {
		LEndKata=false;
		LSalinKata();
	}
}

void LADVKATA(){
	LIgnoreBlank();
	if ((LCC==LMARK) || (LCC==LNEWLINE)){
		LEndKata=true;
	}
	else{
		LSalinKata();
	}	
}

void LSalinKata(){
	int i=1;
	for(;;){
		LCKata.TabKata[i]=LCC;
		LADV();
		if (((LCC==LMARK) || (LCC==LBLANK)) || (LCC==LNEWLINE) || (i>=LNMax)){
			break;
		} 
		else {
			i++;
		}
	}
	LIgnoreBlank();
	LCKata.Length=i;
}
