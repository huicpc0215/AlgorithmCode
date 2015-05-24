#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
#define MAXN 1010
deque< pair<int,int> > q;
set< pair<int,int> > st;
int kmp[MAXN][MAXN],n,m,k;
int knmp[MAXN][MAXN];
int kx,ky,knx,kny;
int k_dt[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1}};
int kn_dt[8][2]={{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1}};

void spfa(int px,int py,int mp[MAXN][MAXN],int dir[8][2]){
    mp[px][py]=0;
    st.clear();
    st.insert( make_pair(px,py) );
    q.push_back(make_pair(px,py) );
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        st.erase( st.find( q.front() ) );
        q.pop_front();
        for(int i=0;i<8;i++){
            int vx=tmp.first,vy=tmp.second;
            int nx=vx+dir[i][0];
            int ny=vy+dir[i][1];
            if( nx >=1 && nx <=n && ny>= 1 && ny <= m){
                if( mp[nx][ny] > mp[vx][vy] + 1 ){
                    mp[nx][ny] = mp[vx][vy] + 1 ;
                    if( st.find(make_pair(nx,ny))==st.end() ){
                        if( q.empty() || mp[nx][ny] < mp[q.front().first][q.front().second] ){
                            q.push_front(make_pair(nx,ny));
                        }
                        else q.push_back(make_pair(nx,ny));
                        st.insert(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}
int main(){
    int T,cnt=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",cnt++);
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                kmp[i][j]=knmp[i][j]=k+1;
            }
        }
        scanf("%d%d",&kx,&ky);
        spfa(kx,ky,kmp,k_dt);
        scanf("%d%d",&knx,&kny);
        spfa(knx,kny,knmp,kn_dt);
        int ans = k+1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if( (kmp[i][j]-knmp[i][j])%2 == 0 ){
                    ans = min ( ans, max( kmp[i][j], knmp[i][j]) );
                }
            }
        }
        if(ans==k+1)puts("OH,NO!");
        else printf("%d\n",ans);
    }
    return 0;
}
