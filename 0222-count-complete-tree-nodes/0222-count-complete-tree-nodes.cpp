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
    void count(TreeNode* root,int &cnt){
        if(root==NULL){
            
            return;
        }
        cnt+=1;
        count(root->left,cnt);
        count(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        if(root==NULL){
            return 0;
        }
        else{
            count(root,cnt);
            return cnt;
        }

    }
};