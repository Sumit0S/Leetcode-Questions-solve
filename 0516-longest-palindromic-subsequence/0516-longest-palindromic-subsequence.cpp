class Solution {
public:

    int solve(string a,string b,int i,int j,vector<vector<int>> &dp){
        if(i==a.length() or j==b.length()){
            return 0;
        }
        int ans=0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1,dp);
        }

        else{
            ans=max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s)
    {
        if(s.length()<=1){
            return 1;
        }
        
        string b=s;
        vector<vector<int>> dp(s.length(),vector<int>(b.length(),-1));
        reverse(b.begin(),b.end());
        int anss=solve(s,b,0,0,dp);

        return anss;
    }
};