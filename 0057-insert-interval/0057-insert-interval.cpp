class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval); // Add the new interval to the list
        sort(intervals.begin(), intervals.end()); // Sort intervals by start time

        vector<vector<int>> merged; // This will store the merged intervals

        for (const auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                // No overlap, add the interval to the result
                merged.push_back(interval);
            } else {
                // Overlap, merge with the last interval in the result
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};