/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Swap Nodes in Pairs
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-28 23:44:39
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution{
    public:
    ListNode *swapPairs(ListNode* head){
        ListNode *res=head;
        ListNode *nxt;
        ListNode *nxt2;
        if(head==NULL) return NULL;
        if(head->next!=NULL){
            nxt=head->next;
            nxt2=nxt->next;
            res=nxt;
            res->next=head;
            head->next=nxt2;
        }
        while(head->next!=NULL && head->next->next!=NULL){
            nxt=head->next;
            nxt2=nxt->next;
            head->next=nxt2;
            nxt->next=nxt2->next;
            nxt2->next=nxt;
            head=nxt;
        }
        return res;
    }
};

int main(){
    ListNode *list;
    list=new ListNode(1);
    ListNode *a=list;
    list->next=new ListNode(2);
    list=list->next;
    list->next=new ListNode(3);
    list=list->next;
    list->next=new ListNode(4);
    Solution s;
    int cnt=0;
    ListNode * ans=s.swapPairs(a);
    while(ans!=NULL){
        printf("ans=%d cnt=%d\n",ans->val,cnt++);
        ans=ans->next;
    }


    return 0;
}
