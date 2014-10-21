#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define MOD (1000000007)
#define ZERO (make_pair(0,0))
#define ONE (make_pair(0,1))
typedef pair<long long, long long> PAIR;
PAIR dp[20][2][210];
long long t10[20];
long long dgt[20],sz;
long long num,l,r;
int k;
PAIR getnumber(int pos,int target,bool lim,int firstpos){
    if(dp[pos][lim][target+100].first!=-1)return dp[pos][lim][target+100];
    if(pos==sz) return dp[pos][lim][target+100]=((target==0)?ONE:ZERO);
    PAIR res = ZERO , tmp;
    long long f=(firstpos==-1?pos:firstpos);
    f=(pos-f)&1ll?1:-1;
    if( lim ){
        for(int i=0;i<=dgt[pos];i++){
            if(i==0&&firstpos==-1) tmp = getnumber(pos+1,target,false||(lim&&(i==dgt[pos])),-1);
            else tmp= getnumber(pos+1,target-f*i,false||lim&&(i==dgt[pos]),firstpos==-1?pos:firstpos);
            res.first=(res.first+i*( t10[sz-1-pos] * tmp.second ) % MOD + tmp.first )%MOD;
            res.second=res.second + tmp.second;
        }
    }
    else {
        for(int i=0;i<10;i++){
            if(i==0&&firstpos==-1) tmp = getnumber(pos+1,target,false,-1);
            else tmp = getnumber(pos+1,target-f*i,false,firstpos==-1?pos:firstpos);
            res.first=(res.first+i*( t10[sz-1-pos] * tmp.second ) % MOD + tmp.first )%MOD;
            res.second=res.second + tmp.second;
        }
    }
    return dp[pos][lim][target+100]=res;
}
long long gao(long long x){
    if(x<0)return 0;
    sz=0;
    while(x){
        dgt[sz++]=x%10;
        x/=10;
    }
    for(int i=0;2*i<sz;i++)swap(dgt[i],dgt[sz-1-i]);
    for(int i=0;i<sz;i++)
        printf("i=%d dgt[i]=%lld\n",i,dgt[i]);
    for(int i=0;i<20;i++)
        for(int p=0;p<2;p++)
            for(int j=0;j<210;j++)
                dp[i][p][j]=make_pair(-1,-1);
    return getnumber(0,k,true,-1).first;
}
int main(){
    t10[0]=1;
    for(int i=1;i<19;i++)t10[i]=10*t10[i-1];
    freopen("std.in","r",stdin);
    while(scanf("%lld%lld%d",&l,&r,&k)!=EOF)
        printf("%lld\n",gao(r)-gao(l-1));
    return 0;
}
