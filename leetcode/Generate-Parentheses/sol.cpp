/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Generate Parentheses
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-25 19:53:05
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
class Solution{
    public:
    string sk;
    vector<string> ans;
    int last;
    void dfs(int pos,int cnt){
        if( cnt < 0 || cnt > last-pos || cnt < pos - last) return ;
        if(pos==last){
            ans.push_back(sk);
            return ;
        }
        sk=sk+'(';
        dfs(pos+1,cnt+1);
        sk=sk.substr(0,sk.length()-1);

        sk=sk+')';
        dfs(pos+1,cnt-1);
        sk=sk.substr(0,sk.length()-1);
    }
    vector<string> generateParenthesis(int n){
        ans.clear();
        last=2*n;
        dfs(0,0);
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> ans=s.generateParenthesis(3);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
