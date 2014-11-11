/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Longest Valid Parentheses
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-11-11 20:11:46
#      History:
=============================================================================*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Solution{
    public:
    int stk[100000],par[100000],stksz;
    int longestValidParentheses(string s){
        int res=0,tmpans=0;stksz=0;
        int sz=s.length();
        for(int i=0;i<sz;i++){
            if( s[i]=='(' ){
                stk[stksz++]=i;
                par[i]=-1;
            }
            else{
                if( stksz==0 ){
                    par[i]=-1;
                }
                else {
                    par[i]=stk[stksz-1];
                    par[ stk[stksz-1] ]=i;
                    stksz--;
                }
            }
        }
        for(int i=0;i<sz;){
            if(par[i]!=-1){
                tmpans+=par[i]-i+1;
                i=par[i]+1;
                res=max(res,tmpans);
            }
            else {
                tmpans=0;
                i++;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    string st1="()(()";
    cout<<s.longestValidParentheses(st1)<<endl;
    string st2=")()()";
    cout<<s.longestValidParentheses(st2)<<endl;
    return 0;
}
