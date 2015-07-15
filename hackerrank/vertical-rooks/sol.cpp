#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bx[2010];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,tmp;
    scanf("%d",&t);
    while(t--){
         scanf("%d",&n);
         int val=0;
         for(int i=0;i<n;i++)scanf("%d",&bx[i]);
         for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            val ^= abs(bx[i]-tmp)-1;
         }
         printf("%s\n",val?"player-2":"player-1");
    }
    return 0;
}

