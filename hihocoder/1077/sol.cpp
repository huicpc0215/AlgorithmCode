#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 1000010
#define INF 100000
int n,q,a,b;
int tree[MAXN*4];
void build(int l,int r,int k){
    if(l==r-1){
        scanf("%d",&tree[k]);
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,k<<1);
    build(m,r,(k<<1)+1);
    tree[k]=min( tree[k<<1] , tree[(k<<1)+1] );
}
void update(int x,int w,int l,int r,int k){
    if( x >= r  || x < l ) return ;
    if( l == r-1 ) {
        tree[k] = w;
        return ;
    }
    int m = ( l + r ) >> 1 ;
    if( x < m ) update(x,w,l,m,k<<1);
    else update(x,w,m,r,(k<<1)+1);
    tree[k] = min ( tree[k<<1], tree[(k<<1)+1]);
}

int query(int a,int b,int l,int r,int k){
    if( a >= r || l >= b ) return INF;
    if( a <=l && b>=r ) return tree[k];
    int m = ( l + r ) >> 1;
    return min(query(a,b,l,m,k<<1),query(a,b,m,r,(k<<1)+1));
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&n);
    build(1,n+1,1);
    scanf("%d",&q);
    int p,a,b;
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&p,&a,&b);
        if( p == 0 ) printf("%d\n",query(a,b+1,1,n+1,1));
        else update(a,b,1,n+1,1);
    }
    return 0;
}
