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

    // Helper function to find the path from the root to the target node.
    bool findPath(TreeNode* root, int target, string &path) {
        if (root == NULL) {
            return false;
        }
        if (root->val == target) {
            return true;
        }
        
        // Search in the left subtree
        path += 'L';
        if (findPath(root->left, target, path)) {
            return true;
        }
        path.pop_back(); // If not found, backtrack
        
        // Search in the right subtree
        path += 'R';
        if (findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back(); // If not found, backtrack
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        if (root == NULL) {
            return "";
        }
        
        string pathToStart = "";
        string pathToDest = "";
        
        // Find path from root to startValue and root to destValue
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);
        
        // Find the first divergence point between the two paths
        int i = 0;
        while (i < pathToStart.length() && i < pathToDest.length() && pathToStart[i] == pathToDest[i]) {
            i++;
        }
        
        // Calculate the directions
        string result = "";
        
        // Add 'U' for each step you move up from startValue to the common ancestor
        for (int j = i; j < pathToStart.length(); j++) {
            result += 'U';
        }
        
        // Add the path from the common ancestor to destValue
        result += pathToDest.substr(i);
        
        return result;
    }
};
