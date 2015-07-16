#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 100000000

int t,n,m,u,v,s;
vector<int> e[1010];
int dis[1010];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            e[i].clear();
            dis[i]=INF;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        scanf("%d",&s);
        dis[s]=0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            u = q.front(); q.pop();
            int sz = e[u].size();
            for(int i=0;i<sz;i++){
                v = e[u][i];
                if( dis[v] > dis[u] + 6 ){
                    dis[v] = dis[u] + 6;
                    q.push( v );
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i!=s){
                cnt++;
                printf("%d",dis[i]==INF?-1:dis[i]);
                if( cnt == n-1 )printf("\n");
                else printf(" ");
            }
        }
    }

    return 0;
}

