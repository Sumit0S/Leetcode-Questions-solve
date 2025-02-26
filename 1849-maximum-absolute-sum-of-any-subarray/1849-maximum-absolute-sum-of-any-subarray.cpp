class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int val=0;

        int sum=0;
        int ans_min=INT_MAX;
        int ans_max=INT_MIN;
        for(auto it:nums){
            sum+=it;
            ans_max=max(ans_max,sum);
            if(sum<0){
                sum=0;
            }
        }

        sum=0;
        for(auto it:nums){
            sum+=it;
            ans_min=min(ans_min,sum);
            if(sum>0){
                sum=0;
            }
        }
        
        return max(ans_max,abs(ans_min));
    }
};