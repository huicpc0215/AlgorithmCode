#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 210
int dir[8][2]={{1,0},{1,-1},{1,1},{-1,0},{-1,1},{-1,-1},{0,1},{0,-1}};
int mp[MAXN][MAXN];
int mp2[MAXN][MAXN];
int t;
int n,m;
void st(int x,int y,int t){
    int nx,ny;
    for(int i=0;i<8;i++){
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if( nx < 0 || nx == n || ny < 0 || ny == m ) continue;
        else if( mp2[nx][ny]==-1 ){
            mp2[nx][ny]=t;
        }
    }
}
int cnt(int x,int y){
    int res=0;
    int nx,ny;
    for(int i=0;i<8;i++){
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if( nx < 0 || nx == n || ny < 0 || ny == m ) continue;
        else if( mp2[nx][ny]==-1 )res++;
    }
    return res;
}
void solve(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            mp2[i][j]=mp[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]==0)
                st(i,j,-2);
            else if(mp[i][j]==cnt(i,j)){
                st(i,j,-3);


            }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&mp[i][j]);
        solve();
    }
    return 0;
}
