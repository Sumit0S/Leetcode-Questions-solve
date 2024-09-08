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
    // Helper function to check the validity of the BST
    bool check(TreeNode* root,long min , long max) {
        if(root==NULL){
            return true;
        }
        bool left = check(root->left,min,root->val);
        bool right= check(root->right,root->val,max);

        return left and right and min<root->val and root->val<max;
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL and root->right==NULL){
            return true;
        }
        return check(root, LONG_MIN, LONG_MAX);
    }
};
