class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   
        int maxlength=0;
        int left=0;
        unordered_set<char> ch;

        for(int r=0; r<s.length(); r++){
            while(ch.find(s[r])!=ch.end()){
                ch.erase(s[left]);
                left++;
            }
            ch.insert(s[r]);
            maxlength=max(maxlength,r-left+1);
        }
        return maxlength;    
    }
};