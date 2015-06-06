#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int dp[1<<13][13];
bool inQ[1<<13][13];
// status , now point
pair<int,int> q[1<<20];
int mp[20][20];
int qfront,qend;

int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int a,b;
        qfront=0;qend=0;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++)
                dp[i][j]=inQ[i][j]=false;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mp[i][j]=0;

        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            mp[a][b]=1;
        }
        dp[1][0]=1;
        q[qend++]=make_pair(1,0);
        inQ[1][0] = true;

        while(qfront<qend){
            int nowstate = q[qfront].first;
            int u = q[qfront++].second;
            inQ[ nowstate ][ u ] = false;

            for(int v=0;v<n;v++){
                if( mp[u][v] && ( ( nowstate & ( 1<<v ) ) == 0 ) ){
                    dp[nowstate |(1<<v)][v] += dp[nowstate][u];
                    if( !inQ[ nowstate|(1<<v) ][ v ] ) {
                        q[qend++]= make_pair( nowstate|(1<<v),v ) ;
                        inQ[ nowstate|(1<<v) ][ v ] = true;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            if(mp[i][0])ans += dp[(1<<n)-1][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

