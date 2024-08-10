class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxlen=0;
        int max_freq=0;
        unordered_map<char,int> mpp;
        for(int r=0; r<s.length(); r++)
        {
            mpp[s[r]]++;
            max_freq=max(max_freq,mpp[s[r]]);
            int len=(r-l+1)-max_freq;
            if(len>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(len<=k){
                maxlen=max(maxlen,r-l+1);
            }
        }
        return maxlen;
    }
};