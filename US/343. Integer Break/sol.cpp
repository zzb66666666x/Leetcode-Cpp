class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for (int i=3; i<=n; i++){
            int s = 1;
            int e = i / 2;
            for (int j=s; j<=e; j++){
                int a = j;
                int b = i-j;
                int val = max(dp[a] * dp[b], max(dp[a]*b, a*dp[b]));
                dp[i] = max(dp[i], max(val, a*b));
            }
        }
        return dp[n];
    }
};
