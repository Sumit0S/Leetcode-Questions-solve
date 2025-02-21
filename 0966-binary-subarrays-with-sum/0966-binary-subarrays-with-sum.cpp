class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        int curr_sum=0;
        mp[0]=1;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            curr_sum+=nums[i];
            if(mp.find(curr_sum-k)!=mp.end()){
                ans+=mp[curr_sum-k];
            }
            mp[curr_sum]++;
        }
        return ans;
    }
};