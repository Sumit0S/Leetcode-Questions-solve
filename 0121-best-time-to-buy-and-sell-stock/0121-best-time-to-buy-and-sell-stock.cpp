class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0;
        int buy_stock= prices[0];

        for(auto it:prices){
            if(it>=buy_stock){
                profit=max(profit,it-buy_stock);
            }
            else{
                buy_stock=it;
            }
        }   
        return profit;
    }
};