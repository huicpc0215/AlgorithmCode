/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for ZigZag Conersion
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-18 20:33:56
#      History:
=============================================================================*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution{
    public:
    string convert(string s,int nRows){
        if(nRows==1) return s;
        int sz=s.size();
        string ans="";
        for(int i=0;i<nRows;i++){
            if(i==0||i==nRows-1){
                int j=i;
                while(j<sz){
                    ans=ans+s[j];
                    j+=2*nRows-2;
                }
            }
            else {
                int j=i;
                while(j<sz){
                    ans=ans+s[j];
                    if(j+2*(nRows-i-1)<sz)ans=ans+s[j+2*(nRows-i-1)];
                    j+=2*nRows-2;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution S;
    cout<<S.convert("PAYPALISHIRING", 3)<<endl;
    return 0;
}
