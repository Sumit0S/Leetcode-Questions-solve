class Solution {
public:
    void subsets(vector<int> &nums,int i,vector<int> output,vector<vector<int> > &ans){
        if(i==nums.size()){
            ans.push_back(output);
            return;
        }
        // include
        int a=nums[i];
        output.push_back(a);
        subsets(nums,i+1,output,ans);

        // exclude
        output.pop_back();
        subsets(nums,i+1,output,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> output;
        subsets(nums,0,output,ans);
        return ans;
    }
};