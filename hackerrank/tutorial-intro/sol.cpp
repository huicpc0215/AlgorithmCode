#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int v,n,tmp;
    scanf("%d%d",&v,&n);
    int ans=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if( tmp == v ){
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}

