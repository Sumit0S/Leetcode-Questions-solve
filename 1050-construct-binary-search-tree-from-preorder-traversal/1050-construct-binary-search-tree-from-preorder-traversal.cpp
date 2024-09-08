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
    // Function to insert a new value into the binary search tree
    void insert(TreeNode* root, int val) {
        // If the value is less than the current node's value, go to the left subtree
        if(val < root->val) {
            // If there is no left child, create a new node and attach it as the left child
            if(root->left == NULL) root->left = new TreeNode(val);
            // If a left child exists, recursively insert the value into the left subtree
            else insert(root->left, val);
        }
        // If the value is greater than or equal to the current node's value, go to the right subtree
        else {
            // If there is no right child, create a new node and attach it as the right child
            if(root->right == NULL) root->right = new TreeNode(val);
            // If a right child exists, recursively insert the value into the right subtree
            else insert(root->right, val);
        }
    }

    // Function to build a BST from a given preorder traversal array
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Create the root node with the first element of the preorder array
        TreeNode* root = new TreeNode(preorder[0]);
        
        // Iterate through the rest of the elements in the preorder array
        for(int i = 1; i < preorder.size(); i++) {
            // Insert each element into the BST
            insert(root, preorder[i]);
        }
        
        // Return the root of the constructed BST
        return root;
    }
};