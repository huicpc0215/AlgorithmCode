/*=============================================================================
#     FileName: sol.cpp
#         Desc: 1038
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-05-21 23:28:12
#      History:
=============================================================================*/

#include<iostream>
#include<cstdio>
#include<limits.h>
using namespace std;
#define MAXM 100010
int n,m,w,v;
int dp[MAXM];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=m;i++){
        dp[i]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&w,&v);
        for(int j=m;j>=w;j--){
            dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
