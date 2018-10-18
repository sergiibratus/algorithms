class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        
        vector<int> dp(prices.size() + 1, 0);
        
        int maximum = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {           
            dp[i] = max(dp[i + 1], maximum - prices[i]);
            maximum = max(maximum, prices[i]);
        }
        
        int result = dp[0];
        int minimum = prices[0];
        int current = 0;
        for (int i = 1; i < prices.size(); i++) {
            current = max(current, prices[i] - minimum);
            minimum = min(minimum, prices[i]);
            
            result = max(result, current + dp[i + 1]);
        }

        return result;
    }
};