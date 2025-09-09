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

    bool hasKNodes(ListNode* head, int k) {
        int cnt = 0;
        while (head != nullptr && cnt < k) {
            head = head->next;
            cnt++;
        }
        return cnt == k;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL){
            return NULL;
        }

        if (!hasKNodes(head, k)) {
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        int count=0;
        while(curr!=NULL and count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }

        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }

        return prev;

    }
};