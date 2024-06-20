class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int n = nums.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;

    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high-low) / 2;

        // If we are in the left:
        if (nums[mid] < nums[mid + 1]) low = mid + 1;

        else high = mid;
    }
    // Dummy return statement
    return low;        
    }
};