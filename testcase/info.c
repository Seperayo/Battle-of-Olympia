/* Command INFO */
#include "gameproperty.h"
#include "listlinierunit.h"
#include "point.h"
#include "map.h"
#include "time.h"
#include "pcolor.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void commandINFO(MATRIKS M)
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
