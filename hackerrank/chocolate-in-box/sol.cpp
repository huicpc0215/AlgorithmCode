#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int bx[1000100];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("1.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        int allxor=0;
        for(int i=0;i<n;i++){
            scanf("%d",&bx[i]);
            allxor^=bx[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if( bx[i]-(allxor^bx[i]) > 0  )
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
