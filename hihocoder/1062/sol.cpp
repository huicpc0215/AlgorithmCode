#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
using namespace std;

#define MAXN 1000
int n,m;
int sz = 1;
map< string,vector<string> > child;
map<string,string> father;
map<string,int> isRoot;
map<string,int>::iterator it;
map<string,int> depth;
string sc,sf;
int fa[MAXN];

void dfs(string x,int d){
    depth[x]=d;
    int sz = child[x].size();
    for(int i=0;i<sz;i++){
        dfs(child[x][i],d+1);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        cin>>sf>>sc;
        father[sc]=sf;
        child[sf].push_back(sc);
        isRoot[sc]=-1;
        if( !isRoot[sf] ) isRoot[sf]=1;
    }

    for(it=isRoot.begin();it!=isRoot.end();it++)
        if(it->second==1)
            dfs(it->first,1);
    /*
    for(int i=1;i<sz;i++){
        cout<<"i="<<i<<" string="<<sv[i]<<" depth="<<depth[i]<<endl;
    }
    */
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin>>sf>>sc;
        if(sf.compare(sc)==0){
            cout<<sf<<endl;
            continue;
        }
        else if(!depth[sf] || !depth[sc]){
            puts("-1");
            continue;
        }
        else {
            while(depth[sf]>depth[sc])sf=father[sf];
            while(depth[sc]>depth[sf])sc=father[sc];
            while( depth[sf] > 1 && sf.compare(sc)!=0 ){
                sf=father[sf];
                sc=father[sc];
            }
            if(sf.compare(sc)!=0)puts("-1");
            else cout<<sf<<endl;
        }
    }

    return 0;
}
