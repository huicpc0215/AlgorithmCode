/*=============================================================================
#     FileName: sol.cpp
#         Desc: leetcode Merge Two Sorted Lists
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-05-24 22:14:32
#      History:
=============================================================================*/
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* ans = NULL;
        ListNode* now;
        while( l1 != NULL || l2 != NULL ){
            if( ans == NULL ){
                if(l1!=NULL&&l2!=NULL){
                    if( l1->val < l2->val ){
                        ans = new ListNode(l1->val);
                        l1=l1->next;
                    }
                    else {
                        ans = new ListNode(l2->val);
                        l2=l2->next;
                    }
                }
                else if( l1 == NULL ){
                    ans = new ListNode(l2->val);
                    l2=l2->next;
                }
                else if( l2 == NULL ){
                    ans = new ListNode(l1->val);
                    l1=l1->next;
                }
                now = ans;
            }
            else {
                if(l1!=NULL&&l2!=NULL){
                    if( l1->val < l2->val ){
                        now->next = new ListNode(l1->val);
                        l1=l1->next;
                    }
                    else {
                        now->next = new ListNode(l2->val);
                        l2=l2->next;
                    }
                }
                else if( l1 == NULL ){
                    now->next = new ListNode(l2->val);
                    l2=l2->next;
                }
                else if( l2 == NULL ){
                    now->next = new ListNode(l1->val);
                    l1=l1->next;
                }
                now = now->next;
            }
        }
        return ans;
    }
};
