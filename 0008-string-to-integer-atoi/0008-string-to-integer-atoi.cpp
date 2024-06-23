class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int sign = 1;
        long ans = 0; // Using long to handle overflow during calculation
        
        // Step 1: Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle optional sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            // Step 4: Handle overflow and underflow
            if (ans * sign >= INT_MAX) {
                return INT_MAX;
            }
            if (ans * sign <= INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return static_cast<int>(ans * sign);
    }
};
