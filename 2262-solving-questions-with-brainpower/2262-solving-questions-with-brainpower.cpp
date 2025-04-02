class Solution {
public:

    long long rec(vector<vector<int>>& questions,int &ans,long long &curr,int i,int size,vector<long long> &dp){
        if(i>=size){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        auto it=questions[i];
        

        long long left = curr+it[0] +rec(questions,ans,curr,i+it[1]+1,size,dp);

        long long right =rec(questions,ans,curr,i+1,size,dp);

        return dp[i]=max(left,right);
    }
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int ans=0;
        int i=0;
        int size=questions.size();
        long long  curr=0;
        vector<long long> dp(questions.size(),-1);
        return rec(questions,ans,curr,i,size,dp);
    }
};