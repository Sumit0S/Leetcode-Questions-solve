
class Solution {
public:
    int longestPalindrome(string s) 
    {
        sort(s.begin(), s.end());

        int ans = 0;
        int r = 0;
        bool hasOdd = false;

        while (r < s.length()) {
            int cnt = 1;  // Initialize count for the current character
            
            // Count frequency of the current character
            while (r + 1 < s.length() && s[r] == s[r + 1]) {
                cnt++;
                r++;
            }

            // Add even counts fully, adjust odd counts
            if (cnt % 2 == 0) {
                ans += cnt;
            } else {
                ans += cnt - 1;
                hasOdd = true;  // Remember there's an odd frequency
            }

            r++;  // Move to the next character
        }

        // Add one if there's any character with an odd frequency
        if (hasOdd) {
            ans += 1;
        }

        return ans;
    }
};
