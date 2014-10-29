/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Reverse Nodes in k-Group
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-29 20:38:25
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution{
    public:
    stack<ListNode*> stk;
    ListNode * reverseKGroup(ListNode* head,int k){
        ListNode *res=head;
        ListNode *tmp;
        bool first=true;
        if(head==NULL||k==1) return res;
        while(head!=NULL){
            stk.push(head);
            if(stk.size()==k){
                head=stk.top()->next;
                if(first){
                    res=stk.top(); stk.pop();
                    tmp=res;
                    first=false;
                }
                while( !stk.empty() ){
                    tmp->next = stk.top();
                    stk.pop();
                    tmp=tmp->next;
                }
                tmp->next=head;
                if(head!=NULL)stk.push(head);
            }
            if(head!=NULL)head=head->next;
        }
        return res;
    }
};
int main(){
    ListNode *a=new ListNode(1);
    ListNode *last=a;
    a->next=new ListNode(2);
    a=a->next;
    Solution s;
    ListNode *ans=s.reverseKGroup(last,2);
    int cnt=0;
    while(ans!=NULL){
        printf("%d\n",ans->val);
        ans=ans->next;
    }
    return 0;
}
