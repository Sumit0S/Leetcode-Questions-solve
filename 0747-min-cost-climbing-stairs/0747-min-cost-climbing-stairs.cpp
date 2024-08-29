class Solution 
{
private:
    int check(int i, vector<int>cost,int n,  vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int one_climb = cost[i] + check(i + 1, cost, n , dp );
        int two_climb = cost[i] + check(i + 2, cost, n , dp);
        dp[i] = min(one_climb, two_climb);
        return dp[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1, -1);
        int start_from_0th_step = check(0, cost,n, dp ); 
        int start_from_1th_step = check(1, cost,n , dp );
        int ans =    min(start_from_0th_step , start_from_1th_step);
        return ans; 
    }
};

//cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// dp = dp = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]

// Index 9:
// Only one step to the top: dp[9] = cost[9] + dp[10] = 1 + 0 = 1

// 2. Index 8:
// One step to index 9: cost[8] + dp[9] = 100 + 1 = 101
// Two steps to the top: cost[8] + dp[10] = 100 + 0 = 100
// dp[8] = min(101, 100) = 100

// 3. Index 7:
// One step to index 8: cost[7] + dp[8] = 1 + 100 = 101
// Two steps to index 9: cost[7] + dp[9] = 1 + 1 = 2
// dp[7] = min(101, 2) = 2

// 4. Index 6:
// One step to index 7: cost[6] + dp[7] = 1 + 2 = 3
// Two steps to index 8: cost[6] + dp[8] = 1 + 100 = 101
// dp[6] = min(3, 101) = 3

// 5. Index 5:
// One step to index 6: cost[5] + dp[6] = 100 + 3 = 103
// Two steps to index 7: cost[5] + dp[7] = 100 + 2 = 102
// dp[5] = min(103, 102) = 102

// Index 4:
// One step to index 5: cost[4] + dp[5] = 1 + 102 = 103
// Two steps to index 6: cost[4] + dp[6] = 1 + 3 = 4
// dp[4] = min(103, 4) = 4

// 7. Index 3:
// One step to index 4: cost[3] + dp[4] = 1 + 4 = 5
// Two steps to index 5: cost[3] + dp[5] = 1 + 102 = 103
// dp[3] = min(5, 103) = 5

// Index 2:
// One step to index 3: cost[2] + dp[3] = 1 + 5 = 6
// Two steps to index 4: cost[2] + dp[4] = 1 + 4 = 5
// dp[2] = min(6, 5) = 5

// Index 1:
// One step to index 2: cost[1] + dp[2] = 100 + 5 = 105
// Two steps to index 3: cost[1] + dp[3] = 100 + 5 = 105
// dp[1] = min(105, 105) = 105

// 10. Index 0:
// One step to index 1: cost[0] + dp[1] = 1 + 105 = 106
// Two steps to index 2: cost[0] + dp[2] = 1 + 5 = 6
// dp[0] = min(106, 6) = 6

   //  ans = min(start_from_0th_step , start_from_1th_step); (start_from_0th_step = 6, similary for the 1th step starting index)
//   the above is for iterating from the 0th index, similary for the 1th index, 