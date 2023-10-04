class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n)); // row0 means having stock, row1 means no stock
        dp[0][0] = -prices[0];
        for (int i=1; i<n; i++){
            if (i>=2){
                dp[0][i] = max(dp[1][i-2]-prices[i], dp[0][i-1]);
            }else{
                dp[0][i] = max(-prices[0], -prices[1]);
            }
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] + prices[i]);
        }
        return dp[1][n-1];
    }
};
