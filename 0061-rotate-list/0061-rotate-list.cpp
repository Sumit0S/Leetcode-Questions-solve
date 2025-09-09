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
    ListNode* revse(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* frontnode=revse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return frontnode;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL or k==0){
            return head;
        }
          ListNode* temp= head;
          int total_val=0;

          while(temp!=NULL){
            total_val+=1;
            temp=temp->next;
          }
          temp=head;
          int rem=total_val-(k%total_val);

          if(rem<=0 or k%total_val==0){
            return head;
          }

          while(rem>1){
            temp=temp->next;
            rem--;
          }

          ListNode* rev=temp->next;
          temp->next=NULL;
          
          ListNode* ans=rev;

          while(ans->next!=NULL){
            ans=ans->next;
          }

          ans->next=head;
          
          
          return rev;
    }
};