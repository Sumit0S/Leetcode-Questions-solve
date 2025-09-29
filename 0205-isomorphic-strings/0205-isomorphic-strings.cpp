class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        set<char> visited;
        unordered_map<char,char> mp;

        for(int i=0; i<min(s.length(),t.length()); i++)
        {
            if(mp.find(s[i])!=mp.end()){
                if(t[i]!=mp[s[i]]){
                    return false;
                }
            }
            else{
                if(visited.find(t[i])!=visited.end()){
                    return false;
                }
                visited.insert(t[i]);
                mp[s[i]]=t[i];
            } 
        }
        return true;
    }
};