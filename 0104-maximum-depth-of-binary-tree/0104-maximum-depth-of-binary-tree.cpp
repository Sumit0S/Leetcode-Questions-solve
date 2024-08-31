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

    int maxleft(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int left=maxleft(root->left);
        int right=maxleft(root->right);
        return max(left,right)+1;
    }

    int maxright(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int left=maxleft(root->left);
        int right=maxleft(root->right);
        return max(left,right)+1;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int max_left=maxleft(root->left);
        int max_right=maxright(root->right);
        return max(max_left,max_right);
    }
};