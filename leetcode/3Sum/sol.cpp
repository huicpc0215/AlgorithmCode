/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode 3sum
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-22 21:59:44
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution{
    public:
    vector< vector<int> > ksum(vector<int> &num,int start,int k,int target){
        int sz=num.size();
        vector< vector<int> > res,next;
        vector<int> tmp;
        if( k==2 ){
            int l=start,r=sz-1;
            while(l<r){
                if(num[l]+num[r]<target) l++;
                else if( num[l]+num[r]>target ) r--;
                else {
                    tmp.clear();
                    tmp.push_back(num[l]);
                    tmp.push_back(num[r]);
                    int pre=num[l];
                    while(l<r && num[l]==pre) l++;
                    pre=num[r];
                    while(l<r && num[r]==pre) r--;
                    res.push_back(tmp);
                }
            }
        }
        else {
            for(int i=start;i<sz-2;i++){
                if(i==start || num[i]!=num[i-1]){
                    next=ksum(num,i+1,k-1,target-num[i]);
                    for(int j=0;j<next.size();j++){
                        tmp.clear();tmp.push_back(num[i]);
                        tmp.insert(tmp.end(),next[j].begin(),next[j].end());
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
    vector< vector<int> > threeSum(vector<int> &num){
        sort(num.begin(),num.end());
        return ksum(num,0,3,0);
    }
};
//i-1 0 1 2 -1 -4
int main(){
    Solution S;
    vector<int> n;
    vector< vector<int> > ans;
    n.push_back(-1);
    n.push_back(0);
    n.push_back(1);
    n.push_back(2);
    n.push_back(-1);
    n.push_back(-4);
    ans=S.threeSum(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<3;j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}
