class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        map<char,char> mp2;
        int i=0;
        int n=min(s.length(),t.length());
        
        while(i<n){
            if((mp.find(s[i])!=mp.end()) || mp2.find(t[i])!=mp2.end())
            {
                // if(mp2[t[i]]!=t[i]){
                //     return false;
                // }
                cout<<i<<" ";
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
            
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
            i++;
        }
        return true;
    }
};