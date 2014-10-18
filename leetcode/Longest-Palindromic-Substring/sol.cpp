/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for Longest Palindromic Substring
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-18 19:51:38
#      History:
=============================================================================*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Solution{
    public:
    int p[10000];
    char st[10000];
    string longestPalindrome(string s){
        string ans;
        int sz=s.size();
        for(int i=0;i<2*sz+1;i++)
        {
            if(i&1)st[i]=s[i/2];
            else if(i)st[i]='#';
            else st[i]='$';
            p[i]=1;
        }
        int far,farid;
        for(int i=1;i<2*sz+1;i++)
        {
            if( far > i )
                p[i] = min ( p[2*farid-i],far-i);
            while(st[i-p[i]]==st[i+p[i]])p[i]++;
            if(p[i]+i>far)
            {
                far=p[i]+i;
                farid=i;
            }
        }
        far=0;
        for(int i=1;i<2*sz+1;i++)
        {
            if(far<p[i])
            {
                far=p[i];
                farid=i;
            }
        }
        ans="";
        for(int i=farid-p[farid]+1;i<farid+p[farid];i++)
            if(st[i]!='$'&&st[i]!='#')
                ans=ans+st[i];
        return ans;
    }
};
int main()
{
    Solution S;
    cout<<S.longestPalindrome("abcb")<<endl;
    cout<<S.longestPalindrome("aaaab")<<endl;
    return 0;
}
