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
    struct Compare {
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<int, vector<int>, Compare> pq;

        for (ListNode* list : lists) {
            ListNode* curr=list;
            while(curr!=NULL){
                pq.push(curr->val);
                curr=curr->next;
            }
        }

        ListNode* temp=new ListNode(-1);
        ListNode* node=temp;
        while(!pq.empty()){
            int val=pq.top();
            ListNode* curr=new ListNode(val);
            node->next=curr;
            node=curr;
            pq.pop();
        }
        return temp->next;
    }
};