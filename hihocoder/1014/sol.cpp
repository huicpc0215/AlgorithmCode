/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for 1014
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-10-17 16:23:12
#      History:
=============================================================================*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXNODE 1000000
#define CC(m,what) memset(m,what,sizeof m)
int child[MAXNODE][26];
int cnt[MAXNODE]={0},sz=1;
int gao(char *a,int f)
{
    int p=0,i=0;
    while(a[i])
    {
        int t=a[i]-'a';
        if(!child[p][t]){
            if(!f) return 0;
            CC(child[sz],0);
            cnt[sz]=0;
            child[p][t]=sz++;
        }
        p=child[p][t];
        if(f)cnt[p]++;
        i++;
    }
    return cnt[p];
}

int main()
{
    //freopen("std.in","r",stdin);
    int n;
    while( scanf("%d",&n)!=EOF)
    {
    CC(child[0],0);
    sz=1;
    char str[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        gao(str,1);
    }
    //puts("ok");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        printf("%d\n",gao(str,0));
    }
    }
    return 0;
}
