/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for hihocoder 1033(dp programing)
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-21 13:13:17
#      History:
=============================================================================*/
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
PAIR dp[20][2][210][20];
// pos,lim,target+100,firstpos
long long t10[20];
long long dgt[20],sz;
long long num,l,r;
int k;
PAIR getnumber(int pos,int target,bool lim,int firstpos){
    //printf("%d %d %d %d \n",pos,target,lim,firstpos);
    if(dp[pos][lim][target+100][firstpos].first!=-1)return dp[pos][lim][target+100][firstpos];
    if(pos==sz) return dp[pos][lim][target+100][firstpos]=((target==0)?ONE:ZERO);
    PAIR res = ZERO,tmp;
    long long f=(firstpos==19?pos:firstpos);
    f=(pos-f)&1ll?-1ll:1ll;
    if( lim ){
        //puts("here");
        for(int i=0;i<=dgt[pos];i++){
            if(i==0&&firstpos==19) tmp = getnumber(pos+1,target,i==dgt[pos],19);
            else tmp= getnumber(pos+1,target-f*i,i==dgt[pos],firstpos==19?pos:firstpos);
            res.first=(res.first+i*( t10[sz-1-pos]%MOD * tmp.second ) % MOD + tmp.first )%MOD;
            res.second=(res.second + tmp.second)%MOD;
            //printf("%d %d %d %d res-> %lld %lld\n",pos,target,lim,firstpos,res.first,res.second);
        }
    }
    else {
        for(int i=0;i<10;i++){
            if(i==0&&firstpos==19) tmp = getnumber(pos+1,target,false,19);
            else tmp = getnumber(pos+1,target-f*i,false,firstpos==19?pos:firstpos);
            res.first=(res.first+i*( t10[sz-1-pos]%MOD * tmp.second ) % MOD + tmp.first )%MOD;
            res.second=(res.second + tmp.second)%MOD;
        }
    }
    return dp[pos][lim][target+100][firstpos]=res;
}
long long gao(long long x){
    if(x<0)return 0;
    sz=0;
    while(x>0){
        dgt[sz++]=x%10;
        x/=10;
    }
    for(int i=0;2*i<sz;i++)swap(dgt[i],dgt[sz-1-i]);
    for(int i=0;i<20;i++)
        for(int p=0;p<2;p++)
            for(int j=0;j<210;j++)
                for(int q=0;q<20;q++)
                    dp[i][p][j][q]=make_pair(-1,-1);
    return getnumber(0,k,true,19).first;
}
int main(){
    t10[0]=1;
    for(int i=1;i<19;i++)t10[i]=10*t10[i-1];
    //freopen("std.in","r",stdin);
    while(scanf("%lld%lld%d",&l,&r,&k)!=EOF){
        long long ans=gao(r)-gao(l-1);
        while(ans<0) ans=ans+MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
