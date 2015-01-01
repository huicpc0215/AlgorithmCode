/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for leetcode Permutations
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-01-01 12:32:31
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<vector<int> > permute(vector<int> &num){
        int sz=num.size();
        vector<vector<int> >res;
        sort(num.begin(),num.end());
        do{
            res.push_back(num);
        }while(next_permutation(num.begin(),num.end()));
        return res;
    }
};
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    return 0;
}
