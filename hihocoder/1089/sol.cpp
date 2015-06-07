#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 110
#define INF 10000000
int n,m;
int mp[MAXN][MAXN];
int d[MAXN][MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    int u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)d[i][j]=INF;
            else d[i][j]=0;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        d[u][v]=d[v][u]=min(d[u][v],w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min( d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            printf("%d%c",d[i][j],j==n?'\n':' ');
    return 0;
}
