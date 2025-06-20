class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 2 >= nums.size()) return {}; // Not enough elements

            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if (c - a > k) return {}; // Max - Min > k

            ans.push_back({a, b, c});
        }

        return ans;
    }
};
