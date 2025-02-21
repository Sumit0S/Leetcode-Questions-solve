class Solution {
public:
    bool wordPattern(string pattern, string s) {

        string ss="";
        vector<string> cr;

        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                    ss+=s[i];
            }
            if(i==s.length()-1 or s[i+1]==' '){
                cr.push_back(ss);
                ss="";
            }
        }

        map<char,string> mp;
        map<string,char> mp2;

        if(pattern.size()!=cr.size()){
            return false;
        }

        for (int i = 0; i < cr.size(); i++) {
            if (mp.find(pattern[i]) != mp.end() && mp[pattern[i]] != cr[i]) {
                return false;
            }
            if (mp2.find(cr[i]) != mp2.end() && mp2[cr[i]] != pattern[i]) {
                cout<<"gh";
                return false; 
            }

            mp[pattern[i]] = cr[i];  
            mp2[cr[i]] = pattern[i];
        }
        return true;
    }
};