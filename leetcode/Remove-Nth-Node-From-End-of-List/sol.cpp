/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Remove Nth Node From End of List
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-22 23:20:41
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p=head;
        int sz=0;
        while(p!=NULL){
            sz++;
            p=p->next;
        }
        n=sz-n;
        p=head;
        for(int i=0;i<n-1;i++)
            p=p->next;
        p->next=p->next->next;
        return head;
    }
};
int main(){
    ListNode *a=new ListNode(1);
    ListNode *b=a;
    int cnt=2;
    while(cnt<6){
        b->next=new ListNode(cnt++);
        b=b->next;
    }
    b=a;
    ListNode *ans;
    Solution s;
    ans=s.removeNthFromEnd(a,2);
    while(ans!=NULL){
        printf("%d\n",ans->val);
        ans=ans->next;
    }


    return 0;
}
