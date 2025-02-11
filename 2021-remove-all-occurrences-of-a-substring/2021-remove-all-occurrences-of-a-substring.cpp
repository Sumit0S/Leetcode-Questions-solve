class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        
        string ans="";

        for(int i=0; i<s.length(); i++)
        {
            ans+=s[i];

            if(ans.size()>=part.size() and ans.substr(ans.size()-part.size())==part){
                ans.resize(ans.size()-part.size());
            }
        }
        return ans;
    }
};