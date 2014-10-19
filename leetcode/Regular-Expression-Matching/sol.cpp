/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Regular Expression Matching
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-19 20:05:44
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
class Solution{
    public:
    bool isMatch(const char *s,const char *p){
        if( *p=='\0' ) return *s=='\0';

        if( *(p+1) !='*' ){
            if( *p==*s || (*p=='.' && *s!='\0' ) )
                return isMatch(s+1,p+1);
            else return false;
        }
        else {
            while( *p==*s || (*p=='.' && *s!='\0') ){
                if(isMatch(s,p+2))
                    return true;
                s++;
            }
            return isMatch(s,p+2);
        }
    }
};
int main(){
    Solution S;
    printf("%c\n",S.isMatch("aa","a")?'y':'n');
    printf("%c\n",S.isMatch("aa","aa")?'y':'n');
    printf("%c\n",S.isMatch("aaa","aa")?'y':'n');
    printf("%c\n",S.isMatch("aa","a*")?'y':'n');
    printf("%c\n",S.isMatch("ab",".*")?'y':'n');
    printf("%c\n",S.isMatch("aab","c*a*b")?'y':'n');


    return 0;
}
