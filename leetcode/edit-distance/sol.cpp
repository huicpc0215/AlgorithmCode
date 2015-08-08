#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Solution {
public:
    int dp[510][510];
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(i==0&&j==0) dp[i][j]=0;
                else if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(word1[i-1]!=word2[j-1]));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                printf("%d%c",dp[i][j],j!=m?' ':'\n');
        return dp[n][m];
    }
};
int main(){
    Solution s;
    string a("abc");
    string b("acc");
    cout<<s.minDistance(a,b)<<endl;
    return 0;
}

