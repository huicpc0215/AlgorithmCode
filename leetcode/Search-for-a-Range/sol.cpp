/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Search for a Range
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-11-11 21:23:22
#      History:
=============================================================================*/
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
class Solution{
    public:
    vector<int> searchRange(int A[],int n,int target){
        vector<int> res;
        int a=lower_bound(&A[0],&A[n],target)-&A[0],b=upper_bound(&A[0],&A[n],target)-&A[0];
        if(a!=b){
            res.push_back(a);
            res.push_back(b-1);
        }
        else {
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};
int main(){
    int A[]={5,7,7,8,8,10};
    vector<int> a;
    Solution s;
    a=s.searchRange(A,6,8);
    int sz=a.size();
    for(int i=0;i<sz;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
