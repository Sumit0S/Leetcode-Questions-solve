// class Solution {
// public:
//     bool rec(int i, string &s, stack<char> st) {  // Pass stack by value to avoid modification across branches
//         if (i >= s.size()) {
//             return st.empty();
//         }
        
//         if (s[i] == '(') {
//             st.push('(');
//             return rec(i + 1, s, st);
//         } else if (s[i] == ')') {
//             if (st.empty()) {
//                 return false;
//             }
//             st.pop();
//             return rec(i + 1, s, st);
//         } else { // s[i] == '*'
//             // Case 1: Treat '*' as '('
//             stack<char> st1 = st;
//             st1.push('(');
//             bool take_as_open = rec(i + 1, s, st1);
            
//             // Case 2: Treat '*' as ')'
//             bool take_as_close = false;
//             if (!st.empty()) {
//                 stack<char> st2 = st;
//                 st2.pop();
//                 take_as_close = rec(i + 1, s, st2);
//             }
            
//             // Case 3: Treat '*' as empty
//             bool take_as_empty = rec(i + 1, s, st);
            
//             return take_as_open || take_as_close || take_as_empty;
//         }
//     }

//     bool checkValidString(string s) {
//         stack<char> st;
//         return rec(0, s, st);
//     }
// };



// class Solution {
// public:
//     bool rec(int i, string &s, stack<char> &st) {  // Pass stack by reference
//         if (i >= s.size()) {
//             return st.empty();
//         }
        
//         if (s[i] == '(') {
//             st.push('(');
//             if (rec(i + 1, s, st)) {
//                 return true;
//             }
//             st.pop();  // Backtrack
//             return false;
//         } else if (s[i] == ')') {
//             if (st.empty()) {
//                 return false;
//             }
//             st.pop();
//             if (rec(i + 1, s, st)) {
//                 return true;
//             }
//             st.push(')');  // Backtrack (but since we popped '(', we need to push it back)
//             return false;
//         } else { // s[i] == '*'
//             // Case 1: Treat '*' as '('
//             st.push('(');
//             if (rec(i + 1, s, st)) {
//                 return true;
//             }
//             st.pop();  // Backtrack

//             // Case 2: Treat '*' as ')'
//             if (!st.empty()) {
//                 st.pop();
//                 if (rec(i + 1, s, st)) {
//                     return true;
//                 }
//                 st.push('(');  // Backtrack
//             }

//             // Case 3: Treat '*' as empty
//             if (rec(i + 1, s, st)) {
//                 return true;
//             }

//             return false;
//         }
//     }

//     bool checkValidString(string s) {
//         stack<char> st;
//         return rec(0, s, st);
//     }
// };


class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; // Track min/max open brackets

        for (char c : s) {
            if (c == '(') {
                low++; high++;
            } 
            else if (c == ')') {
                low--; high--;
            } 
            else { // '*'
                low--; high++; 
            }

            if (high < 0) return false; // More ')' than possible '('

            if (low < 0) low = 0; // Reset low (we can't have negative '(' count)
        }
        
        return low == 0;
    }
};