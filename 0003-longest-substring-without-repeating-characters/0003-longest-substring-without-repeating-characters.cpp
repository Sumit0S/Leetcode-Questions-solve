class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> mp;
        int ans=0;
        int len=0;
        int l=0;
        for(int r=0; r<s.length(); r++)
        {

            if(mp.find(s[r])==mp.end()){
                len+=1;
                mp.insert(s[r]);
                ans=max(ans,len);
            }
            else{
                while(mp.find(s[r])!=mp.end()){
                    mp.erase(s[l]);
                    len--;
                    l++;
                }
                len+=1;
                mp.insert(s[r]);
            }
            
        }
        return ans;
    }
};