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
    TreeNode* replaceValueInTree(TreeNode* root) {
       if (!root) return nullptr;

       int current_levl_sum=root->val;

       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){

        int next_lvl_sum=0;
        int a=q.size();
        for(int i=0; i<a; i++){
            TreeNode* temp=q.front();
            q.pop();

            temp->val = current_levl_sum - temp->val;
        
            int sib_sum = (temp->left?temp->left->val:0) + (temp->right?temp->right->val:0);
            if(temp->left){
                temp->left->val=sib_sum;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->val=sib_sum;
                q.push(temp->right);
                next_lvl_sum+=temp->right->val;
            }
            
        }
        
        current_levl_sum=next_lvl_sum;
       }       
       return root;
    }
};