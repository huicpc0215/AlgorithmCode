/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for Add Two Numbers
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-17 14:33:41
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

struct ListNode {

    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

};
class Solution {

public:

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans;
        ListNode *tail;
        bool first=true;
        bool up=0;
        while(l1!=NULL || l2!=NULL ){
            int now=up; up=0;
            if(l1!=NULL) now+=l1->val;
            if(l2!=NULL) now+=l2->val;
            if(now>=10) {
                now-=10;
                up=1;
            }
            if(first){
                first=false;
                ans=new ListNode(now);
                tail=ans;
            }
            else {
                tail->next = new ListNode(now);
                tail=tail->next;
            }
            if(l1!=NULL)l1=l1->next;
            if(l2!=NULL)l2=l2->next;
        }
        if(up!=0){
            tail->next=new ListNode(1);
            tail=tail->next;
        }
        return ans;
    }
};
int main()
{
    ListNode *a,*b;
    a=new ListNode(1);
    b=new ListNode(9);
    ListNode *c;
    Solution s;
    c=s.addTwoNumbers(a,b);
    while(c!=NULL){
        printf("%d \n",c->val);
        c=c->next;
    }
    return 0;
}
