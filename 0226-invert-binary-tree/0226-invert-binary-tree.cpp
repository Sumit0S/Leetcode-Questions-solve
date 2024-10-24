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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL){
            return root;
        }
        while(!q.empty()){
            int a=q.size();

            for(int i=0; i<a; i++){
                TreeNode* temp=q.front();
                q.pop();
                TreeNode* store=temp->left;;
                temp->left=temp->right;
                temp->right=store;
                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};