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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,long long >> q;
        q.push({root,1});

        long long ans=1;
        while(!q.empty()){
            long long n=q.size();

            long long mini=0;
            long long maxi=0;
            long long mi = q.front().second;
            for(int i=0; i<n; i++)
            {

                auto front=q.front();
                q.pop();
                TreeNode* node=front.first;
                long long  val=front.second-mi;

                if (i == 0) mini = val;
                if (i == n - 1) maxi = val;
                if(node->left){
                    q.push({node->left,2*val});
                }
                if(node->right){
                     q.push({node->right,2*val+1});
                }
            }
            ans=max(ans,maxi-mini+1);
        }
        return ans;
    }
};