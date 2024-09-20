class Solution {
public:

    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else {
                if(st.empty()){
                    return false;
                }
                if((s[i]==')' and st.top()=='(') || 
                (s[i]==']' and st.top()=='[') || 
                (s[i]=='}' and st.top()=='{') and !st.empty()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};