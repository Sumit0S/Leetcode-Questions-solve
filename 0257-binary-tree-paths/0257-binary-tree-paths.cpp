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
    void findeverynode(TreeNode* root,vector<string> &ans,string s){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL and root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val) + "->";
        findeverynode(root->left,ans,s);
        findeverynode(root->right,ans,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        findeverynode(root,ans,s);
        return ans;
    }
};