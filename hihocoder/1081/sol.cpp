#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 10010
#define INF 10000000
int n,m,s,t;
vector< pair<int,int> > e[MAXN];
bool inQ[MAXN];
deque<int> q;
int d[MAXN];
void spfa(int x){
    for(int i=0;i<=n;i++) d[i]=INF;
    d[x]=0;
    q.push_back(x);
    inQ[ x ] = true;
    while(!q.empty()){
        int u = q.front();q.pop_front();
        inQ[u]=false;
        int sz = e[u].size();
        for(int i=0;i<sz;i++){
            int v = e[u][i].first , w = e[u][i].second;
            if( d[v] > d[u] + w ){
                d[v] = d[u] + w;
                if( !inQ[v] ){
                    if( q.empty() || d[q.front()] > d[ v ] ) q.push_front(v);
                    else q.push_back(v);
                    inQ[v]=true;
                }
            }
        }


    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    int u,v,w;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(make_pair(v,w));
        e[v].push_back(make_pair(u,w));
    }
    spfa(s);
    printf("%d\n",d[t]);
    return 0;
}
