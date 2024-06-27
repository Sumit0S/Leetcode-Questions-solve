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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if (head1 == NULL || head2 == NULL) {
            return NULL;
        }
        while (temp1 != temp2) {
            temp1 = (temp1 == NULL) ? headB : temp1->next;
            temp2 = (temp2 == NULL) ? headA : temp2->next;
        }
        return temp1;
    }
};

