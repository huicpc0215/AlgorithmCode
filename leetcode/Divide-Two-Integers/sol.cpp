/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Divide Two Integers
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-11-04 14:43:50
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
using  namespace std;
class Solution{
    public:
    int divide(int dividend, int divisor){
        bool f=false;
        if((dividend>0&&divisor>0)||(dividend<0&&divisor<0))f=true;
        int k=0;
        int res=0;
        long long did=dividend;
        long long dis=divisor;
        if(did<0)did=0-did;
        if(dis<0)dis=0-dis;

        while((dis<<k)<=did){
            if( (dis<<(k+1))>did) break;
            else k++;
        }
        while(did>=dis){
            if((dis<<k)<=did){
                res+=1<<k;
                did-=dis<<k;
            }
            k--;
        }
        return f?res:0-res;
    }
};
int main(){
    Solution s;
    cout<<s.divide(2147483647,1)<<endl;
    cout<<s.divide(180,3)<<endl;
    return 0;
}
