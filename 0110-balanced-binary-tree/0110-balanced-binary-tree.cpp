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

    int balanced(TreeNode* root)
    {
        if(root==NULL){
            return 0;
        }
        int left=balanced(root->left);
        int right=balanced(root->right);
        if(left ==-1 or right==-1){
            return -1;
        }
        if(abs(right-left)>1){
            return -1;
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int ans=balanced(root);
        if(ans!=-1){
            return true;
        }
        else{
            return false;
        }
    }
};