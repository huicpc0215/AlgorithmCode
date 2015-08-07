#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int dp[110][110];
        int n = obstacleGrid.size();
        int m;
        if( n==0 ) return 0;
        m = obstacleGrid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if( i==0 && j==0 ) dp[i][j]=1;
                else if( i==0 ) dp[i][j]=dp[i][j-1];
                else if( j==0 ) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};
int main(){
    vector<int> s;
    s.push_back( 0 );
    s.push_back( 0 );
    s.push_back( 0 );
    vector< vector<int> > k ;
    k.push_back(s);
    s[1]=1;
    k.push_back(s);
    s[1]=0;
    k.push_back(s);
    Solution o;
    cout<<o.uniquePathsWithObstacles(k)<<endl;


    return 0;
}
