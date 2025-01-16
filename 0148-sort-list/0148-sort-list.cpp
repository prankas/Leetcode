/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* ret=new ListNode(0);
        ListNode* p=ret;
        while(a!=NULL && b!=NULL){
            if(a->val>b->val){
                ListNode* t=new ListNode(b->val);
                p->next=t;
                p=t;
                b=b->next;
            } else{
                ListNode* t=new ListNode(a->val);
                p->next=t;
                p=t;
                a=a->next;
            }
        }
        if(a==NULL && b==NULL) return ret->next;
        else if(a==NULL) p->next=b;
        else p->next=a;
        return ret->next;
    }

    ListNode* divide(ListNode* head){
      if(head==NULL || head->next==NULL) return head;
      ListNode* slow=head;
      ListNode* fast=head->next;
      while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
      }
      fast=slow->next;
      slow->next=NULL;
      ListNode* a=divide(head);
      //if(fast==NULL) return a;
      ListNode* b=divide(fast);
      return merge(a,b);
      return a;
    }

    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};