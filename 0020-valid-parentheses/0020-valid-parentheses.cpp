class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(char c : s){
           if (c == '(' || c == '{' || c == '['){
                st.push(c);
           }
           else{
            if(st.empty()){
                return false;
            }
            char ss=st.top();
            if(                    (c == ')' && st.top() != '(') || // the closing bracket doesn't match the corresponding opening bracket at the top of the stack
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')){
                return false;
            }
            st.pop();
           }
        }
        return st.empty();
    }
};