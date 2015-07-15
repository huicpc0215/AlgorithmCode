#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int t,n,tmp;
int sg[100];
set<int> s;

void dfs( int pos, int lastval, int mx, int left, int val ){
    if( pos == mx ) {
        if( left == 0 )s.insert( val );
        else return ;
    }
    for(int i=lastval+1;i<=left;i++)
        dfs( pos + 1 , i , mx , left - i , val^sg[i] );
}
int grundy(int x){
    s.clear();
    for(int i=2;i*(i+1)/2 <= x;i++)
        dfs( 0 , 0 , i , x , 0 );
    int g=0;
    while(s.count(g)!=0) g++;
    return sg[x]=g;
}

int main(){
    //freopen("1.txt","r",stdin);
    for(int i=0;i<100;i++) sg[i]=-1;
    sg[0]=sg[1]=sg[2]=0;
    for(int i=3;i<=50;i++) grundy(i);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int val=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            val^=sg[tmp];
        }
        printf("%s\n",val?"ALICE":"BOB");
    }

    return 0;
}
