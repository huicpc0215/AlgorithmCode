#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int len,n,m;
bool dfs(char board[3][4],char *word,int x,int y,int pos){
    if( pos == len ) return true;
    if(  x <0 || x >= n || y < 0 || y >= m  ||  board[x][y] != word[pos] ) return false;
    char old = board[x][y];
    board[x][y]='$';
    int nx,ny,i;
    for(i=0;i<4;i++)
        if( dfs(board,word,x+dir[i][0],y+dir[i][1],pos+1) ) return true;
    board[x][y]=old;
    return false;
}
bool exist(char board[3][4], int boardRowSize, int boardColSize, char* word) {
    if( word == NULL )  return true;
    len = strlen(word);
    n = boardRowSize;
    m = boardColSize;
    bool res = false;
    int i,j;
    for(i=0;i<boardRowSize;i++)
        for(j=0;j<boardColSize;j++)
            if( word[0]==board[i][j] ){
                printf("in here");
                if(dfs(board,word,i,j,0))
                    return true;
            }
    return false;
}
int main(){
    char a[3][4];
    a[0][0]='A';
    a[0][1]='B';
    a[0][2]='C';
    a[0][3]='E';
    a[1][0]='S';
    a[1][1]='F';
    a[1][2]='C';
    a[1][3]='S';
    a[2][0]='A';
    a[2][1]='D';
    a[2][2]='E';
    a[2][3]='E';
    return 0;
}
