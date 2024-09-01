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

    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
    if (!root) return {};

    queue<pair<TreeNode*,pair<int,int>>> q;
    map<int,map<int,vector<int> > > m;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        pair<TreeNode*,pair<int,int>> temp=q.front();
        q.pop();
        TreeNode* frontnode=temp.first;
        int lvl=temp.second.first;
        int hd=temp.second.second;

        m[hd][lvl].push_back(frontnode->val);

        if(frontnode->left){
            q.push({frontnode->left,{lvl+1,hd-1}});
        }

        if(frontnode->right){
            q.push({frontnode->right,{lvl+1,hd+1}});
        }
    }
    vector<vector<int>> ans;
        for (auto& p : m) {
            vector<int> col;
            for (auto& q : p.second) {
                // Sort the vector of node values to handle the tie in levels
                sort(q.second.begin(), q.second.end());
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
    return ans;
    }
};