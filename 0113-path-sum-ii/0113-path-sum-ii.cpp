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
    void helper(TreeNode* root,vector<int>v,vector<vector<int>>&ans,int sum){
        if(root==NULL) return;
        // this condition specify that we are in leaf node.because right & left of leaf node is NULL 
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum){
                v.push_back(root->val);
                ans.push_back(v);
            }
            
        }
        v.push_back(root->val);
        // Recursively call the helper function for left and right subtrees
        helper(root->left,v,ans,sum-root->val);
        helper(root->right,v,ans,sum-root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(root,v,ans,targetSum);
        return ans;
    }
};