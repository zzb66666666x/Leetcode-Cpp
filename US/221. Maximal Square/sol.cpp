class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxval = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i==0 || j==0){
                    dp[i][j] = matrix[i][j] == '1'? 1: 0;
                    maxval = max(maxval, dp[i][j]);
                    continue;
                }
                if (matrix[i][j] == '1'){
                    int left = dp[i][j-1];
                    int up = dp[i-1][j];
                    int leftup = dp[i-1][j-1];
                    if (left == up && up == leftup && up > 0){
                        dp[i][j] = leftup + 1;
                    }else{
                        dp[i][j] = 1 + min(min(left, leftup), min(up, leftup));
                    }
                    maxval = max(maxval, dp[i][j]);
                }
            }
        }
        return maxval * maxval;
    }
};
