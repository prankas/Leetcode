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
    ListNode* reverseList(ListNode* head){
       ListNode* temp=head;
       ListNode* prev=NULL;
       while(temp!=NULL){
        ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
       }
       return prev;
    }
    
    ListNode* findKth(ListNode* head,int k){
        ListNode* temp=head;
        int cnt=1;
        while(cnt<k){
            cnt++;
            temp=temp->next;
            if(temp==NULL) return temp;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        int f=0;
        while(temp!=NULL){
            ListNode* curr=findKth(temp,k);
            if(curr==NULL){
                prev->next=temp;
                break;
            }
            ListNode* next=curr->next;
            curr->next=NULL;
            curr=reverseList(temp);
            if(f)
            prev->next=curr;
            prev=temp;
            if(!f) head=curr;
            temp=next;
            f=1;
        }
        return head;
    }
};