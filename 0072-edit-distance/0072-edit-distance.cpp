class Solution {
public:
    int f(int i,int j,string word1,string word2,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }

        if(j<0)
        {
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return f(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j]=1+ min(f(i,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));
    }
    int minDistance(string word1, string word2) 
    {
        int l1=word1.size();
        int l2=word2.size();
        vector<vector<int>> dp(l1,vector<int> (l2,-1));
        return f(l1-1,l2-1,word1,word2,dp);
    }
};