class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int sum=0;
        int ans_min=0;
        int ans_max=0;
        for(auto it:nums){
            sum+=it;
            ans_max=max(ans_max,sum);
            ans_min=min(ans_min,sum);
        }
        return ans_max-ans_min;
    }
};