#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 100010
vector<int> e[MAXN];
int match[MAXN];
bool dfs(int f,int x , int target){
    if( match[x] != -1 ){
        if( match[x] == target ) return true;
        else return false;
    }
    match[x] = target;
    int sz = e[x].size();
    for(int i=0;i<sz;i++)
        if( e[x][i] != f && !dfs(x,e[x][i],1-target) )
            return false;
    return true;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    int t,n,u,v,m;
    scanf("%d",&t);
    while( t-- ){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            e[i].clear();
            match[i]=-1;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        bool fg=true;
        for(int i=1;i<=n;i++){
            if( match[i]==-1 && !dfs(-1,i,0)){
                fg = false;
                break;
            }
        }
        printf("%s\n",fg?"Correct":"Wrong");
    }
    return 0;
}
