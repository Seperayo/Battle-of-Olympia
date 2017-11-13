/* Nama file :  driver_turnqueue.c */

#include "turnqueue.h"
#include "gameproperty.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TurnQueue Q;
    int id;
    Player pl;

    InitializeTurnQueue(&Q);

    scanf("%d", &id);
    while (id != -999) {
        Player pla;
        pla.ID = id;
        AddQ(&Q, pla);
        scanf("%d", &id);
    }

    while (!IsQueueEmpty(Q)) {
        DelQ(&Q, &pl);
        printf("Player %d deleted\n", pl.ID);
    }
    
    return 0;
}