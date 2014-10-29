/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Remove Element
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-29 20:54:47
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
class Solution{
    public:
    int removeElement(int A[],int n, int elem){
        int sz=0;
        for(int i=0;i<n;i++)
            if(A[i]!=elem)A[sz++]=A[i];
        return sz;
    }
};
int main(){

    return 0;
}
