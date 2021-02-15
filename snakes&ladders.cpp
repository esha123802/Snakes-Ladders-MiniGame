#include<iostream>
using namespace std;
#include<stdlib.h>
#include<windows.h>
#include <wincon.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}
void sandl(int i);
int board();//printing the board
char game();//actual game
char name[5][20];//name of the player
void play();//name and symbol assign of player
int n;//number of players
char pos[101][4];//on the board
int loci[5]={0,0,0,0}; //location of each player
char player[5][4];//each player symbol
void pause()
{
   std::cout<<"Press enter to continue!";
   cin.sync();
   cin.ignore();
}
int dice()//for the dice
{
	int roll;
	srand(time(NULL));
	roll=rand()%10+1;
	if(roll>=7&&roll<=10)
	 roll=roll-4;
	if(roll==1)
	{
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
    }
	else if(roll==2)
	{	
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*    |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|    *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	else if(roll==3)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*    |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|    *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	else if(roll==4)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;		
	}
	else if(roll==5)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;		
	}
	else if(roll==6)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	return roll;
}
int dice2()//when rolled 6
{
	int roll;
	srand(time(NULL));
	roll=rand()%10+1;
	if(roll>=7&&roll<=10)
	 roll=roll-4;
	if(roll==1)
	{
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
    }
	else if(roll==2)
	{	
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*    |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|    *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	else if(roll==3)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*    |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|    *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	else if(roll==4)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;		
	}
	else if(roll==5)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;		
	}
	else if(roll==6)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	return roll;
}
int dice3()//for the dice
{
	int roll;
	srand(time(NULL));
	roll=rand()%10+1;
	if(roll>=7&&roll<=10)
	 roll=roll-4;
	if(roll==1)
	{
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
    }
	else if(roll==2)
	{	
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*    |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|    *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	else if(roll==3)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*    |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|    *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	else if(roll==4)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|     |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;		
	}
	else if(roll==5)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|  *  |"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;		
	}
	else if(roll==6)
	{
     cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<"|*   *|"<<endl;
	 cout<<"\t \t \t \t \t"<<"      "<<" -----"<<endl;
	}
	return roll;
}
void posi()//for putting the value on the board
{        
  	int i; 
	  char o[101][4];//                        
	for(i=1;i<=100;i++) 
	{
	 itoa(i,o[i],10);
	 strcpy(pos[i],o[i]);
	}         
}
int main()
{
	cout<<"\t \t \t \t \t"<<"     HELLO!";
	 cout<<"\n"<<"\t \t \t \t \t"<<"SNAKES AND LADDER"<<"\n \n";
	 play();
	 cout<<"\n"<<"\t\t\t\t\t"<<"    "<<"Lets play!!!"<<endl<<endl; 
	 posi();
     board();
     game();
     cout<<endl;
	return 0;
}
int board()
{
	cout<<"\t \t \t"<<"----------------------------------------------------------------------"<<endl;
	cout<<"\t \t \t"<<"| "<<pos[100]<<"  |  "<<pos[99]<<"  |  "<<pos[98]<<"  |  "<<pos[97]<<"  |  "<<pos[96]
	      <<"  |  "<<pos[95]<<"  |  "<<pos[94]<<"  |  "<<pos[93]<<"  |  "<<pos[92]<<"  |  "<<pos[91]<<"  |"<<"\n";
    cout<<"\t \t \t"<<"|      |      |  ''  |      |      | |__| |      |      |      |  ''  |"<<endl;
    cout<<"\t \t \t"<<"-----------------00----------------- |__| ------------------------00---"<<endl;
	cout<<"\t \t \t"<<"|  "<<pos[81]<<"  |  "<<pos[82]<<"  |  ||"<<pos[83]<<"|  "<<pos[84]<<"  |  "<<pos[85]
	      <<"  |  "<<pos[86]<<"  |  "<<pos[87]<<"  |  "<<pos[88]<<"  |  "<<pos[89]<<"  | // "<<pos[90]<<"|"<<"\n";
	      cout<<"\t \t \t"<<"|      | |__| |   \\\\ |      |      | |__| |      |      |      |//    |"<<endl;
	cout<<"\t \t \t"<<"---------|__|  ----\\\\------------------------------------------//------"<<endl;
	cout<<"\t \t \t"<<"|  "<<pos[80]<<"  |  "<<pos[79]<<"  |  "<<pos[78]<<" \\\\  "<<pos[77]<<"  |  "<<pos[76]
	      <<"  |  "<<pos[75]<<"  |  "<<pos[74]<<"  |  "<<pos[73]<<"  |  "<<pos[72]<<" //  "<<pos[71]<<"  |"<<"\n";
	      cout<<"\t \t \t"<<"|      | |__| |      \\\\     |      |      | |__| |      |    //|      |"<<endl;
	cout<<"\t \t \t"<<"---------|__| --------\\\\--------------------|__|------------//--------"<<endl;
	cout<<"\t \t \t"<<"|  "<<pos[61]<<"  |  "<<pos[62]<<"  |  "<<pos[63]<<"  | \\\\"<<pos[64]<<" |  "<<pos[65]
	      <<"  |  "<<pos[66]<<"  |  "<<pos[67]<<"  |  "<<pos[68]<<"  |  //"<<pos[69]<<"|  "<<pos[70]<<"  |"<<"\n";
	      cout<<"\t \t \t"<<"|      | |__| |      |  \\\\  |      |      | |__| |      |  U   |      |"<<endl;
	cout<<"\t \t \t"<<"---------|__| -----------\\\\-----------------|__|-----------------------"<<endl;
	cout<<"\t \t \t"<<"|  "<<pos[60]<<"  |  "<<pos[59]<<"  |  "<<pos[58]<<"  | "<<pos[57]<<" \\\\|  "<<pos[56]
	      <<"  |  "<<pos[55]<<"  |  "<<pos[54]<<"  |  "<<pos[53]<<"  |  "<<pos[52]<<"  |  "<<pos[51]<<"  |"<<"\n";	        
	      cout<<"\t \t \t"<<"|      | |__| |      |     \\\\      |      | |__| |      |      |      |"<<endl;
    cout<<"\t \t \t"<<"---------|__| --------------\\\\--------------|__|-----------------------"<<endl;
	cout<<"\t \t \t"<<"|  "<<pos[41]<<"  |  "<<pos[42]<<"  |  "<<pos[43]<<"  |  "<<pos[44]<<"  |\\\\"<<pos[45]
	      <<"  |  "<<pos[46]<<"  |  "<<pos[47]<<"  |  "<<pos[48]<<"  |  "<<pos[49]<<"  |  "<<pos[50]<<"  |"<<"\n";
    cout<<"\t \t \t"<<"|  ''  | |__| |      |      | \\\\   |      | |__| |      |      | |__| |"<<endl;
	cout<<"\t \t \t"<<"---00--- |__| -----------------\\\\--------------------------------|__|--"<<endl;
	cout<<"\t \t \t"<<"|  ||"<<pos[40]<<"|  "<<pos[39]<<"  |  "<<pos[38]<<"  |  "<<pos[37]<<"  | "<<pos[36]
	      <<"\\\\ |  "<<pos[35]<<"  |  "<<pos[34]<<"  |  "<<pos[33]<<"  |  "<<pos[32]<<"  |  "<<pos[31]<<"  |"<<"\n";
    cout<<"\t \t \t"<<"|   \\\\ | |__| |      |      |    \\\\|      |      |  ''  |      | |__| |"<<endl;
    cout<<"\t \t \t"<<"-----\\\\---------------------------\\\\----------------00-----------|__|--"<<endl;
	cout<<"\t \t \t"<<"|  "<<pos[21]<<" \\\\  "<<pos[22]<<"  |  "<<pos[23]<<"  |  "<<pos[24]<<"  |  "<<pos[25]
	      <<"  \\\\ "<<pos[26]<<"  |  "<<pos[27]<<"  | // "<<pos[28]<<"|  "<<pos[29]<<"  |  "<<pos[30]<<"  |"<<"\n";
    cout<<"\t \t \t"<<"|      \\\\     |      | |__| |      |U     |      |//    |      | |__| |"<<endl;
	cout<<"\t \t \t"<<"--------\\\\------------ |__| ---------------------//--------------------"<<endl; 
	cout<<"\t \t \t"<<"|  "<<pos[20]<<"  | "<<"\\\\ "<<pos[19]<<"|  "<<pos[18]<<"  |  "<<pos[17]<<"  |  "<<pos[16]
	      <<"  |  "<<pos[15]<<"  |  "<<pos[14]<<" //  "<<pos[13]<<"  |  "<<pos[12]<<"  |  "<<pos[11]<<"  |"<<"\n";		  		  		  	      
    cout<<"\t \t \t"<<"|      |  U   |      | |__| |      |      |    //|      |      |      |"<<endl;
	cout<<"\t \t \t"<<"-----------------------|__|-------------------//-----------------------"<<endl;
	cout<<"\t \t \t"<<"|   "<<pos[1]<<"  |   "<<pos[2]<<"  |  "<<pos[3]<<"   |  "<<pos[4]<<"   |  "<<pos[5]
	      <<"   |  "<<pos[6]<<"   |  // "<<pos[7]<<"|  "<<pos[8]<<"   |  "<<pos[9]<<"   |  "<<pos[10]<<"  |"<<"\n";	      
	cout<<"\t \t \t"<<"|      |      |      | |__| |      |      |  U   |      |      |      |"<<endl;
	cout<<"\t \t \t"<<"-----------------------------------------------------------------------"<<endl;	  	   
	for(int i=1;i<=n;i++)
	cout<<"\t \t \t \t \t"<<"Position of "<<name[i]<<" is:"<<loci[i]<<endl;
	
}
void play()
{
	
	int i;
	cout<<endl<<"\t \t \t \t"<<"Enter number of players:";
	cin>>n;
	cin.ignore();
	for(i=1;i<=n;i++)
	{
	 cout<<"\t \t \t \t"<<"Enter name of player"<<i<<":"<<flush;
	 gets(name[i]);
	}

	if(n==2)
	 {
		strcpy(player[1],"@");
		strcpy(player[2],"#");
	 } 
	else if(n==3)
	 {
		strcpy(player[1],"@ ");
		strcpy(player[2],"# ");
		strcpy(player[3],"% ");
	 } 
	 else if(n==4)
	 {
		strcpy(player[1],"@ ");
		strcpy(player[2],"# ");
		strcpy(player[3],"% ");
		strcpy(player[4],"& ");
	 } 
	 cout<<"\t \t \t \t"<<"The symbols for the players are:"<<endl<<endl;	 
	 for(i=1;i<=n;i++)
 	  	cout<<"\t \t \t \t \t"<<"      "<<name[i]<<"-->"<<player[i]<<endl;
}
char game()
{
	char r[4];
	int i,l,l1,l2;
    while(strcpy(pos[100],"100")!=0)
    {

 	  for(i=1;i<=n;i++)
 	  {
 	   pause();
	    system("cls");
	     if(i==1)
	      system("color 09");
	     if(i==2)
	      system("color 0A");
	     if(i==3)
	      system("color 0C");
	     if(i==4)
	      system("color 0E"); 
 	  	cout<<name[i]<<" roll the dice!"<<endl;
 	  	getch();
 	  	l=dice();
 	  	if(l==6)
 	  	 {
 	  	 	cout<<"Roll again!!"<<endl;
 	  	 	getch();
 	  	 	l1=dice2();
 	  	 	if(l1==6)
 	  	 	 {
 	  	 	 	cout<<"Roll again!!"<<endl;
 	  	 	 	getch();
 	  	 	    l2=dice3();
 	  	 	     if(l2==6)
 	  	 	      {
 	  	 	       cout<<"YOU MISSED YOUR CHANCE"<<endl;
 	  	 	       l=0;
 	  	 	      } 
 	  	 	     else l=l+l1+l2;
 	  	     }
 	  	 	else l=l+l1;
			}
		//int p;
 	  	loci[i]=loci[i]+l;
 	  	sandl(i);
 	  	 if(loci[i]>100)
 	  	  loci[i]=loci[i]-l;
       /* for(p=0;p<l;p++)
        {
        	loci[i]+=1;
				strcpy(pos[loci[i]],player[i]);
				//delay(100);
				//system("cls");
 	    }*/
 	    strcpy(pos[loci[i]],player[i]);
 	    if(strcpy(pos[loci[i]],"@ ")!=0) //put the number back in the board 
 	  	 {
 	  	 	if(strcpy(pos[loci[i]],"# ")!=0)
 	  	 	 {
 	  	 	 	if(strcpy(pos[loci[i]],"% ")!=0)
 	  	 	 	 {
 	  	 	 	 	if(strcpy(pos[loci[i]],"& ")!=0)
 	  	 	 	 	{
 	  	 	 	 		strcpy(pos[loci[i]],itoa(loci[i],r,10));
						  }
					  }
				 }
			}
 	  	 if(loci[i]==100)
 	  	  {
      	   cout<<name[i]<<" HAS WON!!!!!!";
      	   exit(0);
          }
 	  	board();
	   }
    }
}
void sandl(int i)
{

  if(loci[i]==4)
   {
    loci[i]=24;
    cout<<"\t \t \t \t \t"<<"LADDER!!!!"<<endl;
   }
  if(loci[i]==30)
   {
    loci[i]=50;
     cout<<"\t \t \t \t \t"<<"LADDER!!!!"<<endl;
   }
  if(loci[i]==39)
   {
    loci[i]=82;
     cout<<"\t \t \t \t \t"<<"LADDER!!!!"<<endl;
   }
  if(loci[i]==47)
   {
    loci[i]=74;
     cout<<"\t \t \t \t \t"<<"LADDER!!!!"<<endl;
   }
  if(loci[i]==86)
   {
    loci[i]=95;
     cout<<"\t \t \t \t \t"<<"LADDER!!!!"<<endl;
   }
  if(loci[i]==98)
   {
    loci[i]=26;
     cout<<"\t \t \t \t \t"<<"SNAKE!!!!"<<endl;
   }
  if(loci[i]==91)
   {
    loci[i]=69;
     cout<<"\t \t \t \t \t"<<"SNAKE!!!!"<<endl;
   }
  if(loci[i]==41)
   {
    loci[i]=19;
     cout<<"\t \t \t \t \t"<<"SNAKE!!!!"<<endl;
   }
  if(loci[i]==33)
   {
    loci[i]=7;	
     cout<<"\t \t \t \t \t"<<"SNAKE!!!!"<<endl;
   }
}

 /*      ''
        00
       //
      //
     //                  
    // 
	\/  */
