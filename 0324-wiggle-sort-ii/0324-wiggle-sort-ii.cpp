class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int n = nums.size();

        int j = (n + 1) / 2 - 1;  // Middle of the sorted array for left half
        int k = n - 1;  // End of the sorted array for the right half

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sortedNums[j--];  // Fill from the end of the left half
            } else {
                nums[i] = sortedNums[k--];  // Fill from the end of the right half
            }
        }
    }
};
