class Solution {
public:

    void find(int ind, int sum, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans, int n){
        if(sum==target){
            ans.push_back(temp);
        }

        for(int i=ind; i<n; i++){
            if(sum + candidates[i] > target) continue;
            if(i>ind and candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            find(i+1, sum + candidates[i], candidates, target, temp, ans, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        find(0, 0, candidates, target, temp, ans, n);
        return ans;      
    }
};