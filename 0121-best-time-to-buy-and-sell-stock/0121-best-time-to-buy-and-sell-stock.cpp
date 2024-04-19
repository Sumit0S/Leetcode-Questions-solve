class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() <= 1) return 0;
        int local = 0, global = 0;
        for(int i = 1; i < prices.size(); i++){
            local = max(0, local + prices[i] - prices[i - 1]);
            global = max(global, local);
        }
        return global;
    }
};