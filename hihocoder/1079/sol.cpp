#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 1000010
#define DL_FG -1
int mp[MAXN*6];
int post[MAXN][2];
int tree[MAXN*24];
int delay[MAXN*24];

int n,l,cnt;

void add(int p){
    for(int i=0;i<2;i++)
        for(int j=-1;j<2;j++)
            mp[cnt++]=post[p][i]+j;
}
void build(int l,int r,int k){
    delay[k]=DL_FG;
    tree[k]=-1;
    if(l==r-1) return ;
    int m = (l+r)>>1;
    build(l,m,k<<1);
    build(m,r,(k<<1)+1);
}

void update(int a,int b,int x,int l,int r,int k){
    if( a >= r || l >= b ) return ;
    if( a <= l && b >= r ){
        delay[k]=x;
        tree[k]=x;
        return ;
    }
    int m = ( l + r ) >> 1;
    if( delay[k] != DL_FG ){
        delay[k<<1]=delay[k];
        delay[(k<<1)+1]=delay[k];
        tree[k<<1]=delay[k];
        tree[(k<<1)+1]=delay[k];
        delay[k]=DL_FG;
    }
    update(a,b,x,l,m,k<<1);
    update(a,b,x,m,r,(k<<1)+1);
}

int query(int x,int l,int r,int k){
    if( x >= r || l > x ) return -1;
    if( x==l && l == r-1 ) return tree[k];
    int m=(l+r)>>1;
    if( delay[k] != DL_FG ){
        delay[k<<1]=delay[k];
        delay[(k<<1)+1]=delay[k];
        tree[k<<1]=delay[k];
        tree[(k<<1)+1]=delay[k];
        delay[k]=DL_FG;
    }
    if( x < m ) return query(x,l,m,k<<1);
    else return query(x,m,r,(k<<1)+1);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d%d",&n,&l);
    cnt = 0 ;
    for(int i=0;i<n;i++){
        scanf("%d%d",&post[i][0],&post[i][1]);
        add(i);
    }
    sort(mp,mp+cnt);
    cnt = unique(mp,mp+cnt)-mp;
    for(int i=0;i<n;i++){
        post[i][0] = lower_bound(mp,mp+cnt,post[i][0]) - mp ;
        post[i][1] = lower_bound(mp,mp+cnt,post[i][1]-1) - mp +1;
    }
    build(0,cnt,1);
    for(int i=0;i<n;i++)
        update( post[i][0],post[i][1],i,0,cnt,1);
    set<int> st;
    for(int i=0;i<cnt;i++)
        st.insert(query(i,0,cnt,1));
    //    st.insert( query(i,0,cnt,1) );
    printf("%d\n",st.size()-1);
    return 0;
}
