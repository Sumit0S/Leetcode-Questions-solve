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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root)
    {
        push(root);
    }
    
    void push(TreeNode* root){
        if(root==NULL){
            return;
        }
        st.push(root);
        push(root->left);
    }
    int next() {
        TreeNode* node = st.top();
        st.pop();  // Pop the current node
        if (node->right != nullptr) {
            push(node->right);  // Push the leftmost nodes of the right subtree
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */