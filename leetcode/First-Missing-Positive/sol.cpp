/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for leetcode First Missing Positive
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-12-04 21:12:32
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
class Solution{
    public:
    int firstMissingPositive(int A[],int n){
        for(int i=0;i<n;){
            if( (A[i]>0 && A[i]<=n)&&(A[i]!=i+1)&&(A[i]!=A[A[i]-1])){
                swap(A[i],A[ A[i]-1 ]);
            }
            else i++;
        }
        for(int i=0;i<n;i++){
            if(A[i]!=i+1)return i+1;
        }
        return n+1;
    }
};
int main(){
    Solution s;
    int A[]={1,1};
    printf("res=%d\n",s.firstMissingPositive(A,2));
    int B[]={3,4,1,-1};
    printf("res=%d\n",s.firstMissingPositive(B,4));
    return 0;
}
