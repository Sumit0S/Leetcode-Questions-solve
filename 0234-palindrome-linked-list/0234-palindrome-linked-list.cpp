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

    ListNode* reverse(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* frontnode=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return frontnode;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* secondrev=reverse(slow);

        ListNode* first=head;
        ListNode* second=secondrev;

        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }

        return true;
    }
};