#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,less<int> > p;
int n,t;
char op[10];
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",op);
        if(op[0]=='A'){
            scanf("%d",&t);
            p.push(t);
        }
        else {
            printf("%d\n",p.top());
            p.pop();
        }
    }
}
