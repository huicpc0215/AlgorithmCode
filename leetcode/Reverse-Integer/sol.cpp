/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for Reverse Integer
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-18 20:08:50
#      History:
=============================================================================*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Solution{
    public:
    int reverse(int x){
        int ans=0;
        while(x){
            ans=ans*10+x%10;
            x/=10;
        }
        return ans;
    }
};

int main(){
    Solution S;
    cout<<S.reverse(10)<<endl;
    cout<<S.reverse(-321)<<endl;
    cout<<S.reverse(123)<<endl;
    cout<<S.reverse(-123)<<endl;

    return 0;
}
