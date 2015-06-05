#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 100010
#define SET_DL_FG -1
#define ADD_DL_FG 0
int n,m,p;
int tree[MAXN*4];
int delay0[MAXN*4];
int delay1[MAXN*4];
void build(int l,int r,int k){
    delay0[k]=ADD_DL_FG;
    delay1[k]=SET_DL_FG;
    if(l==r-1){
        scanf("%d",&tree[k]);
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,k<<1);
    build(m,r,(k<<1)+1);
    tree[k]=tree[k<<1]+tree[(k<<1)+1];
}
void update(int a,int b,int w,int l,int r,int k){
    if( a >= r || l >= b ) return ;
    if( a <=l && b >= r ){
        if( p == 0 ){
            delay0[k]+=w;
            tree[k]+=(r-l)*w;
        }
        else{
            delay0[k]=ADD_DL_FG;
            delay1[k]=w;
            tree[k]=(r-l)*w;
        }
        return ;
    }
    int m=(l+r)>>1;
    if( delay1[k]!=SET_DL_FG ){
        delay0[k<<1]=ADD_DL_FG ;
        delay0[(k<<1)+1]=ADD_DL_FG;
        delay1[k<<1]=delay1[k];
        delay1[(k<<1)+1]=delay1[k];
        tree[k<<1] = delay1[k] * (m - l);
        tree[(k<<1)+1] = delay1[k] * (r - m);
        delay1[k]=SET_DL_FG;
    }

    if( delay0[k]!=ADD_DL_FG){
        delay0[k<<1] += delay0[k];
        delay0[(k<<1)+1] += delay0[k];
        tree[k<<1] += delay0[k] * ( m - l );
        tree[(k<<1)+1] += delay0[k] * ( r - m );
        delay0[k] = ADD_DL_FG;
    }

    update(a,b,w,l,m,k<<1);
    update(a,b,w,m,r,(k<<1)+1);
    tree[k] = tree[k<<1]+tree[(k<<1)+1];
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);n++;
    build(0,n,1);
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&p,&a,&b,&c);
        update(a,b+1,c,0,n,1);
        printf("%d\n",tree[1]);
    }
    return 0;
}
