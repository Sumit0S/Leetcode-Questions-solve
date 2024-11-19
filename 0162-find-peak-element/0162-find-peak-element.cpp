class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Compare middle element with its right neighbor
            if (nums[mid] > nums[mid + 1]) {
                // Peak is in the left half (including mid)
                high = mid;
            } else {
                // Peak is in the right half (excluding mid)
                low = mid + 1;
            }
        }
        // 'low' and 'high' converge to the peak element
        return high;
    }
};
