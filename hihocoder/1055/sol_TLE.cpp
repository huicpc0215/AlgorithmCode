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

int dfsp(int x,int f,int pos,int sz,int r,int nowv);
int dfs(int x,int r,int f);

int dfsp(int x,int f,int pos,int sz,int r,int nowv){
    if( pos == sz ) return nowv;
    if(e[x][pos]==f) return dfsp(x,f,pos+1,sz,r,nowv);
    int ret = 0;
    for(int i=0;i<=r;i++)
        ret = max( ret, dfsp(x,f,pos+1,sz,r-i,nowv+dfs(e[x][pos],i,x)) );
    return ret;
}

int dfs(int x,int r,int f){
    if( dp[x][r] !=-1 ) return dp[x][r];
    if( r <= 1 ) return dp[x][r]=(r==1)?v[x]:0;
    return dp[x][r]=dfsp(x,f,0,e[x].size(),r-1,v[x]);
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
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            dp[i][j]=-1;
    printf("%d\n",dfs(1,m,0));
    return 0;
}
