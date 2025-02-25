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

    struct Compare{
        bool operator()(ListNode* val1,ListNode* val2){
            cout<<val1->val<<" "<<val2->val<<endl;
            return val1->val > val2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(ListNode* it:lists){
            if (it != nullptr) {
                pq.push(it);
            }
        }

        ListNode* temp=new ListNode();
        ListNode* head=temp;

        while(!pq.empty()){
            ListNode* front=pq.top();
            pq.pop();
            head->next=front;
            if(front->next){
                pq.push(front->next);
            }
            head=head->next;
        }
        return temp->next;
    }
};