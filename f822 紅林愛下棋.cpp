#include <bits/stdc++.h>
using namespace std;

void print(int a, int b, int board1[11][11], int BW){
    if(board1[a+1][b]=='.') {board1[a+1][b]=BW; print(a+1,b,board1,BW);}
    if(board1[a][b+1]=='.') {board1[a][b+1]=BW; print(a,b+1,board1,BW);}
    if(board1[a][b-1]=='.') {board1[a][b-1]=BW; print(a,b-1,board1,BW);}
    if(board1[a-1][b]=='.') {board1[a-1][b]=BW; print(a-1,b,board1,BW);}
}

int main()
{
    int board[11][11], board_W[11][11], board_B[11][11] ;
    for(int i=0; i<11; i++)
        for(int j=0; j<11; j++){board[i][j]='S'; board_W[i][j]='S'; board_B[i][j]='S';}
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){board[i][j]=getchar(); board_W[i][j]=board[i][j]; board_B[i][j]=board[i][j];}
        getchar() ;
    }
    //for(int i=0; i<11; i++){for(int j=0; j<11; j++)printf("%c ", board[i][j]) ;printf("\n") ;}
    for(int i=1; i<10; i++)
        for(int j=1; j<10; j++){
            if(board[i][j]=='B') print(i,j,board_B,'B') ;
            if(board[i][j]=='W') print(i,j,board_W,'W') ;
        }
    //for(int i=0; i<11; i++){for(int j=0; j<11; j++)printf("%c ", board_W[i][j]) ;printf("\n") ;}
    //for(int i=0; i<11; i++){for(int j=0; j<11; j++)printf("%c ", board_B[i][j]) ;printf("\n") ;}
    int black=0, white=0 ;
    for(int i=1; i<10; i++)
        for(int j=1; j<10; j++){
            if(board_W[i][j]=='W'){white++; board[i][j]='W';}
            if(board_B[i][j]=='B'){black++; board[i][j]='B';}
            if(board_W[i][j]=='W'&&board_B[i][j]=='B'){printf("Wrong"); return 0;}
        }
    printf((black>white)?"Black wins!!\n":"White wins!!\n") ;
    printf("%d:%d\n", black, white) ;
    for(int i=1; i<10; i++){for(int j=1; j<10; j++)printf("%c", board[i][j]) ;printf("\n") ;}
    return 0;
}