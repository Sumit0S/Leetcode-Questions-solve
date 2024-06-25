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
   bool isPalindrome(ListNode* head) {
        // Edge cases: empty list or a single node list
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // Find the middle of the linked list using a slow and a fast pointer
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> s;

        // Push the first half elements into stack
        while (fast != NULL && fast->next != NULL) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the list has an odd number of elements, skip the middle element
        if (fast != NULL) {
            slow = slow->next;
        }

        // Compare the second half of the list with the elements in the stack
        while (slow != NULL) {
            int top = s.top();
            s.pop();
            if (top != slow->val) {
                return false;
            }
            slow = slow->next;
        }

        return true;
    }
};