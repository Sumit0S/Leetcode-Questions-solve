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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> st;
        st.push(root);
        bool rev=true;

        while(!st.empty()){
            int n=st.size();
            vector<int> v;

            for(int i=0; i<n; i++){
                TreeNode* val=st.front();
                st.pop();
                v.push_back(val->val);
                if(val->left){
                    st.push(val->left);
                }
                if(val->right){
                    st.push(val->right);
                }
            }
            if(rev){
                rev=false;
                ans.push_back(v);
            }
            else{
                rev=true;
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
        }
        return ans;
    }
};