#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long dp[2][200];
#define MOD 1000000007
int n,m,w,now;
void dfs(int s,int p){
    if( p == m ){
        dp[w^1][s] = (dp[w^1][s]+now)%MOD;
        return ;
    }
    dfs(s,p+1);
    if( p<m-1 && !(s&(3<<p)) )
        dfs( s|(3<<p) , p+2 );
}
int main(){
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    w = 0; now = 1;
    dfs(0,0);
    w^=1;
    for(int i=1;i<n;i++){
        memset(dp[w^1],0,sizeof(dp[w^1]));
        for(int j=0;j<(1<<m);j++){
            if( dp[w][j] ){
                now = dp[w][j];
                dfs( (~j)&((1<<m)-1),0 );
            }
        }
        w^=1;
    }
    printf("%lld\n",dp[w][(1<<m)-1]);
    return 0;
}

