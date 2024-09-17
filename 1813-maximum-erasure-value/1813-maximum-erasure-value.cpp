class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> mp;  // Set to store unique elements in the current window
        int l = 0, ans = 0, current_sum = 0;  // Left pointer, answer, and running sum
        
        for (int r = 0; r < nums.size(); r++) {
            // If nums[r] is already in the set, shrink the window from the left
            while (mp.find(nums[r]) != mp.end()) {
                current_sum -= nums[l];  // Remove the value at the left pointer from current_sum
                mp.erase(nums[l]);       // Remove nums[l] from the set
                l++;                     // Move the left pointer forward
            }
            
            // Add the new unique number to the set and to the current sum
            mp.insert(nums[r]);
            current_sum += nums[r];
            
            // Update the maximum sum of the unique subarray
            ans = max(ans, current_sum);
        }
        
        return ans;
    }
};