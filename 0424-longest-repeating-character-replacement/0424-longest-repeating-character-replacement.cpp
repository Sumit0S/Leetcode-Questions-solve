class Solution {
public:
    int characterReplacement(string s, int k) {

        int cnt=0;
        int maxlen=0;

        for(int i=0; i<s.length(); i++){
            int hash[26]={0} , maxfreq=0;
            for(int j=i; j<s.length(); j++){
                hash[s[j]-'A']++;
                maxfreq=max(maxfreq,hash[s[j]-'A']);
                int changes=(j-i+1)-maxfreq;
                if(changes<=k){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};