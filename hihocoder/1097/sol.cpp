#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 1010
int mat[MAXN][MAXN];
int match[MAXN];
int n;
int prim(){
    int ans=0;
    for(int i=1;i<n;i++){
        int s=1e5,t=0;
        for(int j=0;j<i;j++)
            for(int k=i;k<n;k++){
                if(mat[match[j]][match[k]] < s){
                    s = mat[ match[j] ][ match[k] ];
                    t = k;
                }
            }
        ans += s;
        swap( match[i] , match[t] );
    }
    return ans;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&mat[i][j]);
            }
            match[i]=i;
        }
        printf("%d\n",prim());
    }
    return 0;
}
