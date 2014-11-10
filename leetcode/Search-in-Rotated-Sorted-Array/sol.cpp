#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
    public:
    int search(int A[],int n,int target){
        int r=0;
        for(int i=1;i<n;i++){
            if(A[i]<A[i-1]){
                r=i;
                break;
            }
        }
        int res=-1;
        if( r ){
            if(A[0]<=target){
                int k=lower_bound(&A[0],&A[r],target)-&A[0];
                if(k<r && A[k]==target) res=k;
            }
            else {
                int k=lower_bound(&A[r],&A[n],target)-&A[0];
                if(k<n && A[k]==target) res=k;
            }
        }
        else {
            int k=lower_bound(&A[0],&A[n],target)-&A[0];
            if(k<n && A[k]==target) res=k;
        }
        return res;
    }
};

int main(){
    Solution s;
    int A[]={4,5,6,7,0,1,2};
    cout<<"ans="<<s.search(A,6,5)<<endl;
    cout<<"ans="<<s.search(A,6,7)<<endl;
    cout<<"ans="<<s.search(A,6,3)<<endl;


    return 0;
}
