/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for Palindrome Number
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-18 21:27:35
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Solution{
    public:
    char st[100];
    bool isPalindrome(int x){
        int sz=0;
        if(x<0) return false;
        long long y=x;y=abs(y);
        while(y){
            st[sz++]=y%10;
            y/=10;
        }
        for(int i=0;i<sz;i++)
            if(st[i]!=st[sz-1-i])
                return false;
        return true;
    }
};

int main(){
    Solution S;
    cout<<S.isPalindrome(21312)<<endl;
    cout<<S.isPalindrome(456)<<endl;
    cout<<S.isPalindrome(-1)<<endl;
    return 0;
}
