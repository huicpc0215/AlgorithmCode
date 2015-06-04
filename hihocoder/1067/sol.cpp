#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
using namespace std;

#define MAXN 100010
#define MAX_LOG_N 18
int n,m;
int sz = 1;
map<string,int> mp;
vector<int> e[MAXN];
bool isRoot[MAXN];
int depth[MAXN];
string sv[MAXN];
int parent[MAX_LOG_N][MAXN];
map<string,int>::iterator it;
string sc,sf;

void dfs(int x,int p,int d){
    depth[x]=d;
    parent[0][x]=p;
    int size = e[x].size();
    for(int i=0;i<size;i++){
        if(e[x][i]!=p)
            dfs(e[x][i],x,d+1);
    }
}

void init(){
    int rt;
    for(int i=1;i<sz;i++)
        if(isRoot[i]){
            rt = i;
            break;
        }
    dfs(rt,-1,0);
    for(int k=0;k+1<MAX_LOG_N;k++){
        for(int i=1;i<sz;i++){
            if( parent[k][i] == -1 ) parent[k+1][i]=-1;
            else parent[k+1][i]=parent[k][ parent[k][i] ];
        }
    }
    //for(int i=1;i<sz;i++){
    //    printf("i = %d  parent[17][i]=%d\n",i,parent[17][i]);
    //}
    //for(int i=1;i<sz;i++){
    //    cout<<"i ="<<i<<" string="<<sv[i]<<endl;
    //    for(int j=0;j<3;j++){
    //        cout<<"  "<<j<<"th parent is"<<" "<<parent[j][i]<<endl;
    //    }
    //}
}
string query(string &s1,string &s2){
    //cout<<"query = "<<s1<<"  "<<s2<<endl;
    int a=mp[s1],b=mp[s2];
    if(depth[a]<depth[b]) swap(a,b);
    //printf("a= %d b=%d\n",a,b);
    for(int k=0;k<MAX_LOG_N;k++)
        if( (depth[a]-depth[b])>>k&1 )
            a = parent[k][a];
    if(a==b) return sv[a];
    for(int k=MAX_LOG_N-1;k>=0;k--)
        if( parent[k][a] != parent[k][b] ){
            //printf("now a = %d b = %d\n",a,b);
            //printf("k = %d p[k][a]=%d p[k][b]=%d\n",k,parent[k][a],parent[k][b]);
            a = parent[k][a];
            b = parent[k][b];
            //printf("now a = %d b = %d\n",a,b);
        }
    //printf("a=%d b=%d\n",a,b);
    return sv[parent[0][a]];
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<MAXN;i++)
        isRoot[i]=true;
    for(int i=0;i<n;i++){
        cin>>sf>>sc;
        if( mp[sf] == 0 ) {
            mp[sf] = sz;
            sv[sz++]=sf;
        }
        if( mp[sc] == 0 ) {
            mp[sc] = sz;
            sv[sz++]=sc;
        }
        a = mp[sf]; b = mp[sc];
        isRoot[b] = false;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    init();
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin>>sf>>sc;
        cout<<query(sf,sc)<<endl;
    }
    return 0;
}
