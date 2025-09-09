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

    ListNode* find(ListNode* node,int k){
        ListNode* temp=node;
        for(int i=1; i<k; i++){
            temp=temp->next;
            if(temp==NULL){
                return NULL;
                break;
            }
        }
        return temp;
    }

    void reverse(ListNode* head) {
        ListNode* curr=head;
        
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;

        ListNode* prevLast = NULL;

        while(temp!=NULL){
            ListNode* findkthnode=find(temp,k);
            if(findkthnode!=NULL){
                cout<<findkthnode->val<<" "<<endl;
            }
            
            if(findkthnode==NULL){
                if(prevLast){
                    prevLast -> next = temp; 
                }
                break;
            }
            ListNode* nextnode=findkthnode->next;
            findkthnode->next=NULL;
            reverse(temp);
            if(head==temp){
                head=findkthnode;
            }
            else{
                prevLast->next=findkthnode;
            }
            prevLast = temp; 

            temp = nextnode;
        }
        return head;
    }
};