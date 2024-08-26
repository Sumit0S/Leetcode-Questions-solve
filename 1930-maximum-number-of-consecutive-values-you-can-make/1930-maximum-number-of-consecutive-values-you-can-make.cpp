class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int preSum = 0;
        
        for(int coin: coins){
            if(coin <= preSum + 1){
                preSum += coin;
            }
            else break;
        }

        return preSum + 1;
    }
};