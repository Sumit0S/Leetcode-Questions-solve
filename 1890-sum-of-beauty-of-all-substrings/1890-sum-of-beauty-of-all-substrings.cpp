class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);  // Frequency array for characters 'a' to 'z'
            
            for (int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;  // Update frequency for current character

                // Calculate the beauty of the substring from i to j
                int maxFreq = *max_element(freq.begin(), freq.end());
                int minFreq = INT_MAX;
                
                // Find the minimum frequency of non-zero counts
                for (int f : freq) {
                    if (f > 0) minFreq = min(minFreq, f);
                }
                
                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;
    }
};