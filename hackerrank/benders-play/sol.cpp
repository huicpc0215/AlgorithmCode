#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010


int n,m,q,k,u,v,tmp;
int sg[MAXN],cnt[MAXN];
vector<int> e[MAXN];

void dfs(int x){
    int sz = e[x].size();
    if( sz == 0 ) {
        sg[x]=0;
        return;
    }
    else if( sg[x]!=-1 ) return ;
    for(int i=0;i<sz;i++)dfs( e[x][i] );
    set<int> s;
    for(int i=0;i<sz;i++)s.insert( sg[ e[x][i] ] );
    int g=0;
    while( s.count(g)!=0 )g++;
    sg[x]=g;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        e[i].clear();
        cnt[i]=0;
        sg[i]=-1;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        cnt[v]++;
    }
    for(int i=1;i<=n;i++)
        if(cnt[i]==0)
            dfs(i);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&k);
        int val=0;
        for(int j=0;j<k;j++){
            scanf("%d",&tmp);
            val^=sg[ tmp ];
        }
        printf("%s\n",val?"Bumi":"Iroh");
    }
    return 0;
}
