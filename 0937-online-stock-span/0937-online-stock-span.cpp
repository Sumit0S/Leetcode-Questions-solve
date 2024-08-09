class StockSpanner {
public:
    // Constructor
    StockSpanner() {}

    // Function to get the span of the current price
    int next(int price) {
        int span = 1;
        
        // While stack is not empty and the price at the top of the stack is <= current price
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        
        // Push the current price and its span onto the stack
        stk.push({price, span});
        
        return span;
    }

private:
    std::stack<std::pair<int, int>> stk; // Stack to store pairs of (price, span)
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */