#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // Find the maximum number of bananas in a single pile
        int n = *std::max_element(piles.begin(), piles.end());
        
        // Binary search initialization
        int low = 1; // Start from 1 because 0 speed is not feasible
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = 0; // Use long long to avoid overflow

            // Calculate total hours needed with the current eating speed (mid)
            for (int i = 0; i < piles.size(); i++) {
                totalH += (piles[i] + mid - 1) / mid; // Equivalent to ceil(piles[i] / (double)mid)
            }

            // Check if the current speed can finish eating all bananas in h hours
            if (totalH <= h) {
                high = mid - 1; // Try for a smaller speed
            } else {
                low = mid + 1; // Increase the speed
            }
        }

        return low; // Return the minimum speed at which Koko can eat all the bananas
    }
};