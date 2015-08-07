#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        int box[10];
        bool exist[10];
        for(int i=0;i<10;i++)exist[i]=true;
        box[0]=1;
        for(int i=1;i<10;i++)box[i]=box[i-1]*i;
        for(int i=0;i<n;i++){
            int nowpos=1;
            while(!exist[nowpos]) nowpos++;
            while(k>box[n-i-1]){
                k-=box[n-i-1];
                nowpos++;
                while(!exist[nowpos]) nowpos++;
            }
            char c = nowpos+'0';
            res = res + c;
            exist[nowpos]=false;
        }
        return res;
    }
};
int main(){
    int n,k;
    Solution s;
    cout<<s.getPermutation(3,4)<<endl;
    while(cin>>n>>k)
        cout<<s.getPermutation(n,k)<<endl;
    return 0;
}
