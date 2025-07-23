class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int left=0;
        unordered_set<int> mp;

        int currsum=0;
        int ans=0;
        for(int right=0; right<nums.size(); right++){
            currsum+=nums[right];
            while(mp.find(nums[right])!=mp.end() and left<right){
                currsum-=nums[left];
                mp.erase(nums[left]);
                left++;
            }
            mp.insert(nums[right]);
            ans=max(ans,currsum);
        }
        return ans;
    }
};