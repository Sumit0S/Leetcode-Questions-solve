class Solution {
public:
    vector<int> applyOperations(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> ans(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            if(i+1<n and nums[i]==nums[i+1]){
                nums[i]=2*nums[i+1];
                nums[i+1]=0;
            }
        }
        int index=0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                ans[index]=nums[i];
                index++;
            }
        }
        return ans;
    }
};