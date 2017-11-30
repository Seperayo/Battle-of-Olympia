#include "mesinkata.h"
#include <stdio.h>

int main(){
		int a=0,i;
		STARTKATA();
		while(!EndKata){
				if(a>0)
					printf(" ");
				for(i=1;i<=CKata.Length;i++){
					printf("%c", CKata.TabKata[i]);
				}
		if(a==0)
				a=1;
		ADVKATA();
		}
		return 0;
}
