/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for Pow(x,n)
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-01-01 15:30:41
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
public:
    double pow(double x,int n){
        if(abs(x)<1e-9) return 0;
        long long newn=n;
        if(newn<0) {
            x=1/x;
            newn=-newn;
        }
        double res=1.0,tmp=x;
        while(newn){
            if(newn&1ll)res=res*tmp;
            tmp=tmp*tmp;
            newn>>=1ll;
        }
        return res;
    }
};

int main(){
    Solution s;
    printf("%lf\n",s.pow(2,3));
    printf("%lf\n",s.pow(2,0));
    printf("%lf\n",s.pow(2,1));

    return 0;
}
