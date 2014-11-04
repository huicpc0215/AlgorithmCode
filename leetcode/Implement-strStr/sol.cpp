/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Implement strStr()
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-11-04 13:58:50
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution{
    public:
    static const int maxlength=100000;
    int next[maxlength];
    int strStr(char *haystack,char *needle){
        if(strlen(needle)>strlen(haystack))return -1;
        if(strlen(needle)==0) return 0;
        next[0]=-1;
        int j=-1;
        int len=strlen(needle);
        for(int i=1;i<len;i++){
            while((j+1)&&needle[j+1]!=needle[i])j=next[j];
            if(needle[j+1]==needle[i])next[i]=j+1;
            else next[i]=j;
            j=next[i];
        }
        j=-1;
        len=strlen(haystack);
        int targetlen=strlen(needle);
        for(int i=0;i<len;i++){
            while((j+1)&&haystack[i]!=needle[j+1])j=next[j];
            if(haystack[i]==needle[j+1])j++;
            if(j==targetlen-1)return i-targetlen+1;
        }
        return -1;
    }
};

int main(){
    Solution S;
    char a[]="a";
    char b[]="a";
    cout<<S.strStr(a,b)<<endl;

    return 0;
}
