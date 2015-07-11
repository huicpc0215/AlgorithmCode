#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int val=0;
        long long tmp;
        for(int i=0;i<n;i++){
            scanf("%lld",&tmp);
            val^=(int)((tmp%9)/2);
        }
        printf("%s\n",val?"Manasa":"Sandy");
    }
    return 0;
}

