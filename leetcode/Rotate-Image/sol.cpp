/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for leetcode Rotate-Image
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-01-01 13:04:36
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
class Solution{
public:
    void rotate(vector<vector<int> > &matrix){
        int n = matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=tmp;
            }
        }
    }
};
int main(){
    vector<int> tmp;
    vector<vector<int> >m;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);
    m.push_back(tmp);
    tmp.clear();
    tmp.push_back(4);
    tmp.push_back(5);
    tmp.push_back(6);
    m.push_back(tmp);
    tmp.clear();
    tmp.push_back(7);
    tmp.push_back(8);
    tmp.push_back(9);
    m.push_back(tmp);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            printf("%d%c",m[i][j],j==2?'\n':' ');
    Solution s;
    s.rotate(m);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            printf("%d%c",m[i][j],j==2?'\n':' ');

    return 0;
}
