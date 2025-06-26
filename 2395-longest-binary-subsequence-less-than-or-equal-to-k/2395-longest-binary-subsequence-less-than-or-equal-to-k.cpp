class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int value = 0;
        long long power = 1;
        int n = s.length();

        // Traverse from the end (least significant bit)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++;  // Always safe to include 0
            } else {
                // Check if adding this '1' would still keep value ≤ k
                if (power <= k) {
                    k-=power;
                    count++;
                }
            }
            if(power<=k){
                power<<=1;
            }
        }

        return count;
    }
};
