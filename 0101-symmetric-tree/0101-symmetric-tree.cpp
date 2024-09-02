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
    bool ism(TreeNode* leftnode,TreeNode* rightnode){
        if(leftnode==NULL and rightnode==NULL){
            return true;
        }
        if(leftnode==NULL and rightnode!=NULL){
            return false;
        }
        if(leftnode!=NULL and rightnode==NULL){
            return false;
        }
        if(leftnode->val!=rightnode->val){
            return false;
        }
        bool a=ism(leftnode->left,rightnode->right);
        bool b=ism(leftnode->right,rightnode->left);

        return a&b;

    }
    bool isSymmetric(TreeNode* root) {
        return ism(root->left,root->right);
    }
};