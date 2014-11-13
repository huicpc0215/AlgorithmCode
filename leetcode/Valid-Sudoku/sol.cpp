/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode valid sudoku
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-11-13 21:21:46
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
class Solution{
    public:
    bool isValidSudoku(vector< vector<char> > &board){
        // colume
        for(int i=0;i<9;i++){
            bool f[10]={false};
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(f[ board[i][j]-'0' ]) return false;
                f[ board[i][j]-'0' ]=true;
            }
            for(int j=0;j<10;j++)f[j]=false;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                if(f[ board[j][i]-'0' ]) return false;
                f[ board[j][i]-'0' ]=true;
            }
        }
        // block
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                bool f[10]={false};
                for(int p=0;p<3;p++){
                    for(int q=0;q<3;q++){
                        if(board[i+p][j+q]=='.')continue;
                        if(f[board[i+p][j+q]-'0'])return false;
                        f[ board[i+p][j+q]-'0' ]=true;
                    }
                }

            }
        }
        return true;
    }
};
int main(){

}

