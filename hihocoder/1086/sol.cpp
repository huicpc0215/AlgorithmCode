#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
#define MAXN 1000100
#define MOD 1000007
int n,m,nowsize;
vector< pair<string,int> > vt[MAXN];
map<int,string> mp;
set<int> tms;
int getHash(string s){
    int sz=s.length();
    int ret = 0;
    for(int i=0;i<sz;i++)
        ret = (ret * 17 + s[i])%MOD;
    return ret;
}
bool check(string s,int t){
    int pos = getHash(s);
    int sz = vt[pos].size();
    bool ret = false;
    for(int i=0;i<sz;i++){
        if( s.compare( vt[pos][i].first ) == 0 ){
            mp.erase( mp.find( vt[pos][i].second ) );
            tms.erase( tms.find( vt[pos][i].second ) );
            vt[pos].erase( vt[pos].begin()+i );
            ret = true;
            break;
        }
    }
    if( tms.size() == m ){
        int rm = *tms.begin();
        string rms = mp[rm];
        int rmpos = getHash( rms );
        int rmsz = vt[rmpos].size();
        for(int i=0;i<rmsz;i++){
            if( rms.compare( vt[rmpos][i].first ) == 0 ){
                vt[rmpos].erase( vt[rmpos].begin() + i );
                break;
            }
        }
        mp.erase( mp.find(rm) );
        tms.erase( tms.begin() );
    }
    mp[t]=s;
    vt[pos].push_back(make_pair(s,t));
    tms.insert(t);
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    string str;
    nowsize = 0;
    for(int i=0;i<n;i++){
        cin>>str;
        printf("%s\n",check(str,i)?"Cache":"Internet");
    }
    return 0;
}
