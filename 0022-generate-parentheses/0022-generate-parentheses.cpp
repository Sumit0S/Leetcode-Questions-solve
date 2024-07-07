class Solution {
public:
    void paranthesis(int n,int opening ,int closing,vector<string> &ans,string s){
        if(opening==n and closing==n){
            ans.push_back(s);
            return;
        }
        if(opening<n){
            paranthesis(n,opening+1,closing,ans,s+"(");
        }

        if(opening>closing){
            paranthesis(n,opening,closing+1,ans,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        paranthesis(n,0,0,ans,"");
        return ans;
    }
};