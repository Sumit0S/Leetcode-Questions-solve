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

    void pathsum(TreeNode* root, int targetSum,vector<int> &v,int &sum,vector<vector<int>> &ans){
        if(root==NULL){

            return;
        }

        v.push_back(root->val);
        sum+=root->val;

        if(sum==targetSum and root->left==NULL and root->right==NULL){
            ans.push_back(v);
        }
        pathsum(root->left,targetSum,v,sum,ans);
        pathsum(root->right,targetSum,v,sum,ans);
        v.pop_back();
        sum-=root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        int sum=0;
        pathsum(root,targetSum,v,sum,ans);
        return ans;
    }
};