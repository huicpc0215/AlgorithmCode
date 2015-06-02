#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
#define MAXN 110
int dp[MAXN][MAXN];
int v[MAXN];
vector<int> e[MAXN];
int n,m,a,b;
void dfs(int x,int f){
    dp[x][0]=0;
    dp[x][1]=v[x];
    int sz = e[x].size();
    for(int i=0;i<sz;i++){
        if( e[x][i]==f ) continue;
        dfs(e[x][i],x);
        // this can't be 0,1 package problem
        // is a group package problem
        // for each group that can at most one can be choose!
        for(int j=m;j>1;j--)
            for(int k=1;k<j;k++)
                dp[x][j] = max( dp[x][j], dp[x][ j-k ] + dp[ e[x][i] ][ k ] );
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    memset(dp,0,sizeof (dp));
    int ans = 0;
    dfs(1,0);
    for(int i=0;i<=m;i++)
        ans = max( ans , dp[1][i]);
    printf("%d\n",ans);
    return 0;
}
