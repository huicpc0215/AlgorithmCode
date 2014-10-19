/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for hihocoder 1032 Longest Palindrome
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-19 19:16:15
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN (1000000)
char str[MAXN+10];
char st2[2*MAXN+10];
int p[2*MAXN+10];
int maxPalindrome(){
    int res=0,now;
    int len=strlen(str)*2+1;
    for(int i=0;i<len;i++){
        if(i&1)st2[i]=str[i/2];
        else if(i)st2[i]='$';
        else st2[i]='#';
        p[i]=1;
    }
    int far=0,farid;
    for(int i=1;i<len;i++){
        if( far > i )
            p[i]=min( p[2*farid-i],far-i);
        while(st2[i-p[i]]==st2[i+p[i]]) p[i]++;
        now = i&1? (p[i]-1)/2*2+1 : p[i]/2*2;
        res = res > now ? res : now;
        if( i+p[i]>far ){
            far = i + p[i];
            farid = i;
        }
    }
    return res;
}
int main(){
    //freopen("std.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        printf("%d\n",maxPalindrome());
    }
    return 0;
}
