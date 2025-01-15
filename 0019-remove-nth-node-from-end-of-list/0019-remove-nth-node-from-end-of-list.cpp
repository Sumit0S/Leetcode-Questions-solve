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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;

        ListNode* temp=head;
        while(temp!=NULL){
            cnt+=1;
            temp=temp->next;
        }
        ListNode* node=head;
        ListNode* prev=head;
        if(cnt==n){
            return node->next;
        }
        while(cnt!=n)
        {
            prev=node;
            node=node->next;
            cnt--;
        }
        prev->next=node->next;
        
        return head;
    }
};