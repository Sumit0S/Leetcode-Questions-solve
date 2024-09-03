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
    void parentlink(TreeNode* root,unordered_map<TreeNode* ,TreeNode* > &linked)
    {
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            if(p->left){
                linked[p->left]=p;
                q.push(p->left);
            }
            if(p->right){
                linked[p->right]=p;
                q.push(p->right);
            }
        }   
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode* ,TreeNode* > linked;
        parentlink(root,linked);
        unordered_map<TreeNode* ,bool > visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int cur_level=0;

        while(!q.empty()){
            int siz=q.size();
            if(cur_level++==k){
                break;
            }

            for(int i=0; i<siz; i++){
                TreeNode* current=q.front(); q.pop();

                if(current->left and !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }

                if(current->right and !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(linked[current] && !visited[linked[current]]){
                    q.push(linked[current]);
                    visited[linked[current]]=true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            TreeNode* fr=q.front();
            q.pop();
            ans.push_back(fr->val);
            
        }
        return ans;
    }
};