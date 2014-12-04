/*=============================================================================
#     FileName: sol.cpp
#         Desc: solution program for leetcode Combination Sum
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-12-04 17:22:23
#      History:
=============================================================================*/
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
    vector<int> tmp;
    vector< vector<int> > ans;
    vector<int> ca;
    vector<int>::iterator it;
    int sz;
    int tgt;
    bool dfs(int tmpsum,int pos){
        if( tmpsum==tgt ) return true;
        if( tmpsum>tgt || pos == sz ) return false;
        int uplimit=(tgt-tmpsum)/ca[pos];
        if(dfs(tmpsum,pos+1))
            ans.push_back( tmp );
        for(int i=1;i<=uplimit;i++){
            tmp.push_back(ca[pos]);
            if(dfs(tmpsum+i*ca[pos],pos+1))
                ans.push_back(tmp);
        }
        for(int i=0;i<uplimit;i++){
            it=tmp.end();
            it--;
            tmp.erase(it);
        }
        return false;
    }
    public:
    vector< vector<int> > combinationSum(vector<int> &candidates, int target){
        ans.clear();
        sort(candidates.begin(),candidates.end());
        ca=candidates;
        sz=candidates.size();
        tgt=target;
        tmp.clear();
        dfs(0,0);
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> ca;
    ca.push_back(2);
    ca.push_back(6);
    ca.push_back(3);
    ca.push_back(7);
    int tar=7;
    vector< vector<int> > res=s.combinationSum(ca,tar);
    for(int i=0;i<res.size();i++){
        vector<int> ans = res[i];
        int sz=ans.size();
        for(int j=0;j<sz;j++){
            printf("%d ",ans[j]);
        }
        puts("");
    }
    return 0;
}
