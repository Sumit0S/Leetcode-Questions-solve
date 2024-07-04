class Solution {
public:
    void subsetsum(vector<int> nums, int n,int index,vector<int> output,set<vector<int>> &ans)
    {
        if(index>=n){
            sort(output.begin(), output.end());
            ans.insert(output);
            return;
        }
        // for(int i=index; i<nums.size(); i++){
        //     if(nums[i]==nums[i-1]){
        //         continue;
        //     }
            int a=nums[index];
            output.push_back(a);
            subsetsum(nums,n,index+1,output,ans);
            output.pop_back();
        // }

        subsetsum(nums,n,index+1,output,ans);
        return;
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> output;
        set<vector<int>> ans;
        vector<vector<int>> ans1;
        subsetsum(nums,nums.size(),0,output,ans);
        for (auto it = ans.begin(); it != ans.end(); it++) {
            ans1.push_back( * it);
        }
        return ans1;
    }
};