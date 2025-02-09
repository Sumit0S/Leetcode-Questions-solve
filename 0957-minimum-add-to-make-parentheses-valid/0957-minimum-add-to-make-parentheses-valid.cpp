class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int n = s.size();
        int ans=0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(')
                size++;
            else if(ch==')'){
                size--;
                if(size<0){
                    size++;
                    ans++;
                }
            }
        }
        return ans+abs(size);      
    }
};