#include<iostream>
#include<string.h>
#include<window.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char currentmarker;
int currentplayer=1;

void drawboard()
{
cout<<" "<< board[0][0]<< " | "<<board[0][1]<< " | "<<board[0][2];
cout<<"\n------------\n";
cout<<" "<< board[1][0]<< " | "<<board[1][1]<< " | "<<board[1][2];
cout<<"\n------------\n";
cout<<" "<< board[2][0]<< " | "<<board[2][1]<< " | "<<board[2][2];
cout<<"\n\n";
}

bool placemarker(int slot)
{
int row,col;

if(slot%3==0)
{
row=(slot/3)-1;
}
else
{
row=slot/3;
}
if(slot%3==0)
{
col=2;
}
else
{
col=(slot%3)-1;
}
if(board[row][col]=='X' || board[row][col]=='O')
{
return false;
}
else
{
board[row][col] = currentmarker;
return true;
}
}

char winner()
{
int i=0;
for(i=0;i<3;i++)
{
if(board[i][0]==board[i][1] && board[i][1]==board[i][2] )
{
return currentplayer;
}
if(board[0][i]==board[1][i] && board[1][i]==board[2][i] )
{
return currentplayer;
}
if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
{
return currentplayer;
}
if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
{
return currentplayer;
}
}
return 0;
}

void swap()
{
if(currentmarker=='X')
{
currentmarker='O';
}
else
currentmarker='X';
}


void game()
{
int playerwon;
bool yes;
cout<<"\nplayer one choose your marker:\n";
char markerp1;
cin>>markerp1;

currentmarker=markerp1;

for(int i=1;i<=9;i++)
{
if(i%2==0)
{
currentplayer=2;
}
else if(i%2!=0)
{
currentplayer=1;
}
cout<<"\nits's player"<<currentplayer<<"'s turn.Enter your slot\n";
int slot;
cin>>slot;
if(slot>9 || slot<=0)
{
cout<<"enter a valid slot";
i--;
continue;
}
yes=placemarker(slot);
if(yes!=true)
{
cout<<"\nslot is already occupied!\n";
i--;
continue;
}
playerwon=winner();
if(playerwon==1)
{
cout<<"\nPlayer 1 won!\n";
drawboard();
break;
}
else if(playerwon==2)
{
cout<<"\nPlayer 2 won\n";
drawboard();
break;
}
swap();
drawboard();
}
if(playerwon==0)
{
cout<<"\nthat is a tie!\n";
drawboard();
}
}


int main()
{
int win;
game();
}

