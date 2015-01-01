/*=============================================================================
#     FileName: sol.cpp
#         Desc: program detail for leetcode Jump-Game
#       Author: huicpc0215
#        Email: huicpc0215@gmail.com
#     HomePage: http://huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-01-01 12:24:50
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
class Solution{
public:
    bool visit[100000];
    queue<int> q;
    int minpos;
    bool canJump(int A[],int n){
	    minpos=0;
	    for(int i=0;i<n;i++)
            visit[i]=false;
        visit[0]=true;
        q.push(0);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            int maxpos=min(n-1,t+A[t]);
            for(int i=max(minpos+1,t+1);i<=maxpos;i++){
                if(i<n&&!visit[i]){
                    q.push(i);
                    visit[i]=true;
                }
            }
	        minpos=max(minpos,t+A[t]);
        }
        return visit[n-1];
    }
};
int main(){
    int A[]={2,3,1,1,4};
    Solution s;
    printf("first = %d\n",s.canJump(A,5));
    int B[]={3,2,1,0,4};
    printf("second = %d\n",s.canJump(B,5));
    return 0;
}
