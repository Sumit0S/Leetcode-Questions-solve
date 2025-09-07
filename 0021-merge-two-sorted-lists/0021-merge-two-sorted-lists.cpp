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


    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* left=list1;
        ListNode* right=list2;
        ListNode dummy;  // create dummy node
        ListNode* temp = &dummy;  // temp points to dummy
        // dummy.next = nullptr;
        while(left!=NULL and right!=NULL){
            if(left->val<=right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp = temp->next;
        }
        if(left!=NULL){
            temp->next=left;
           
        }
        if(right!=NULL){
            temp->next=right;
        }

        return dummy.next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        return merge(list1,list2);    
    }
};