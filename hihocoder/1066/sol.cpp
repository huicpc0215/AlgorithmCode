#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int group[200010];
int n,p,pa,pb,sz=1;
map<string,int> mp;
string sa,sb;
int find_group(int x){
    if( x == group[x] ) return x;
    return group[x]=find_group(group[x]);
}

void union_group(int x,int y){
    x = find_group(x);
    y = find_group(y);
    group[y]=group[x];
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    for(int i=0;i<200010;i++)group[i]=i;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p);
        cin>>sa>>sb;
        if(mp[sa]==0) mp[sa]=sz++; pa = mp[sa];
        if(mp[sb]==0) mp[sb]=sz++; pb = mp[sb];
        if(p){
            pa=find_group(pa);
            pb=find_group(pb);
            printf("%s\n",pa==pb?"yes":"no");
        }
        else union_group(pa,pb);
    }
    return 0;
}
