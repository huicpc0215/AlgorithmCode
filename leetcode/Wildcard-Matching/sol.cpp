/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for leetcode Wildcard-Matching
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-12-13 12:07:23
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
    public:
    bool isMatch(const char *s,const char *p){
        const char *star=NULL;
        const char *sPos=s;
        while( *s ){
            if( *p=='?'||*p==*s){
                p++;s++;
            }
            else if( *p=='*' ){
                star=p++;
                sPos=s;
            }
            else if( star ){
                p=star+1;
                s=++sPos;
            }
            else return false;
        }
        while(*p=='*')p++;
        return *p=='\0';
    }
};
int main(){
    Solution s;
    printf("%s\n",s.isMatch("abc","*")?"YES":"NO");
    return 0;
}
