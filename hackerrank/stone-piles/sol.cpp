#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,tmp;
int sg[100];
int dfs(int x);
void dfs2(int pos,int mx,int lastval,int left,bool *vis,int nowval);

void dfs2(int pos,int mx,int lastval,int left,bool *vis,int nowval){
    if( pos == mx ){
        if(left == 0) vis[ nowval ] = true;
        return;
    }
    for(int i=lastval+1;i<=left;i++)
        if( left-i >=0 )dfs2(pos+1,mx,i,left-i,vis,nowval^dfs(i));
        else break;
}
int dfs(int x){
    if(sg[x]!=-1) return sg[x];
    if( x<=2 ) return sg[x]=0;
    bool vis[50];
    memset(vis,false,sizeof vis);
    for(int i=2;i<10;i++){
        dfs2(0,i,0,x,vis,0);
    }
    for(int i=0;i<50;i++)
        if(!vis[i])
            return sg[x]=i;
}

int main(){
    for(int i=0;i<100;i++) sg[i]=-1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int val=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            val^=dfs(tmp);
        }
        printf("%s\n",val?"ALICE":"BOB");
    }

    return 0;
}
