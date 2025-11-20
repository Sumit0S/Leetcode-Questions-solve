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

    int findansfromleft(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int left=findansfromleft(node->left);
        int right=findansfromleft(node->right);

        return 1+max(left,right);
    }
    int findansfromright(TreeNode* node)
    {
        if(node==NULL){
            return 0;
        }
        int left=findansfromleft(node->left);
        int right=findansfromleft(node->right);

        return 1+max(left,right);
    }
    int findmaxheigh(TreeNode* root){
        if(root==NULL){
            return 0;
        }
    
        int left=findansfromleft(root->left);
        int right=findansfromright(root->right);

        int leftDia=findmaxheigh(root->left);
        int rightDia=findmaxheigh(root->right);

        return max({left + right, leftDia, rightDia});
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        return findmaxheigh(root);    
    }
};