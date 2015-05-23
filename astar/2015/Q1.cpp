#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 1000010
#define MOD 1000000007
long long dp[MAXN];
int cnt,n,t;
int main(){
    dp[0]=dp[1]=1;
    cnt=1;
    for(int i=2;i<MAXN;i++){
        dp[i]=(dp[i-1]+((long long)(i-1)*dp[i-2]%MOD))%MOD;
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        printf("Case #%d:\n%lld\n",cnt++,dp[t]);
    }
    return 0;
}
