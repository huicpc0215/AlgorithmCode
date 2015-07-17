#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int mn = 100000000;
    int n,tmp;
    scanf("%d",&n);
    vector<int> e;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        e.push_back(tmp);
    }
    sort(e.begin(),e.end());
    for(int i=1;i<n;i++)
        mn = min ( mn , e[i] - e[i-1] );
    bool prt = false;
    for(int i=1;i<n;i++){
        if( e[i]-e[i-1] == mn ){
            if( prt )printf(" ");
            printf("%d %d",e[i-1],e[i]);
            prt = true;
        }
    }


    return 0;
}

