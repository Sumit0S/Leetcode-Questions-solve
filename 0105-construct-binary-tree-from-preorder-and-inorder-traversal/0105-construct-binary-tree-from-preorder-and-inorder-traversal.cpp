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

    TreeNode* buildTree2(vector<int>& preorder,int prestart,int preEnd,vector<int>& inorder,int instart,int inEnd,map<int,int> &inMap)
    {
        if(prestart>preEnd || instart>inEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=inMap[root->val];
        int numleft=inroot-instart;
        root->left=buildTree2(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,inMap);
        root->right=buildTree2(preorder,prestart+numleft+1,preEnd,inorder,inroot+1,inEnd,inMap);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> inMap;

        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]]=i;
        }

        TreeNode* root=buildTree2(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};