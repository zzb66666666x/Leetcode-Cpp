class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0)); // row 0 hold, row 1 not hold
        dp[0][0] = -prices[0]-fee;
        for (int i=1; i<n; i++){
            // dp[1][i]
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] + prices[i]);
            // dp[0][i]
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] - prices[i] - fee);
        }
        int maxval = 0;
        for (int idx = 0; idx < n; idx++){
            maxval = max(maxval, dp[1][idx]);
        }
        return maxval;
    }
};
