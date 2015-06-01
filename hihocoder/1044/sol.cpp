#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[2][1028];
int cnt[1028];
int n,m,q,tmp;
inline int getCnt(int x){
    int res = 0;
    while(x){
        res++;
        x-=x&(-x);
    }
    return res;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    int w=0,mx=1<<m;
    dp[0][0]=0,cnt[0]=0;
    scanf("%d",&tmp);
    for(int i=1;i<mx;i++){
        dp[0][i]=(i==1)?tmp:0;
        cnt[i]=getCnt(i);
    }
    for(int i=1;i<n;i++){
        memset(dp[w^1],0,sizeof (dp[w^1]) );
        scanf("%d",&tmp);
        for(int j=0;j<mx;j++){
            if( cnt[j&((1<<(m-1))-1)] < q )
                dp[w^1][ ((j&((1<<(m-1))-1))<<1)+1 ] = max( dp[w^1][ ((j&((1<<(m-1))-1))<<1)+1 ], dp[w][j]+tmp);
            dp[w^1][ (j&((1<<(m-1))-1))<<1 ] = max ( dp[w^1][ (j&((1<<(m-1))-1))<<1 ],dp[w][j] );
        }
        w^=1;
    }
    int ans = 0;
    for(int i=0;i<mx;i++)
        ans = max( ans , dp[w][i]);
    printf("%d\n",ans);
    return 0;
}
