class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length()<=1){
            return 0;
        }
        
        for (int i = 0; i < haystack.length(); i++) {
            // Iterate over all possible ending indices (ensuring substrings don't go out of bounds)
            for (int j = i + 1; j <= haystack.length(); j++) {
                // Extract the substring from index i to j (exclusive)
                string s = haystack.substr(i, j - i);
                cout<<s<<" ";
                if(s==needle){
                    return i;
                }
            }
        }
        return -1;
    }
};