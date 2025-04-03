class Solution {
public:

    int rec(int i,vector<int>& cost,int size,vector<int>& dp){
        if(i>=size){
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        int step1=cost[i]+rec(i+1,cost,size,dp);
        
        int step2=cost[i]+rec(i+2,cost,size,dp);

        return dp[i] = min(step1, step2);
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> dp(cost.size(),-1);
        int n=cost.size();
        return min(rec(0, cost, n, dp), rec(1, cost, n, dp));
    }
};