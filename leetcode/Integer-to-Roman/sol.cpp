/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Integer to Roman
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-20 20:56:44
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
    public:
    char dgtToRoman(int d,bool f){
        if(d==0) return f?'I':'V';
        else if(d==1) return f?'X':'L';
        else if(d==2) return f?'C':'D';
        else return 'M';
    }
    string intToRoman(int num){
        string ans="";
        int nm[10],sz=0;
        while(num){
            nm[sz++]=num%10;
            num/=10;
        }
        if(sz<4)nm[sz++]=0;
        while(sz--){
            int j=sz;
            bool check=false;
            if(j&&nm[j-1]==9){
                nm[j-1]=0;
                check=true;
            }
            if(nm[j]>4){
                ans=ans+dgtToRoman(j,0);
                nm[j]-=5;
                while(nm[j]--)ans=ans+dgtToRoman(j,1);
            }
            else if(nm[j]==4) ans=ans+dgtToRoman(j,1)+dgtToRoman(j,0);
            else while(nm[j]--)ans=ans+dgtToRoman(j,1);
            if(check)ans=ans+dgtToRoman(j-1,1)+dgtToRoman(j,1);
        }
        return ans;
    }
};
int main(){
    Solution S;
    cout<<S.intToRoman(29)<<endl;
    cout<<S.intToRoman(39)<<endl;
    cout<<S.intToRoman(49)<<endl;
    cout<<S.intToRoman(99)<<endl;


    return 0;
}
