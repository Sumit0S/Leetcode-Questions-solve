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

    bool pathsum(TreeNode* root, int targetSum,vector<int> &v,int &sum,vector<vector<int>> &ans){
        if(root==NULL){
            return true;
        }

        v.push_back(root->val);
        sum+=root->val;

        bool left=pathsum(root->left,targetSum,v,sum,ans);
        bool right=pathsum(root->right,targetSum,v,sum,ans);
        if(left and right and targetSum==sum){
            ans.push_back(v);
        }

        v.pop_back();
        sum-=root->val;
        return false;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        int sum=0;
        pathsum(root,targetSum,v,sum,ans);
        return ans;
    }
};