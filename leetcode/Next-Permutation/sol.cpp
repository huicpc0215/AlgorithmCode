/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Next Permutation
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2015-01-01 12:22:16
#      History:
=============================================================================*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution{
    public:
    void nextPermutation(vector<int> &num){
        int r=num.size()-1;
        while(r&&num[r]<=num[r-1])r--;
        reverse(num.begin()+r,num.end());
        if(r){
            int l=upper_bound(num.begin()+r,num.end(),num[r-1])-num.begin();
            swap(num[l],num[r-1]);
        }
    }
};
int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    int sz=3;
    Solution s;
    s.nextPermutation(num);
    for(int i=0;i<sz;i++){
        printf("%d ",num[i]);
    }
    puts("");
    num.clear();
    num.push_back(3);
    num.push_back(2);
    num.push_back(1);
    s.nextPermutation(num);
    for(int i=0;i<sz;i++){
        printf("%d ",num[i]);
    }
    puts("");
    num.clear();
    num.push_back(1);
    num.push_back(5);
    num.push_back(1);
    s.nextPermutation(num);
    for(int i=0;i<sz;i++){
        printf("%d ",num[i]);
    }
    return 0;
}
