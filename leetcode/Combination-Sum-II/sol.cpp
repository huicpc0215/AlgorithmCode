/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for leetcode Combination Sum II
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-12-04 19:53:32
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
    bool check_same(vector<int> &a,vector<int> &b){
        if(a.size()!=b.size())return false;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i])return false;
        return true;
    }
    bool check_exist(vector<int> &x){
        int sz=ans.size();
        for(int i=0;i<sz;i++){
            if( check_same(x,ans[i]))
                return true;
        }
        return false;
    }
    bool dfs(int tmpsum,int pos){
        if( tmpsum==tgt ) return true;
        if( tmpsum>tgt || pos == sz ) return false;
        int uplimit=(tgt-tmpsum)/ca[pos];
        if(dfs(tmpsum,pos+1))
            ans.push_back( tmp );
        tmp.push_back(ca[pos]);
        if(dfs(tmpsum+ca[pos],pos+1))
            if(!check_exist(tmp))
                ans.push_back(tmp);
        it=tmp.end();
        it--;
        tmp.erase(it);
        return false;
    }
    public:
    vector< vector<int> > combinationSum2(vector<int> &candidates, int target){
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
    ca.push_back(1);
    ca.push_back(1);
    ca.push_back(2);
    ca.push_back(5);
    ca.push_back(6);
    ca.push_back(10);
    ca.push_back(7);
    int tar=8;
    vector< vector<int> > res=s.combinationSum2(ca,tar);
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
