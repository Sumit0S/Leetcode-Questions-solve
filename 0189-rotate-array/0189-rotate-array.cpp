class Solution {
public:
    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        int rotations = k % n, regular = 0;
        if (rotations == 0)
            return;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i){
            if (rotations > 0)
                ans[i] = nums[n - rotations--];
            else
                ans[i] = nums[regular++];
        }
        nums = ans;
    }
};