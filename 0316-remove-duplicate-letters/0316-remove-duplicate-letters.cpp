class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastoccurence(26,-1);
        vector<bool> visited(26,false);

        stack<int> st;

        for(int i=0; i<s.size(); i++){
            lastoccurence[s[i]-'a']=i;
        }

        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
                visited[s[i]-'a']=true;
                continue;
            }

            while(!st.empty() and st.top()>s[i] and lastoccurence[st.top()-'a']>i and !visited[s[i]-'a']){
                visited[st.top()-'a']=false;
                st.pop();
            }

            if (visited[s[i] - 'a'] == false) {
                visited[s[i] - 'a'] = true; // Mark the current character as visited.
                st.push(s[i]); // Push the current character onto the stack.
            }
        }

        string ans="";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Reverse the result string to get the correct order.
        reverse(ans.begin(), ans.end());
        return ans;

    }
};