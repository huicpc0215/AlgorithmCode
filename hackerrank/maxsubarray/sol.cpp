#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,tmp;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int mx1=0,mx2=0,nowsum=0,mxdgt=-100000;
        int mnsum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            nowsum+=tmp;
            mx1 = max( mx1 , nowsum - mnsum );
            mnsum = min ( mnsum , nowsum );
            if( tmp > 0  )mx2+=tmp;
            mxdgt = max( mxdgt , tmp );
        }
        if(mxdgt>=0)printf("%d %d\n",mx1,mx2);
        else printf("%d %d\n",mxdgt,mxdgt);
    }
    return 0;
}

