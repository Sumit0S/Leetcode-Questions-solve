#include <stack>
#include <string>

class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        std::stack<char> st;

        // Traverse each digit in the number
        for (char c : num) {
            // While the stack is not empty, we can still remove digits, and the current digit is smaller than the stack's top
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();  // Remove the top element
                k--;
            }
            st.push(c);  // Push the current digit onto the stack
        }
        
        // If we still need to remove digits, remove them from the end of the number (top of the stack)
        while (k > 0) {
            st.pop();
            k--;
        }

        // Build the result string from the stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;  // Prepend the current top element to the result string
            st.pop();
        }

        // Remove leading zeros from the result
        int non_zero_index = 0;
        while (non_zero_index < result.size() && result[non_zero_index] == '0') {
            non_zero_index++;
        }

        result = result.substr(non_zero_index);  // Get the substring without leading zeros

        // If the result is empty after removing leading zeros, return "0"
        return result.empty() ? "0" : result;
    }
};
