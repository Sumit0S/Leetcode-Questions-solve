class Solution {
public:
    int myAtoi(string s) 
    {
        int i=0;
        int sign=1;
        int ans=0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }


        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow before updating ans
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return (ans * sign);

    }
};
