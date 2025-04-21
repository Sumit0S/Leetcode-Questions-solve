class Solution {
public:
    bool rec(int i, int n, vector<int>& nums, vector<int>& dp) {
        if(i >= n - 1) return true;
        if(dp[i] != -1) return dp[i];
        
        int furthestJump = min(i + nums[i], n - 1);
        for(int j = i + 1; j <= furthestJump; j++) {
            if(rec(j, n, nums, dp)) {
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return rec(0, nums.size(), nums, dp);
    }
};
