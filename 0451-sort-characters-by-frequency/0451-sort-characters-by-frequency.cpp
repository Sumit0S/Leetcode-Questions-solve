class Solution {
public:
    std::string frequencySort(std::string s) {
        // Unordered map to store frequency of each character
        std::unordered_map<char, int> mp;
        
        // Priority queue (max-heap) to store pairs of (frequency, character)
        std::priority_queue<std::pair<int, char>> pq;

        // Count the frequency of each character
        for (char c : s) {
            mp[c]++;
        }

        // Push each character and its frequency to the priority queue
        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }

        // Construct the result string
        std::string ans = "";
        while (!pq.empty()) {
            ans += std::string(pq.top().first, pq.top().second);
            pq.pop();
        }

        return ans;
    }
};