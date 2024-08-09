#include <vector>

class StockSpanner {
private:
    std::vector<int> prices;
    std::vector<int> spans;

public:
    StockSpanner() {
        // No initialization needed for the vectors
    }

    int next(int price) {
        int span = 1; // Start with a span of 1 for the current day
        int index = prices.size() - 1;

        // Traverse backward through the list of prices
        while (index >= 0 && prices[index] <= price) {
            span += spans[index];
            index -= spans[index];
           
        }

        // Store the current price and its calculated span
        prices.push_back(price);
        spans.push_back(span);

        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */