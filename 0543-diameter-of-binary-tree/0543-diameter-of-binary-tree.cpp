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
    int maxheight(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }

        int left=maxheight(root->left,diameter);
        int right=maxheight(root->right,diameter);

        diameter=max(diameter,left+right);


        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        maxheight(root,ans);
        return ans;
    }
};