#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::unordered_set<long long> numSet(nums.begin(), nums.end());  // Use a set for quick lookup
        int longestStreak = 1;

        for (int num : nums) {
            int currentStreak = 1;
            long long currentVal = num;

            // Check if squares of the current value exist in numSet
            while (numSet.find(currentVal * currentVal) != numSet.end()) {
                currentVal *= currentVal;
                currentStreak++;
            }

            longestStreak = std::max(longestStreak, currentStreak);
        }

        return longestStreak > 1 ? longestStreak : -1;  // Return -1 if the longest streak is only 1
    }
};
