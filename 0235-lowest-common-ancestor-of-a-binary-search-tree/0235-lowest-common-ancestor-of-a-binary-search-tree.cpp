/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* findlca(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL){
            return NULL;
        }

        if(root->val == p->val or root->val==q->val){
            return root;
        }

        TreeNode* left=findlca(root->left,p,q);
        TreeNode* right=findlca(root->right,p,q);

        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findlca(root,p,q);
    }
};