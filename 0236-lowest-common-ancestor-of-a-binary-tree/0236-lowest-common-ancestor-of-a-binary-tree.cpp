/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 */
class Solution {
public:

    TreeNode* findval(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left=findval(root->left,p,q);
        TreeNode* right=findval(root->right,p,q);

        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }

        else {
            return root;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return findval(root,p,q);
    }
}; 