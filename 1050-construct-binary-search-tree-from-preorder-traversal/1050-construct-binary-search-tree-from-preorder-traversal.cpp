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

    void make(TreeNode* &dummy,int val){
        TreeNode* root=dummy;
        while(root!=NULL){
            if(val<root->val){
                if(root->left!=NULL){
                    root=root->left;
                }
                else{
                    root->left=new TreeNode(val);
                    break;
                }
            }
            else{
                if(root->right!=NULL){
                    root=root->right;
                }
                else{
                    root->right=new TreeNode(val);
                    break;
                }
                
            }
        }

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            make(root,preorder[i]);
        }
        return root;
    }
};