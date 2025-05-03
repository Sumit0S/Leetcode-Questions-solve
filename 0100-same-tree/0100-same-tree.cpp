/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool check(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL){
            if(p==NULL and q==NULL){
                return true;
            }
            return false;
        }
        bool left=check(p->left,q->left);
        bool right=check(p->right,q->right);
        bool curr=p->val==q->val;

        return left and right and curr;
    }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        return check(p,q);
    }
};