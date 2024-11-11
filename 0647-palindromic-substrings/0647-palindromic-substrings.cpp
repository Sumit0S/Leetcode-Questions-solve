class Solution {
public:
    // Function to count palindromic substrings
    int countSubstrings(string s) {
        int n = s.length();
        int total_palindromes = 0;
        
        // Function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            int count = 0;
            // Expand as long as the characters match
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            return count;
        };
        
        // Loop through each character and count palindromes
        for (int i = 0; i < n; i++) {
            // Odd length palindromes (centered on the character)
            total_palindromes += expandAroundCenter(i, i);
            // Even length palindromes (centered between characters)
            total_palindromes += expandAroundCenter(i, i + 1);
        }
        
        return total_palindromes;
    }
};