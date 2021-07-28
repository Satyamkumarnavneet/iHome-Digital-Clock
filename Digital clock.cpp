#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;


char d0[5][3] = {	177,177,177,
					177,' ',177,
					177,' ',177,
					177,' ',177,
					177,177,177	};
					
										
char d1[5][3] = {	' ',' ',177,
					' ',' ',177,
					' ',' ',177,
					' ',' ',177,
					' ',' ',177	};
					
					
char d2[5][3] = {	177,177,177,
					' ',' ',177,
					177,177,177,
					177,' ',' ',
					177,177,177	};
					
					
char d3[5][3] = {	177,177,177,
					' ',' ',177,
					177,177,177, 
					' ',' ',177,
					177,177,177	};
					
					
char d4[5][3] = {	177,' ',177,
					177,' ',177,
					177,177,177,
					' ',' ',177,
					' ',' ',177	};
					

char d5[5][3] = {	177,177,177,
					177,' ',' ',
					177,177,177,
					' ',' ',177,
					177,177,177	};
					

char d6[5][3] = {	177,177,177,
					177,' ',' ',
					177,177,177,
					177,' ',177,
					177,177,177	};
					

char d7[5][3] = {	177,177,177,
					' ',' ',177,
					' ',' ',177,
					' ',' ',177,
					' ',' ',177	};
					

char d8[5][3] = {	177,177,177,
					177,' ',177,
					177,177,177,
					177,' ',177,
					177,177,177	};
					

char d9[5][3] = {	177,177,177,
					177,' ',177,
					177,177,177,
					' ',' ',177,
					' ',' ',177	};


char sep[5][3] = {	' ',' ',' ',
					' ',177,' ',
					' ',' ',' ',
					' ',177,'  ',
					' ',' ',' '	};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //The GetStdHandle() function gives us a mechanism for retrieving the standard input
COORD CursorPosition;

//Basically, it gets a handle you can use to write to the console. SetConsoleCursorPosition then uses that handle and the …

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	
	//In console mode the typical need for set cursor position would be to "update" data in the same fixed position 
	//creating a refresh effect. This requirement need to set the cursor in the same point every time and start print characters. 
	//Each new print will overwrite the old data and this will create the dynamic update effect.
	
SetConsoleCursorPosition(console, CursorPosition);
}
void printDigit(int no, int x, int y ){
	 
	for(int i=0; i<5; i++){
		for(int j=0; j<3; j++){
			switch(no){
				case 0:
					gotoxy(x+j, y+i); cout<<d0[i][j]; break;
				case 1:
					gotoxy(x+j, y+i); cout<<d1[i][j]; break;
				case 2:
					gotoxy(x+j, y+i); cout<<d2[i][j]; break;
				case 3:
					gotoxy(x+j, y+i); cout<<d3[i][j]; break;
				case 4:
					gotoxy(x+j, y+i); cout<<d4[i][j]; break;
				case 5:
					gotoxy(x+j, y+i); cout<<d5[i][j]; break;
				case 6:
					gotoxy(x+j, y+i); cout<<d6[i][j]; break;
				case 7:
					gotoxy(x+j, y+i); cout<<d7[i][j]; break;
				case 8:
					gotoxy(x+j, y+i); cout<<d8[i][j]; break;
				case 9:
					gotoxy(x+j, y+i); cout<<d9[i][j]; break;
				case 10:
					gotoxy(x+j, y+i); cout<<sep[i][j]; break;
			} 
		}
	}
	
}

void drawBorder(int x=0, int y=0){
	char v = 186; // vertical
    char h = 205; // horizontal
    char tr = 187; //top right
    char br = 188; //bottom right
    char tl = 201; //top left
    char bl = 200; //bottom left
    int width = 50;
    int height = 11;
    
    gotoxy(((width/2)+x-11), y); // Calculating position of you are in the moment
	cout<<"**You're In The Moment**";
    
    for( int i=1; i<=height; i++ ){
		for( int j=1; j<=width; j++ ){
	    	gotoxy(j+x,i+y);
	    	if( i==1 && j==1 ) cout<< tl;
			else if( i==height && j==1 ) cout<< bl;
	    	else if( i==1 && j==width ) cout<< tr;
			else if( i==height && j==width ) cout<< br;
			else if( i==1 || i==height ) cout<< h;
			else if( j==1 || j==width ) cout<< v;
		}
	}
}

int main() {
	//system("cls");
	//Background color 
	//E for background Color // 5 for text color
    system("color 5E");  
 	
	time_t now = time(0);
   
	// convert now to string form
	char* dt = ctime(&now);
	// convert now to tm struct for UTC
	tm *lotm = localtime(&now);
 	int hour = lotm->tm_hour;  
 	int min  = lotm->tm_min;
 	int sec  = lotm->tm_sec;
	
	int gap  = 5;
	int posX ;
	int posY = 8;
	
	while(1){
		system("cls");
		drawBorder(5,4);
		posX  = 15;
		
		if(kbhit())
		{
			char ch = getch();
			if(ch==27){
				break;
			}
		} 
		if( hour < 10 ){
			printDigit(0, posX, posY);
			printDigit(hour, posX+=gap, posY);
		}
		else{
			printDigit(hour/10, posX, posY);
			printDigit(hour%10, posX+=gap, posY);
		}
		
		printDigit(10, posX+=gap, posY);
		
		if( min < 10 ){
			printDigit(0, posX+=gap, posY);
			printDigit(min, posX+=gap, posY);
		}
		else{
			printDigit(min/10, posX+=gap, posY);
			printDigit(min%10, posX+=gap, posY);
		}
		printDigit(10, posX+=gap, posY);
		if( sec < 10 ){
			printDigit(0, posX+=gap, posY);
			printDigit(sec, posX+=gap, posY);
		}
		else{
			printDigit(sec/10, posX+=gap, posY);
			printDigit(sec%10, posX+=gap, posY);
		}
		Sleep(1000); 
		sec++;
		if( sec>=60 ){
			sec = 0;
			min++;
		}
		if( min>=60 ){
			min = 0;
			hour++;
		}
		if( hour>=24 ){
			sec = 0;
			min = 0;
			hour = 0;
		}
		
			
	}
	
	return 0;
}

