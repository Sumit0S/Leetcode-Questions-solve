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
    TreeNode* dfs(vector<int> &preorder, int start, int end) {
        if(start > end) return nullptr;

        TreeNode *root = new TreeNode(preorder[start]);

        if(start == end) return root;

        //find right node
        //right node is first greater than current
        auto itr = upper_bound(preorder.begin() + start, preorder.begin() + end + 1, root->val); //end + 1 means iter in [first, last) 
        if(itr != preorder.end()) { //found right node
            int r_idx = distance(preorder.begin(), itr);
            root->left = dfs(preorder, start + 1, r_idx - 1);
            root->right = dfs(preorder, r_idx, end);
        } else { //does not exist right node
            root->left = dfs(preorder, start + 1, end);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);    
    }
};