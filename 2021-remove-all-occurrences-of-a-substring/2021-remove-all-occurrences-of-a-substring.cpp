class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        stack<char> st;
        int j=0;
        string ans="";
        bool main=false;
        for(int i=0; i<s.length(); i++){
            ans+=s[i];
            if(s[i]==part[j]){
                j++;
            }
            else{
                j=0;
            }
            if(j==part.size()){
                ans.resize(ans.size()-part.size());
            }
            if(ans.size()>=part.size() and ans.substr(ans.size()-part.size())==part){
                ans.resize(ans.size()-part.size());
            }
        }
        return ans;
    }
};