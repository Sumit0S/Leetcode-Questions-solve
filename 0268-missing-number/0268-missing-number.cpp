class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum,ar_sum=0;
        for(int i=0; i<n; i++){
            sum+=i;
            ar_sum+=nums[i];
        }
        sum+=n;
        return (sum-ar_sum);
    }
};