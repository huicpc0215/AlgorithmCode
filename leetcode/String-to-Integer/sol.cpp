/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for String to Integer
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-18 21:13:49
#      History:
=============================================================================*/
#include<iostream>
#include<cmath>
#include<limits.h>
#include<cstring>
#include<cstdio>
using namespace std;

class Solution{
    public:
    int atoi(const char *str){
        long long int res=0; if(strlen(str)==0) return 0;
        int i=0;
        int nag=0,nagpos,pospos;
        int pos=0;
        while(str[i] && (str[i]<'0'||str[i]>'9')){
            if(str[i]=='-') {
                nagpos=i;
                nag++;i++;

            }
            else if(str[i]=='+') {
                pos++;
                pospos=i;i++;
            }
            else if(str[i]==' ')i++;
            else break;
        }
        if(nag||pos) i=max(nagpos,pospos)+1;
        if(nag+pos>1)return 0;
        while(str[i]) {
            if(str[i]>='0'&&str[i]<='9')
                res=res*10+str[i]-'0';
            else if(res>INT_MAX){
                return nag?INT_MIN:INT_MAX;
            }
            else return nag?-res:res;
            i++;
        }
        if(res>INT_MAX){
            return nag?INT_MIN:INT_MAX;
        }
        return nag?-res:res;
    }
};
int main(){
    Solution S;
    cout<<S.atoi("2147483648")<<endl;
    cout<<S.atoi("+-123")<<endl;
    cout<<S.atoi("+1")<<endl;
    cout<<S.atoi("-01")<<endl;
    cout<<S.atoi("       010")<<endl;
    cout<<S.atoi("       0    1    0")<<endl;
    cout<<S.atoi("-10000000")<<endl;
    return 0;
}
