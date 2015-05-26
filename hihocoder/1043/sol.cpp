#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[100010];

int main(){
    int n,W,w,v;
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d%d",&w,&v);
        for(int j=w;j<=W;j++){
            dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
    int ans=0;
    for(int i=0;i<=W;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
