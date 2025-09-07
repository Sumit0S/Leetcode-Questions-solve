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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head->next==NULL){
            return NULL;
        }
        int total_el=0;
        ListNode* temp=head;
        while(temp!=NULL){
            total_el+=1;
            temp=temp->next;
        }
        int nod=total_el-n;
        int cnt=0;
        temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL and cnt!=nod){
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        if(temp==NULL){
            return NULL;
        }
        if(prev==NULL){
            return temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        return head;    
    }
};