class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0; 
        int n = nums.size();

        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        if (cnt > 1) return false;
        return true; // The array is a rotated sorted array
    }
};
