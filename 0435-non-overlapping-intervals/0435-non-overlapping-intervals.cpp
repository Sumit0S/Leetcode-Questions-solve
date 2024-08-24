class Solution {
public:
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int cnt = 0;
    int st = INT_MIN;

    for (const auto& interval : intervals) {
        if (interval[0] >= st) {
            st = interval[1];
        } else {
            cnt++;
        }
    }
    return cnt;
}

};