#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n;
vector< set<int> > e[1010];

void read(int idx){
    int cnt,tmp=0;
    set<int> s;
    scanf("%d",&cnt);
    while( cnt && scanf("%d",&tmp) ){
        if( tmp ) s.insert( tmp ) , cnt--;
        else {
            e[idx].push_back(s);
            s.clear();
        }
    }
    if(!s.empty())e[idx].push_back(s);
}
struct section{
    int mx_height;
    int length;
    section(int h,int l):mx_height(h),length(l){};
    bool operator<(const section & a)const {
        return mx_height - length > a.mx_height - a.length ;
    }
};
int dfs(int idx){
    int sz = e[idx].size();
    if( sz == 0 ) return 1;
    section *sec = (section *)malloc(sizeof(section)*sz);
    set<int>::iterator it;
    for(int i=0;i<sz;i++){
        int *row_mx = (int *) malloc( sizeof(int) * e[idx][i].size() );
        int row_cnt=0;
        for(it=e[idx][i].begin();it!=e[idx][i].end();it++)
            row_mx[row_cnt++]=dfs( *it );
        sort(row_mx,row_mx+row_cnt);
        int height=0;
        for(int j=0;j<row_cnt;j++)
            height  = max( height , row_mx[ row_cnt-j-1 ] + j );
        free(row_mx);
        sec[i]=section(height , row_cnt);
    }
    sort(sec,sec+sz);
    int res = 0 , now = 0 ;
    for(int i=0;i<sz;i++){
        res = max( res , now + sec[i].mx_height );
        now += sec[i].length;
    }
    free(sec);
    return res;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        read(i);
    printf("%d\n",dfs(0));
    return 0;
}
