/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for leetcode Wildcard Matching
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-12-07 21:37:44
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
        if( *p=='\0' ) return *s=='\0';

        if( *p !='*' ){
            if( *p==*s || (*p=='?' && *s!='\0' ) )
                return isMatch(s+1,p+1);
            else return false;
        }
        else {
            while(*(p+1)=='*')p++;
            while( true ){
                if(isMatch(s,p+1)) return true;
                if(*s=='\0') return false;
                else s++;
            }
        }
    }
};
int main(){
    Solution s;
    printf("check = %s\n",s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba","a*******b")?"YES":"NO");
    return 0;
}
