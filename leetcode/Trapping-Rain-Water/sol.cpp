/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for Leetcode Trapping Rain Water
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-19 21:32:39
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

class Solution{
    public:
    int l[100000],r[100000];
    int trap(int A[],int n ){
        int lx=0,rx=0;
        for(int i=0;i<n;i++){
            l[i]=lx;r[n-1-i]=rx;
            lx=max(lx,A[i]);
            rx=max(rx,A[n-1-i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
            res += max( 0 , min(l[i],r[i])-A[i]);
        return res;
    }
};
int main(){

    Solution S;
    int B[]={0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n",S.trap(B,12));
    return 0;
}
