/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Count and Say
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-11-17 21:17:48
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution{
    public:
    char str[2][100000];
    int tmp[100];
    string countAndSay(int n){
        int x=n-1;
        int w=0;
        str[0][0]='1';str[0][1]='\0';
        while(x--){
            int len = strlen(str[w]);
            int cnt=1;
            int len2 =0;
            for(int i=0;i<len;i++){
                if( str[w][i]==str[w][i+1] ){
                    cnt++;
                }
                else {
                    int tmpcnt=0;
                    while(cnt){
                        tmp[tmpcnt++]=cnt%10;
                        cnt/=10;
                    }
                    for(tmpcnt--;tmpcnt>=0;){
                        str[w^1][len2++]=tmp[tmpcnt--]+'0';
                    }
                    str[w^1][len2++]=str[w][i];
                    cnt=1;
                }
            }
            str[w^1][len2]='\0';
            w^=1;
        }
        string res;
        res=str[w];
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.countAndSay(1)<<endl;
    cout<<s.countAndSay(2)<<endl;
    cout<<s.countAndSay(3)<<endl;
    cout<<s.countAndSay(4)<<endl;
    cout<<s.countAndSay(5)<<endl;
    return 0;
}

