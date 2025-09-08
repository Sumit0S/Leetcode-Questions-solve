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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
       ListNode* left=headA;
       ListNode* right=headB;
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
       while(left!=right)
       {

            left=left==NULL?headB:left->next;
            right=right==NULL?headA:right->next;

       } 

       return left;    
    }
};