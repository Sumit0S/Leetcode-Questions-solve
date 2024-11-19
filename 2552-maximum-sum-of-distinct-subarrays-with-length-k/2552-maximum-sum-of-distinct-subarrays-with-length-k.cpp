class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long curr_sum=0;
        long long res=0;
        unordered_map<int,int> mp;
        int l=0;
        for(int r=0; r<nums.size(); r++){
            curr_sum+=nums[r];
            mp[nums[r]]++;
            while(mp[nums[r]]>1 or r-l+1>k){
                curr_sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(r-l+1==k){
                res=max(res,curr_sum);
            }
        }
        return res;
    }
};