class Solution {
public:

    int calculateval(vector<int> &a, int maxSum) {
        int n = a.size(); // Size of array
        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < n; i++) {
            if (subarraySum + a[i] <= maxSum) {
                // Insert element to current subarray
                subarraySum += a[i];
            } else {
                // Insert element to next subarray
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int mini = *max_element(nums.begin(), nums.end()); // Maximum element in the array
        int max2 = accumulate(nums.begin(), nums.end(), 0); // Sum of all elements

        int low = mini;
        int high = max2;
        int result = high; // Initialize with a possible upper bound

        while (low <= high) {
            int mid = (low + high) / 2;
            int val = calculateval(nums, mid);
            
            if (val <= k) {
                result = mid; // Store the current mid as it's a valid maximum sum
                high = mid - 1; // Try to find a smaller valid maximum sum
            } else {
                low = mid + 1; // Increase the allowed maximum sum
            }
        }

        return result;
    }
};
