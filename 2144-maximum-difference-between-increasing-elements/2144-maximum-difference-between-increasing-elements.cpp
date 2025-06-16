class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        int smallest=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>smallest){
                ans=max(ans,nums[i]-smallest);
            }
            smallest=min(smallest,nums[i]);
        }
        return ans;
    }
};