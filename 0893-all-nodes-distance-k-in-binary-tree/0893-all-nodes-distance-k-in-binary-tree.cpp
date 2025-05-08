/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void parent2(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front->left){
                parent[front->left]=front;
                 q.push(front->left); 
            }
            if(front->right){
                parent[front->right]=front;
                 q.push(front->right); 
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode* ,TreeNode* > parent;
        parent2(root,parent);
        unordered_map<TreeNode* ,bool > visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;

        int cur_level=0;
        while(!q.empty())
        {
            if(cur_level++==k){
                break;
            }
            int n=q.size();
            for(int i=0; i<n; i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left and !visited[front->left]){
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right and !visited[front->right]){
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(parent[front] and !visited[parent[front]]){
                    visited[parent[front]]=true;
                    q.push(parent[front]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};