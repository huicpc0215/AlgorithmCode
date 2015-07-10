#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t,n;
int dp[40000],bx[20];
bool dfs(int x){
    if( dp[x]!=-1 ) return dp[x];
    int last=-1;
    bool fg = true;
    for(int i=0;i<n;i++){
        if( x & ( 1<<i ) ){
            if(bx[i]<=last){
                fg=false;
                break;
            }
            else {
                last = bx[i];
            }
        }
    }
    if( fg ) return dp[x]=false;
    for(int i=0;i<n;i++){
        if( x & ( 1<<i ) ){
            if( dfs( x& ~(1<<i) ) == false )
                return dp[x]=true;
        }
    }
    return dp[x]=false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<(1<<n);i++)
            dp[i]=-1;
        for(int i=0;i<n;i++){
            scanf("%d",&bx[i]);
        }
        printf("%s\n",dfs((1<<n)-1)?"Alice":"Bob");
    }
    return 0;
}
