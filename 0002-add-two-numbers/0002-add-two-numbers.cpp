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
class Solution 
{
public:
    ListNode* addTwo(ListNode* l1, ListNode* l2) {
        ListNode* node1=l1;
        ListNode* node2=l2;
        ListNode* node1_pre;
        int prev=0;
        while(node1!=NULL and node2!=NULL){
            if(prev==1){
                node1->val=node1->val+node2->val+1;
            }
            else{
                node1->val=node1->val+node2->val;
            }
            
            if(node1->val>9){
                node1->val=node1->val%10;
                prev=1;
            }
            else{
                prev=0;
            }
            node1_pre=node1;
            node1=node1->next;
            node2=node2->next;
        }

        if(prev==1 and node1==NULL and node2==NULL){
            node1_pre->next=new ListNode(1);
            return l1;
        }

        if(node1){
            ListNode* newnode;
            while(node1!=NULL){
                if(prev==1){
                    node1->val=node1->val+1;
                }
                if(node1->val>9){
                    node1->val=node1->val%10;
                    prev=1;
                }
                else{
                    prev=0;
                }
                newnode=node1;
                node1=node1->next;
            }
            if(prev==1){
                newnode->next=new ListNode(1);
            }
        }
        

        if(node2){
            ListNode* newnode2;
            node1_pre->next=node2;
            node1_pre=node1_pre->next;

            while(node1_pre!=NULL){
                if(prev==1){
                    node1_pre->val=node1_pre->val+1;
                }
                if(node1_pre->val>9){
                    node1_pre->val=node1_pre->val%10;
                    prev=1;
                }
                else{
                    prev=0;
                }
                newnode2=node1_pre;
                node1_pre=node1_pre->next;
            }

            if(prev==1){
                newnode2->next=new ListNode(1);
            }
        }


        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
           return addTwo(l1,l2); 
    }
};