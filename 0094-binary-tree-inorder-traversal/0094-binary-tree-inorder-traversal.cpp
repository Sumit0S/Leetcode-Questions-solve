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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        if(root==NULL){
            return ans;
        }
        TreeNode* temp=root;
        while(true){
            if(temp->left!=NULL){
                st.push(temp->left);
                temp=temp->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                else{
                    TreeNode* front=st.top();
                    st.pop();
                    ans.push_back(front->val);
                    if(front->right!=NULL){
                        st.push(front->right);
                        temp=front->right;
                    }
                }
            }
        }
        return ans;
    }
};