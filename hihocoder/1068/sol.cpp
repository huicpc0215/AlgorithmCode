#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 1000010
#define INF 1000000
int n,m;
int RMQ[MAXN][21];
int query(int a,int b){
    int t=b-a,last=0;
    while( true ){
        if( t & (1<<last) ) t -= 1<<last;
        if( !t ) break;
        last ++ ;
    }
    return min( RMQ[a][last],RMQ[b-(1<<last)][last]);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    int a,b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&RMQ[i][0]);
    for(int i=1;i<20;i++)
        for(int j=1;j<=n;j++)
            if( j+(1<<(i-1)) <= n ) RMQ[j][i]=min(RMQ[j][i-1],RMQ[j+(1<<(i-1))][i-1]);
            else RMQ[j][i] = RMQ[j][i-1];
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",query(a,b+1));
    }
    return 0;
}
