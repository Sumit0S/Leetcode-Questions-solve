class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0;
        int ans=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum<0){
                ans=max(ans,sum);
                sum=0;
                continue;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};