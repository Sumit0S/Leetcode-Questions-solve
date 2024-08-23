class Solution {
public:
    bool checker(string s,int i,int cnt,vector<vector<int>> &dp){
        if(i==s.length()){
            return (cnt==0);
        }
        if(cnt<0){
            return false;
        }
        if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }
        if(s[i]=='('){
            return dp[i][cnt] =checker(s,i+1,cnt+1,dp);
        }
        if(s[i]==')'){
            return dp[i][cnt] =checker(s,i+1,cnt-1,dp);
        }
    
        return dp[i][cnt]=checker(s,i+1,cnt+1,dp) || checker(s,i+1,cnt-1,dp) || checker(s,i+1,cnt,dp);;
        

    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length() + 1, -1));
        return checker(s,0,0,dp);
    }
};
