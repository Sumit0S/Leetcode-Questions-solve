class Solution {
public:
    int subarraySum(vector<int>& arr, int k) 
    {
        int n = arr.size();
        map<int,int> mpp;
        int preSum = 0, cnt = 0;

        mpp[0] = 1;
        for (int i = 0; i < n; i++) {
            
            preSum += arr[i];

            // Calculate x-k:
            int remove = preSum - k;

            // Add the number of subarrays to be removed:
            cnt += mpp[remove];

            // Update the count of prefix sum
            // in the map.
            mpp[preSum]++;
        }
        return cnt;
    }
};