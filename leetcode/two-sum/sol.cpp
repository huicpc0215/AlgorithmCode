/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for two-sum
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2014-10-16 16:21:45
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        vector< pair<int,int> > P;
        int sz=numbers.size();
        for(int i=0;i<sz;i++)
            P.push_back(make_pair(numbers[i],i+1));
        sort(P.begin(),P.end());
        vector<int> ans;
        for(int i=0;i<sz;i++)
        {
            int t=lower_bound(P.begin(),P.end(),make_pair(target-(P[i].first),0)) -P.begin();
            while( t!=sz && P[i].first+P[t].first==target )
            {
                if(P[i].second==P[t].second)
                {
                    t++;
                    continue;
                }
                if(P[i].second<P[t].second){
                    ans.push_back(P[i].second);
                    ans.push_back(P[t].second);
                }
                else {
                    ans.push_back(P[t].second);
                    ans.push_back(P[i].second);
                }
                return ans;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> ans;
    vector<int> data;
    data.push_back(0);
    data.push_back(4);
    data.push_back(3);
    data.push_back(0);
    ans =s.twoSum(data,0);
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
    return 0;
}
