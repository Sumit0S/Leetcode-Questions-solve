class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 2) {
            return s;
        }

        string result;
        int count = 1;

        // Start by adding the first character
        result += s[0];

        // Iterate from the second character onward
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            // Only add the character if it doesn't create three in a row
            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};
