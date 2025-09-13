class Solution {
public:

    bool ispalindrome(int i,int j,string s)
    {
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void partitioning(int ind,string s,vector<string> &temp,vector<vector<string>> &ans)
    {
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(ispalindrome(ind,i,s)){
                temp.push_back(s.substr(ind,i-ind+1));
                partitioning(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        vector<vector<string>> ans;
        partitioning(0,s,temp,ans);
        return ans;
    }
};