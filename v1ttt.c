#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
char badray[10];
int rannumgenerator;
void assignor(){
	rannumgenerator = (rand() %9) + 1;
	if(rannumgenerator==1){
		badray[0]='O';
	}
	else if(rannumgenerator==2){
		badray[1]='O';
    }
    else if(rannumgenerator==3){
		badray[2]='O';
    }
    else if(rannumgenerator==4){
		badray[3]='O';
    }
    else if(rannumgenerator==5){
		badray[4]='O';
    }else if(rannumgenerator==6){
		badray[5]='O';
    }
    else if(rannumgenerator==7){
		badray[6]='O';
    }
    else if(rannumgenerator==8){
		badray[7]='O';
    }
    else{
    	badray[8]='O';
	}
}
void drawdash(){
	printf(" %c  | %c  | %c   \n___ ___ ___\n %c  | %c  | %c  \n___ ___ ___\n %c  | %c  | %c  \n", badray[0], badray[1], badray[2], badray[3], badray[4], badray[5], badray[6], badray[7], badray[8]);
}
int main(){
	rannumgenerator = (rand() %9) + 1;
	char bingo[4]="";
	int j;
	char lingo[4]="";
	char dingo[4]="";
	srand(time(NULL));
	int i=0;
	printf("Welcome to Tic-Tac-Toe\n");
	printf("Do you want to play?\n");
	scanf("%s", bingo);
	if (strcasecmp(bingo,"yes")==0) {
		printf("GREAT CHOICE!! WELCOME ABOARD!!\n");
		printf("We'll begin with the instructions to the game.\n");
		printf("1. There are 9 squares.\n");
		printf("2. You can mark one of those boxes.\n");
		printf("3. Enter the number of box you want to mark.\n");
		printf("4. Boxes marked by you will be visible as X.\n");
		printf("5. Boxes marked by the computer will be visible as O.\n");
		printf("6. First to mark a continuos row,column or diagonal WINS!\n");
		printf("Enter player name:");
		scanf("%s", lingo);
		printf("GAME ON!!!!!\n");
		drawdash();
		printf("Who takes the first turn?bot or %s?\n",lingo);
		scanf("%s", dingo);
		if(strcasecmp(dingo,lingo)==0){
			while(i<9){
				i++;
				printf("TURN %d\n",i);
				if(i%2==0){
				assignor();
				drawdash();
				}
			}
	    }
	}
	else if(strcasecmp(bingo,"no")==0) {
		printf("Maybe another time >_<");
	}
	else{
		printf("Please enter a valid yes or no input");
	}
	return 0;
} 
