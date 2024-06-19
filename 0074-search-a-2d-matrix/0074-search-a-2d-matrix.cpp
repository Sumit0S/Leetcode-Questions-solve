class Solution {
public:
    int findvalue(vector<int>& matrix, int target, int n) {
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid] == target) {
                return mid;
            } else if (matrix[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Return -1 if the target is not found
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            int val = findvalue(matrix[i], target, matrix[i].size());
            if (val != -1) {
                return true;
            }
        }
        return false;
    }
};