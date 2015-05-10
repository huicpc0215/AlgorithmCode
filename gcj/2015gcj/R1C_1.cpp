#include<iostream>
#include<cstdio>
using namespace std;
int R,C,W;
int dp[30][30];
int dfs(int c,int w){
    if( c <= w ) return w;
    return 1+dfs(c-w,w);
}

int main(){
//    freopen("test.in","r",stdin);
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&R,&C,&W);
        printf("Case #%d: %d\n",i,dfs(C,W)+(R-1)*(C/W));
    }
    return 0;
}
