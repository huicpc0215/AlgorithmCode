/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Remove Duplicates from Sorted Array
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-29 20:46:51
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
    public:
    int removeDuplicates(int A[],int n){
        int sz=1;
        for(int i=1;i<n;i++)
            if(A[i]!=A[i-1])A[sz++]=A[i];
        return n?sz:n;
    }
};
int main(){

    return 0;
}
