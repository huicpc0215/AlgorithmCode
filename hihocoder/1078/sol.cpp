#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXN 100010
#define DL_FG 1000000
int n,q;
long long tree[MAXN*4];
long long delay[MAXN*4];

void build(int l,int r,int k){
    if(l==r-1){
        scanf("%lld",&tree[k]);
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,k<<1);
    build(m,r,(k<<1)+1);
    tree[k]= tree[k<<1] + tree[(k<<1)+1] ;
    delay[k]=DL_FG;
}
void update(int a,int b,int w,int l,int r,int k){
    if( a >= r  || l >= b ) return ;
    if( a<=l && b>=r ){
        delay[k]=w;
        tree[k]=(r-l)*w;
        return ;
    }
    int m = (l+r)>>1;
    if( delay[k]!=DL_FG ){
        delay[k<<1]=delay[k];
        delay[(k<<1)+1]=delay[k];
        tree[k<<1]=(m-l)*delay[k];
        tree[(k<<1)+1]=(r-m)*delay[k];
        delay[k]=DL_FG;
    }
    update(a,b,w,l,m,k<<1);
    update(a,b,w,m,r,(k<<1)+1);
    tree[k] = tree[k<<1]+tree[(k<<1)+1];
}

long long query(int a,int b,int l,int r,int k){
    if( a >= r || l >= b ) return 0;
    if( a <=l && b>=r )
        return tree[k];
    int m = ( l + r ) >> 1;
    if(delay[k] != DL_FG ){
        delay[k<<1] = delay[k];
        delay[(k<<1)+1] = delay[k];
        tree[k<<1] = (m-l)*delay[k];
        tree[(k<<1)+1] = (r-m)*delay[k];
        delay[k] = DL_FG;
    }
    return query(a,b,l,m,k<<1)+query(a,b,m,r,(k<<1)+1);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&n);
    build(1,n+1,1);
    scanf("%d",&q);
    int p,a,b,c;
    for(int i=0;i<q;i++){
        scanf("%d",&p);
        if( p == 0 ) {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a,b+1,1,n+1,1));
        }
        else {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b+1,c,1,n+1,1);
        }
    }
    return 0;
}
