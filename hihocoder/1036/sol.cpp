#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

#define MAXN 1000010
#define MAXNODE 26
int sz;
int n;
char str[MAXN];
int child[MAXN][MAXNODE];
int np[MAXN];
int word[MAXN];

void ins(char *a){
    int p = 0;
    while( *a ){
        int c = (*a)-'a';
        if(child[p][c]==0){
            memset(child[sz],0,sizeof(child[sz]));
            word[sz]=0;
            child[p][c]=sz++;
        }
        p = child[p][c];
        a++;
    }
    word[p]=1;
}
void init(){
    sz = 1;
    memset(child[0],0,sizeof(child[0]));
}
void ac(){
    queue<int> q;
    for(int i=0;i<MAXNODE;i++){
        if(child[0][i]!=0){
            np[ child[0][i] ]=0;
            q.push( child[0][i] );
        }
    }
    while(!q.empty()){
        int now = q.front();q.pop();
        for(int i=0;i<MAXNODE;i++){
            if(child[now][i]!=0){
                int v = child[now][i];
                np[ v ] = child[np[now]][i];
                q.push(v);
                if( word[ np[v] ])
                    word[v] = 1;
            }
            else child[now][i] = child[ np[now] ][i];
        }
    }
}
bool solve(){
    ac();
    scanf("%s",str);
    int p=0;
    for(int i=0;str[i];i++){
        if(word[p]) return true;
        else{
            int c = str[i]-'a';
            p = child[p][c];
        }
    }
    if( word[p] ) return true;
    return false;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    init();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        ins(str);
    }
    printf("%s\n",solve()?"YES":"NO");
    return 0;
}
