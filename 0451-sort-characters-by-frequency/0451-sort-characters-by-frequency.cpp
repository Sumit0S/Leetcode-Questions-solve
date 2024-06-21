class Solution {
public:
    string frequencySort(string s) {
        // Frequency map to store frequency of each character
        unordered_map<char, int> frequencyMap;
        for (char c : s) {
            frequencyMap[c]++;
        }

        // Vector to store characters and their frequencies
        vector<pair<char, int>> frequencyVector(frequencyMap.begin(), frequencyMap.end());

        // Custom comparator for sorting
        auto frequencyComparator = [](const pair<char, int> &a, const pair<char, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        };

        // Sort the vector by frequency
        sort(frequencyVector.begin(), frequencyVector.end(), frequencyComparator);

        // Build the result string
        string result;
        for (const auto &pair : frequencyVector) {
            result.append(pair.second, pair.first); // Append character pair.second times
        }

        return result;
    }
};