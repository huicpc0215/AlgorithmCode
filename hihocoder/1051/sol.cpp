#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int sum[110];
int T,n,m,tmp;
int main(){
    scanf("%d",&T);
    while(T--){
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            sum[tmp]++;
        }
        for(int i=1;i<=100;i++)
            sum[i]+=sum[i-1];
        int ans = 0;
        for(int i=1;i<=100;i++)
            for(int j=i;j<=100;j++)
                if( sum[j]-sum[i-1] <= m )
                    ans = max( ans , j-i+1);
        printf("%d\n",ans);
    }
    return 0;
}
