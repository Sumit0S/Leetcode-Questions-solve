class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        sort(strs.begin(),strs.end());
        for(auto it:strs){
            cout<<it<<" ";
        }
        if(strs.size()<2){
            return strs[0];
        }
        string ans="";
        for(int i=0; i<strs[0].size(); i++){
            string s1=strs[0];
            string s2=strs[strs.size()-1];
            if(s1[i]==s2[i] and s1!="" and s2!=""){
                ans+=s1[i];
            }
            else{
                break;
            }
        }
        return ans;  
    }
};