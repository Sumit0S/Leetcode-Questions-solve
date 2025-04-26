class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> prefix(nums.size(),0);
        vector<int> suffix(nums.size(),1);

        int n=nums.size();
        for(int i=0; i<n; i++){
            prefix[i]=nums[i]*(i>0?prefix[i-1]:1);
            suffix[n-i-1]=nums[n-i-1]*(n-i<n?suffix[n-i]:1);
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            ans[i]=(i>0?prefix[i-1]:1)*(i+1<n?suffix[i+1]:1);
        }
        return ans;
    }
};