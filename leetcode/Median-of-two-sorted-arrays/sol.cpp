/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for Median-of-two-sorted-arrays
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-10-16 19:52:59
#      History:
=============================================================================*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int findKthNumber(int A[],int m,int B[],int n,int k ){
        // always use smaller A
        if( m > n )
            return findKthNumber(B,n,A,m,k);
        // if A is NULL , return Kth in B
        if( m==0 ) return B[k-1];
        // i K==1 return min(A[0],B[0])
        else if( k==1 ) return A[0]>B[0]?B[0]:A[0];
        // use k/2 part and k-k/2 part ,
        // which side is smaller , the result can't be in the side blow it.
        // if side equal, then K-1th and Kth are the same value of A[Apart] or B[Bpart]
        int Apart=min(k/2,m),Bpart=k-Apart;
        if( A[Apart-1]<B[Bpart-1] ) return findKthNumber( A+Apart,m-Apart,B,n,k-Apart);
        else if( A[Apart-1]>B[Bpart-1] ) return findKthNumber( A,m,B+Bpart,n-Bpart,k-Bpart);
        else return A[Apart];
    }
    double findMedianSortedArrays(int A[],int m, int B[],int n){
        if( (m+n)&1 ) return findKthNumber(A,m,B,n,(m+n)/2);
        else return ( findKthNumber(A,m,B,n,(m+n)/2) + findKthNumber( A,m,B,n,(m+n)/2-1) )*0.5;
    }
};
int main()
{
    int A[]={1,3,4};
    int B[]={2};
    Solution s;
    printf("%lf\n",s.findMedianSortedArrays(A,sizeof A / 4, B, sizeof B / 4));
    return 0;
}
