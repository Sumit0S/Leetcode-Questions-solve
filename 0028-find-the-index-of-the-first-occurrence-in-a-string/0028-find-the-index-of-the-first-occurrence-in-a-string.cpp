class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length()<=1){
            return 0;
        }
        
            for (int j = 0; j <= haystack.length(); j++) {
                // Extract the substring from index i to j (exclusive)
                string s = haystack.substr(j,needle.length());
                cout<<s<<" ";
                if(s==needle){
                    return j;
                }
            }
        return -1;
    }
};