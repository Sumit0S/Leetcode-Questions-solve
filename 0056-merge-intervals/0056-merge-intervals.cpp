class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end()); 

        vector<vector<int>> merged; 

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