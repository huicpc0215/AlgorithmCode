/*=============================================================================
#     FileName: sol.cpp
#         Desc: hihocoder week 5
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-05-23 11:41:06
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
using namespace std;
int dp[2][110],w,tmp,n;
int main(){
    scanf("%d",&n);
    w=0;
    for(int i=0;i<110;i++){
        for(int j=0;j<2;j++){
            dp[j][i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            scanf("%d",&tmp);
            dp[w^1][j]=max(dp[w][j]+tmp,dp[w^1][j]);
            dp[w^1][j+1]=max(dp[w][j]+tmp,dp[w^1][j+1]);
        }
        w^=1;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[w][i]);
    }
    printf("%d\n",ans);
    return 0;
}
