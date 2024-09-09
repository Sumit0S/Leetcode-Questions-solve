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

    class BSTIterator {
    public:
        stack<TreeNode*> st;
        bool reverse=true;
        BSTIterator(TreeNode* root,bool isReverse)
        {
            reverse=isReverse;
            push(root);
        }
        
        void push(TreeNode* root){

            if(root==NULL){
                return;
            }
            if(reverse!=true){
                st.push(root);
                push(root->left);
            }
            else{
                st.push(root);
                push(root->right);
            }
        }
        int next() {
            TreeNode* node = st.top();
            st.pop();  // Pop the current node
            if(!reverse){
                if (node->right != nullptr) {
                    push(node->right);  // Push the leftmost nodes of the right subtree
                }
            }
            else{
                if (node->left != nullptr) {
                    push(node->left);  // Push the leftmost nodes of the right subtree
                }
            }
            return node->val;
        }
        
        bool hasNext() {
            return !st.empty();
        }
    };

    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
    }
};