class Solution {
public:

    void find(int ind, int sum, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans, int n){
        if(sum==target){
            ans.push_back(temp);
        }

        for(int i=ind; i<n; i++){
            if(sum + candidates[i] > target) continue;
            temp.push_back(candidates[i]);
            find(i, sum + candidates[i], candidates, target, temp, ans, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        find(0, 0, candidates, target, temp, ans, n);
        return ans;
    }
};