#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> res;
            int len=digits.size();
            int now=1;
            for(int i=len-1;i>=0;i--){
                if( digits[i]+now>9 ){
                    now=1;
                    res.push_back(0);
                }
                else {
                    res.push_back(digits[i]+now);
                    now=0;
                }
            }
            if(now)res.push_back(1);
            reverse(res.begin(),res.end());
            return res;
        }
};
int main(){
    vector<int> a;
    vector<int> res;
    Solution x;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    res=x.plusOne(a);
    for(int i=0;i<res.size();i++){
        printf("%d",res[i]);
    }
    printf("\n");
    cout<<"ok"<<endl;
    a.clear();
    for(int i=0;i<4;i++)
        a.push_back(9);
    res=x.plusOne(a);
    for(int i=0;i<res.size();i++){
         printf("%d",res[i]);
    }
    printf("\n");
    return 0;
}
