/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for 1015 in hihocoder
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-19 18:42:47
#      History:
=============================================================================*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<limits.h>
using namespace std;
int T;
int next[10100];
char pre[10100];
char ori[1000100];
void getnext(){
    next[0]=-1;
    int j=-1;
    int sz=strlen(pre);
    for(int i=1;i<sz;i++){
        while((j+1)&&pre[i]!=pre[j+1]) j=next[j];
        if(pre[i]==pre[j+1])next[i]=j+1;
        else next[i]=j;
        j=next[i];
    }
}
int match(){
    int j=-1;
    int cnt=0;
    int sz=strlen(ori),last=strlen(pre)-1;
    for(int i=0;i<sz;i++){
        while((j+1)&&ori[i]!=pre[j+1]) j=next[j];
        if(ori[i]==pre[j+1])j++;
        if(j==last) cnt++;
    }
    return cnt;
}
int main(){
    //freopen("std.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",pre,ori);
        getnext();
        printf("%d\n",match());
    }
    return 0;
}
