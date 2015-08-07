#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[110][110];
        for(int i=0;i<110;i++)
            for(int j=0;j<110;j++)
                if(i==0||j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};

int main(){
    Solution s;
    cout<<s.uniquePaths(1,2)<<endl;
    return 0;
}
