/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Letter Combinations of a Phone Number
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-22 23:01:01
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;
class Solution{
    public:
    string tmp;
    int sz;
    vector<string> ans;
    vector<char> mp[10];
    void dfs(string digits,int k){
        //cout<<tmp<<endl;
        if(k==sz){
            ans.push_back(tmp);
            return ;
        }
        for(int i=0;i<mp[ digits[k]-'0' ].size();i++){
            tmp=tmp+mp[digits[k]-'0'][i];
            dfs(digits,k+1);
            tmp=tmp.substr(0,tmp.length()-1);
        }
    }
    void init(){
        int cnt=2;
        for(int i=0;i<26;i++){
            if(i<16&&i%3==0&&i>0)cnt++;
            if(i==19||i==22)cnt++;
            mp[cnt].push_back(char('a'+i));
        }
    }
    vector<string> letterCombinations(string digits){
        init();
        sz=digits.length();
        dfs(digits,0);
        return ans;
    }
};
int main(){

    string s; Solution S;
    s="23";
    vector<string> ans=S.letterCombinations(s);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;

    return 0;
}
