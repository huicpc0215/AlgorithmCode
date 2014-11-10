#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Solution{
    public:
    int stksz;
    int longestValidParentheses(string s){
        int sz=s.length();
        int ans=0,tmpans=0;
        stksz=0;
        for(int i=0;i<sz;i++){
            if(s[i]=='(')
                stksz++;
            else {
                if(stksz){
                    stksz--;
                    tmpans+=2;
                }
                else {
                    tmpans=0;
                    stksz=0;
                }
                ans=max(ans,tmpans);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    string st1="(()";
    cout<<s.longestValidParentheses(st1)<<endl;
    string st2=")()()";
    cout<<s.longestValidParentheses(st2)<<endl;
    return 0;
}
