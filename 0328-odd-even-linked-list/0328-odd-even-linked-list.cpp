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

    ListNode* connect(ListNode* head){
        ListNode* node=head;
        while(node and node->next){
            ListNode* front=node->next;
            node->next=front->next;
            node=node->next;
        }
        return head;
    }
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
         ListNode* first=head;
         ListNode* second=head->next;
         ListNode* con=head->next;

         while(second!=NULL and second->next!=NULL){
            ListNode* front=second;
            first->next=second->next;
            first=first->next;
            second->next=first->next;
            second=second->next;
         }

         first->next=con;
         return head;
    }
};