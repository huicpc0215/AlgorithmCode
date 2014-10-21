/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Roman to Integer
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-21 11:04:31
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int charToInt(char c){
        if(c=='M') return 1000;
        else if(c=='D') return 500;
        else if(c=='C') return 100;
        else if(c=='L') return 50;
        else if(c=='X') return 10;
        else if(c=='V') return 5;
        else if(c=='I') return 1;
    }
    int romanToInt(string s){
        int sz=s.length();
        int res=0;
        for(int i=0;i<sz;){
            if( i<sz-1 && charToInt(s[i])<charToInt(s[i+1])){
                res+=charToInt(s[i+1])-charToInt(s[i]);
                i+=2;
            }
            else res+=charToInt(s[i++]);
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.romanToInt("IX")<<endl;
    cout<<s.romanToInt("XI")<<endl;
    cout<<s.romanToInt("IV")<<endl;
    cout<<s.romanToInt("XXIX")<<endl;

    return 0;
}
