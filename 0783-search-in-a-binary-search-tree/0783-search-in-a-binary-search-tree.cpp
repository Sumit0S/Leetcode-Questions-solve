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

    TreeNode* find(TreeNode* root, int val){
         while(root != NULL && root->val != val)
         {
            // Check if the target value is
            // less than the current node's value.
            // If so, move to the left subtree
            // (values smaller than the current node).
            // Otherwise, move to the right subtree
            // (values larger than the current node).
            root = val < root->val ? root->left : root->right;
        }
        // Return the node containing the target value,
        // if found; otherwise, return NULL.
        return root;

    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* r=find(root,val);
        return r;
    }
};