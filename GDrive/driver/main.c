#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "math.h"
#include "boolean.h"
#include "gameproperty.h"
#include "mesinkar.h"
#include "mesinkata.h"

void Credits(){
	printf("\nKelompok Seksi Gorengan\n");
	printf("Aldo Azali........13516125\n");
	printf("Ivan Jonathan.....13516059\n");
	printf("Shevalda..........13516\n");
	printf("Seperayo..........13516068\n");
	printf("Hafizh Budiman....13516137\n\n");
	printf("Dosen : Bu Yani\n");
	getch();
	printf("\n");
	Display();
}

void InputToEksternal(){
	FILE * pita;
	char ch;
	pita = fopen("input.txt","w");
	while((ch = getchar())!='\n'){
		if(!(ch=='1') && !(ch=='2') && !(ch=='3') && !(ch=='4') && !(ch=='5') && !(ch=='6') && !(ch=='7') & !(ch=='8') && !(ch=='9') && !(ch=='0')){
			ch&='_';
		}
		putc(ch,pita);
	}
	putc('.',pita);
	fclose(pita);
}

void EksternalToInput(Kata *pilihan){
	STARTKATA();
	
	*pilihan = CKata;
}

boolean IsKataSama(Kata K1, Kata K2){
	int i;
	boolean bool=false;
	
	if(K1.Length==0 && K2.Length==0){
		bool=true;
	}
	else if(K1.Length==K2.Length){
		bool=true;
		i=1;
		while(i<=K1.Length && bool){
			if(K1.TabKata[i]!=K2.TabKata[i]){
				bool=false;
			}
			i++;
		}
	}
	return bool;
}

void Display(){
	printf("\nWelcome to Battle For Olympia !!\n\n");
	Menu();
}

void Menu(){
	Kata pilihan;
	Kata start,load,exit,satu,dua,tiga;
	Kata credit,empat;
	
	//BAGIAN ASSIGN STRING PILIHAN
	start.TabKata[1]='S';
	start.TabKata[2]='T';
	start.TabKata[3]='A';
	start.TabKata[4]='R';
	start.TabKata[5]='T';
	start.Length=5;
	load.TabKata[1]='L';
	load.TabKata[2]='O';
	load.TabKata[3]='A';
	load.TabKata[4]='D';
	load.Length=4;
	exit.TabKata[1]='E';
	exit.TabKata[2]='X';
	exit.TabKata[3]='I';
	exit.TabKata[4]='T';
	exit.Length=4;
	credit.TabKata[1]='C';
	credit.TabKata[2]='R';
	credit.TabKata[3]='E';
	credit.TabKata[4]='D';
	credit.TabKata[5]='I';
	credit.TabKata[6]='T';
	credit.Length=6;
	
	satu.TabKata[1]='1';
	satu.Length=1;
	dua.TabKata[1]='2';
	dua.Length=1;
	tiga.TabKata[1]='3';
	tiga.Length=1;
	empat.TabKata[1]='4';
	empat.Length=1;
	
	//BAGIAN MENU PROGRAM
	printf("********************\n");
	printf("* START........[1] *\n* LOAD.........[2] *\n* CREDITS......[3] *\n* EXIT.........[4] *\n"); //Menu Pilihan
	printf("********************\n");
	printf("\nWhat do you want to do? : ");
	InputToEksternal();
	EksternalToInput(&pilihan);
	if(IsKataSama(start,pilihan) || IsKataSama(satu,pilihan)){
		printf("Starting Game\n");
	}
	else if(IsKataSama(load,pilihan) || IsKataSama(dua,pilihan)){
		printf("Loading Previous Game\n");
	}
	else if(IsKataSama(credit,pilihan) || IsKataSama(tiga,pilihan)){
		Credits();
	}
	else if(IsKataSama(exit,pilihan) || IsKataSama(empat,pilihan)){
		printf("Exiting the Game\n");
	}
	else{
		printf("Input ERROR !!!\n");
		getch();
		printf("\n\n");
		Menu();
	}
}

int main(){
	Display();
	
	return 0;
}
