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
    // Helper function to check the validity of the BST
    bool check(TreeNode* root, long min, long max) {
        // Base case: an empty tree is a valid BST
        if (root == NULL) {
            return true;
        }
        // The current node's value must be within the valid range (min, max)
        if (root->val <= min || root->val >= max) {
            return false;
        }

        // Recursively check left and right subtrees
        bool left = check(root->left, min, root->val);
        bool right = check(root->right, root->val, max);

        // The current subtree is valid if both left and right subtrees are valid
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        // Start the check with the entire range of valid long values
        return check(root, LONG_MIN, LONG_MAX);
    }
};

