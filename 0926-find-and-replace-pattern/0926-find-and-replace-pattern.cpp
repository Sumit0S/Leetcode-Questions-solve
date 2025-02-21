class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            string curr=words[i];
            if(curr.size()!=pattern.size()){
                continue;
            }
            else{
                map<char,char> mp;
                map<char,char> mp2;
                bool mark=true;
                for(int i=0; i<curr.size(); i++){
                    if(mp.find(curr[i])!=mp.end() and mp[curr[i]]!=pattern[i]){
                        mark=false;
                        break;
                    }
                    if(mp2.find(pattern[i])!=mp2.end() and mp2[pattern[i]]!=curr[i]){
                        mark=false;
                        break;
                    }
                    mp[curr[i]]=pattern[i];
                    mp2[pattern[i]]=curr[i];
                }
                if(mark){
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};