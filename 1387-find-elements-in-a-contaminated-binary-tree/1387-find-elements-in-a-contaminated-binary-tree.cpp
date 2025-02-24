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
class FindElements {
public:

    void dfs(TreeNode* root,int x){
        // if(root==NULL){
        //     return;
        // }
        root->val=x;
        s.insert(x);
        if(root->left){
            dfs(root->left,(2*x)+1);
        }
        if(root->right){
            dfs(root->right,(2*x)+2);
        }
        return;
      }
    unordered_set<int> s;
    FindElements(TreeNode* root)
    {
        dfs(root,0);
    }
    
    bool find(int target) {
        return s.count(target);
    }
};
