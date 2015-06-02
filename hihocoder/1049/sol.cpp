#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{
    node *l,*r;
    char v;
    node(char x):v(x),l(NULL),r(NULL){};
};
node *root;
char s1[300],s2[300];
int p1[300],p2[300];
int len;
node* dfs(int l,int r,int p){
    node* ret = new node(s2[p]);
    if( l < p ) ret->l = dfs(l,p, p2[ s1[p1[s2[p]]+1] ]);
    if( r > p+1 ) ret->r = dfs(p+1,r,p2[ s1[ p1[s2[p]]+1+p-l ] ] );
    return ret;
}
void dfs(node* r){
    if(r->l!=NULL) dfs(r->l);
    if(r->r!=NULL) dfs(r->r);
    printf("%c",r->v);
}
int main(){
    scanf("%s%s",s1,s2);
    len = strlen(s1);
    for(int i=0;i<len;i++){
        p1[s1[i]]=i;
        p2[s2[i]]=i;
    }
    root = dfs(0,len,p2[s1[0]]);
    dfs(root);
    printf("\n");
    return 0;
}
