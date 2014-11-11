/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode for Search Insert Position
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-11-11 21:41:32
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
class Solution{
    public:
    int searchInsert(int A[],int n,int target){
        return lower_bound(&A[0],&A[n],target)-&A[0];
    }
};
int main(){

    return 0;
}
