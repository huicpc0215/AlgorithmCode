/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for Longest Substring Without Repeating Characters
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-16 20:19:29
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
    public:
    int pos[300];
    int lengthOfLongestSubstring(string s){
        for(int i=0;i<300;i++)
            pos[i]=-1;
        int sz=s.length();
        int ans=0,last=-1;
        for(int i=0;i<sz;i++)
        {
            ans=max( ans , i - max( pos[s[i]], last-1 )  );
            last = max( last , pos[ s[i] ]+1 );
            pos[ s[i] ] = i;
        }
        return ans;
    }
};
int main()
{
    Solution st;
    string s="wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    //string s="abcabcbb";
    //string s="bbbbbb";
    printf("%d\n",st.lengthOfLongestSubstring(s));
    return 0;

}
