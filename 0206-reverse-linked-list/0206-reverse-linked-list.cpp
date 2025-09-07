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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next1=curr->next;

        while(curr->next!=NULL)
        {
            cout<<curr->val<<" ";
            curr->next=prev;
            prev=curr;
            curr=next1;
            next1=next1->next;
            
        }
        curr->next=prev;
        return curr;
    }
};