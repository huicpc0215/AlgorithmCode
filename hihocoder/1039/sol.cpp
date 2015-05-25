#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
    char v;
    node * next;
    node(char x):v(x),next(NULL){};
};
char str[1100];
int len;
int getans(node *head){
    node *now;
    node *pre;
    node *safe;
    int ret = len+3;
    while(true){
        bool f = false;
        safe=head;
        now=head->next;
        while( now->v!='+' ){
            if(now->v == now->next->v){
                f=true;
                char p=now->v;
                while(now->v!='+'){
                    pre = now;
                    now = now->next;
                    delete pre;
                    if( now->v != p) break;
                }
            }
            else {
                safe->next = now;
                safe=safe->next;
                now=now->next;
            }
        }
        safe->next=now;
        if(!f)break;
    }
    while(head!=NULL){
        ret--;
        pre =head;
        head=head->next;
        delete pre;
    }
    return ret;
}
int main(){
    int n,ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ans = 0;
        scanf("%s",str);
        len = strlen(str);
        node *head;
        node *now;
        node *pre;
        for(int j=0;j<len;j++){
            head = new node('-');
            now=head;
            for(int k=0;k<len;k++){
                now->next = new node(str[k]);
                now=now->next;
                if(k==j){
                    now->next = new node('A');
                    now = now->next;
                }
            }
            now->next = new node('+');
            ans = max( ans , getans(head));
        }
        for(int j=0;j<len;j++){
            head = new node('-');
            now=head;
            for(int k=0;k<len;k++){
                now->next = new node(str[k]);
                now=now->next;
                if(k==j){
                    now->next = new node('B');
                    now = now->next;
                }
            }
            now->next = new node('+');
            ans = max( ans , getans(head));
        }
        for(int j=0;j<len;j++){
            head = new node('-');
            now=head;
            for(int k=0;k<len;k++){
                now->next = new node(str[k]);
                now=now->next;
                if(k==j){
                    now->next = new node('C');
                    now = now->next;
                }
            }
            now->next = new node('+');
            ans = max( ans , getans(head));
        }
        printf("%d\n",ans);
    }
    return 0;
}
