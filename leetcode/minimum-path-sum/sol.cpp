#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int dp[110][110];
        int n = grid.size();
        if( n == 0 ) return 0;
        int m = grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(i==0&&j==0)dp[i][j]=grid[0][0];
                else if( i == 0 ) dp[i][j]=dp[i][j-1]+grid[i][j];
                else if( j == 0 ) dp[i][j]=dp[i-1][j]+grid[i][j];
                else dp[i][j]=min( dp[i-1][j],dp[i][j-1] )+grid[i][j];
        return dp[n-1][m-1];
    }
};
int main(){


    return 0;
}
