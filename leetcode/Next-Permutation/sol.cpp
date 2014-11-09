#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
class Solution{
    public:
    void nextPermutation(vector<int> &num){
        int r=num.size()-1;
        while(r&&num[r]<=num[r-1])r--;
        if(r)swap(num[r],num[r-1]);
        sort(num.begin()+r,num.end());
    }
};
int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    int sz=3;
    Solution s;
    s.nextPermutation(num);
    for(int i=0;i<sz;i++){
        printf("%d ",num[i]);
    }
    puts("");
    num.clear();
    num.push_back(3);
    num.push_back(2);
    num.push_back(1);
    s.nextPermutation(num);
    for(int i=0;i<sz;i++){
        printf("%d ",num[i]);
    }
    puts("");
    num.clear();
    num.push_back(1);
    num.push_back(1);
    num.push_back(5);
    s.nextPermutation(num);
    for(int i=0;i<sz;i++){
        printf("%d ",num[i]);
    }
    return 0;
}
