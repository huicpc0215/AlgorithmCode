/*=============================================================================
#     FileName: sol.cpp
#         Desc: program for leetcode Merge k Sorted Lists
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-10-28 23:10:27
#      History:
=============================================================================*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
    public:
    struct newNode{
        ListNode *v;
        bool operator<(newNode const &a) const {return v->val>a.v->val;}
        newNode(ListNode* x):v(x){}
    };
    priority_queue<newNode> q;
    ListNode *mergeKLists(vector<ListNode *> &lists){
        ListNode *res=NULL;
        ListNode *head;
        bool first=true;
        int sz=lists.size();
        for(int i=0;i<sz;i++){
            newNode tmpNewNode=newNode(lists[i]);
            if(tmpNewNode.v!=NULL)q.push(tmpNewNode);
        }
        while(!q.empty()){
            newNode tmpNewNode=q.top();q.pop();
            if(first){
                res=tmpNewNode.v;
                head=res;
                first=false;
            }
            else{
                head->next=tmpNewNode.v;
                head=head->next;
            }
            if(tmpNewNode.v->next!=NULL) q.push(newNode(tmpNewNode.v->next));
        }
        return res;
    }
};
int main(){
    ListNode* a=new ListNode(1);
    vector<ListNode*> lists;
    lists.push_back(a);
    ListNode* b=new ListNode(3);
    ListNode *bb=b;
    b->next=new ListNode(6);
    lists.push_back(b);
    ListNode* c=new ListNode(4);
    c->next=new ListNode(5);
    lists.push_back(c);
    Solution s;
    ListNode* ans=s.mergeKLists(lists);
    while(ans!=NULL){
        printf("%d\n",ans->val);
        ans=ans->next;
    }
    return 0;
}
