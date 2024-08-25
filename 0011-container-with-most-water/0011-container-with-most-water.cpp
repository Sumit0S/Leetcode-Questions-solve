class Solution {
public:
    int maxArea(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        int ans = 0;

        while (l < r) {
            // Calculate the area with the current l and r
            int cal = min(arr[l], arr[r]) * (r - l);
            // Update ans if the new area is larger
            ans = max(ans, cal);

            // Move the pointers
            if (arr[l] < arr[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};
