#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 100010

int b[MAXN];
int x1[MAXN],x2[MAXN],n;
bool f1,f2;

void prt(int t){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(f1&&f2){
            if(x1[i]==t&&x2[i]==t)ans.push_back(i);
        }
        else if( f1 ){
            if(x1[i]==t) ans.push_back(i);
        }
        else {
            if(x2[i]==t) ans.push_back(i);
        }
    }
    int sz = ans.size();
    printf("%d",sz);
    for(int i=0;i<sz;i++)
        printf(" %d",ans[i]);
    printf("\n");
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    int t;
    b[0]=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        f1=true;f2=true;
        int last=1;
        x1[1]=1;x1[0]=0;
        for(int i=1;i<=n;i++){
            x1[i+1]=b[i]-x1[i]-x1[i-1];
            if(x1[i]>1||x1[i]<0){
                f1=false;
                break;
            }
        }
        if(x1[n+1]!=0) f1=false;

        x2[1]=0;x2[0]=0;
        for(int i=1;i<=n;i++){
            x2[i+1]=b[i]-x2[i]-x2[i-1];
            if(x2[i]>1||x2[i]<0){
                f2=false;
                break;
            }
        }
        if(x2[n+1]!=0) f2=false;
        prt(1);
        prt(0);
    }
    return 0;
}
