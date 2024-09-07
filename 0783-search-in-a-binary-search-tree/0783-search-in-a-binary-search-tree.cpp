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
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        // if(root->val>val)
        // {
           TreeNode* left1= find(root->left,val);
        // }
        // else{
           TreeNode* right1=find(root->right,val);
        // }
        if(left1==NULL){
            return right1;
        }
        else if(right1==NULL){
            return left1;
        }

        return root;

    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* r=find(root,val);
        return r;
    }
};