/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Longest Common Prefix
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-21 12:10:04
#      History:
=============================================================================*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
class Solution{
    public:
    string longestCommonPrefix(vector<string> &strs){
        string res="";
        int sz=strs.size();
        if(sz==0) return "";
        for(int i=0;i<strs[0].length();i++){
            for(int j=1;j<sz;j++)
                if( strs[j][i]!=strs[0][i] ) return res;
            res=res+strs[0][i];
        }
        return res;
    }
};

int main(){


    return 0;
}

