class Solution {
public:
    int maxArea(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        int ans = 0;

        while (l < r) {


            if (arr[l] < arr[r]) {
                int cal = min(arr[l], arr[r]) * (r - l);
                ans = max(ans, cal);
                l++;
            } else {
                int cal = min(arr[l], arr[r]) * (r - l);
                ans = max(ans, cal);
                r--;
            }
        }

        return ans;
    }
};
