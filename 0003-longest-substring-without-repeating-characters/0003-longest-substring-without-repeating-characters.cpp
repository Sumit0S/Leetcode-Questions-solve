class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0)
        {
            return 0;
        }

        int maxans = INT_MIN;

        unordered_map<char, int> sett;
        int l=0;
        for(int r=0; r<s.length(); r++){
            if(sett.find(s[r])!=sett.end()){
                l = max(sett[s[r]] + 1, l); 
            }
            sett[s[r]] = r;
            maxans = max(maxans, r - l + 1);
        }
        return maxans;
    }
};