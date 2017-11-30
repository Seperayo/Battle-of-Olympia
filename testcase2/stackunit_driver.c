#include <stdio.h>
#include "stackunit.h"
#include "listlinierunit.h"

int main(){
    Unit X;
    Stack S1;
    MATRIKS M;
    X.MAXHP = 100;
    X.HP = 100;
    X.ATK = 100;
    X.MAXMOVE =100;
    X.MOVEPTS =100;
    X.LOC.X = 8;
    X.LOC.Y = 8;
    X.PRC = 100;
    X.RNGTYP = 'r';
    X.TYP = 'A';
    X.P = 100;
    X.CHN = true;
    X.PRB = 54.4;
    CreateEmptyS(&S1);
    if(IsEmptyS(S1) && !IsFullS(S1)){
        Push(&S1,X);
    }
    printf("tahap 2");
    if(IsOneS){
        Pop(&S1,&M,&X);
    }
    printf("selesai");
    return 0;
}
