
class Solution {
public:
    int maxUniqueSplit(string s1) {
        unordered_set<string> mp; // Using set to store unique substrings
        return backtrack(s1, mp, 0);
    }

private:
    int backtrack(const string& s1, unordered_set<string>& mp, int start) {
        if (start == s1.size()) return 0; // No more characters to process
        
        int maxCount = 0;
        string current = "";
        
        for (int i = start; i < s1.size(); ++i) {
            current += s1[i]; // Build the substring
            
            if (mp.find(current) == mp.end()) { // If the substring is unique
                mp.insert(current); // Add it to the set
                maxCount = max(maxCount, 1 + backtrack(s1, mp, i + 1)); // Count this split and continue
                mp.erase(current); // Backtrack: remove the substring from the set
            }
        }
        
        return maxCount;
    }
};