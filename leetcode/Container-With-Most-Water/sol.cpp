#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

class Solution{
public:
    int maxArea(vector<int> &height){
        int sz=height.size();
        int l=0,r=sz-1;
        int res=0;
        while(l<r){
            res=max(res,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])l++;
            else if(height[r]<height[l])r--;
            else {
                l++;
                r--;
            }
        }
        return res;
    }
};
vector<int> h;
int main(){
    Solution S;
    freopen("std.in","r",stdin);
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        h.push_back(t);
    }
    printf("%d\n",S.maxArea(h));
    return 0;
}

