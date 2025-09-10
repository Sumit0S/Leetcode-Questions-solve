class Solution {
public:

    void findans(int ind,int n,vector<vector<int>> &ans,vector<int>& temp,vector<int>& nums){
        ans.push_back(temp);
        for(int i=ind; i<n; i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);          
            findans(i + 1, n, ans, temp, nums); 
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            vector<int> temp;
            findans(0,nums.size(),ans,temp,nums);
            return ans;
    }
};