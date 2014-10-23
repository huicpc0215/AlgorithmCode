/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Valid Parentheses
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-23 20:22:15
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
    public:
    char stk[1000];
    bool isValid(string s){
        int sz=s.length();
        int stksz=0;
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk[stksz++]=s[i];
            else if(s[i]==')'){
                if(stksz==0||stk[stksz-1]!='(')return false;
                else stksz--;
            }
            else if(s[i]=='}'){
                if(stksz==0||stk[stksz-1]!='{')return false;
                else stksz--;
            }
            else if(stksz==0||stk[stksz-1]!='[')return false;
            else stksz--;
        }
        return stksz==0;
    }
};

int main(){
    Solution s;
    string str="()";
    cout<<s.isValid(str)<<endl;
    str="()[]{}";
    cout<<s.isValid(str)<<endl;
    str="(]";
    cout<<s.isValid(str)<<endl;
    str="({)]";
    cout<<s.isValid(str)<<endl;
    return 0;
}
