#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t,n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n&1)puts("1");
        else {
            int top=0,tmpn=n,val=1;
            while( tmpn ){
                if( tmpn&(1<<top) ) tmpn-=(1<<top);
                top++;
            }
            // val is total sg number
            // top is max sg number
            val^=top;
            int ans = (1<<(top-1))-1;
            for(int i=1;i<=top;i++){
                if( ( i-(i^val) ) > 0 ){
                    int x = i ^ val;
                    int from = 1<<(i-1);
                    int to = (  x == i - 1 ) ? (from>>1): ((1<<x)-1);
                    ans = min ( ans ,from - to );
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

