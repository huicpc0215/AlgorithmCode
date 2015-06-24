#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 1000010

struct edge{
    int u,v,w;
    edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){};
    bool operator < (const edge & e)const {
        return w<e.w;
    }
};
vector<edge> E;
int belong[MAXN];

int find_father(int x){
    if( x==belong[x] ) return x;
    return belong[x]=find_father(belong[x]);
}

void uni(int u,int v){
    int fu=find_father(u),fv=find_father(v);
    belong[fu]=fv;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    int n,m,u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        E.push_back(edge(u,v,w));
        belong[u]=u;belong[v]=v;
    }
    sort(E.begin(),E.end());
    int cnt=0,res=0;
    for(int i=1;i<n;i++){
        while( find_father( E[cnt].u ) == find_father( E[cnt].v ) ) cnt++;
        res += E[cnt].w;
        uni(E[cnt].u,E[cnt].v);
        cnt++;
    }
    printf("%d\n",res);
}
