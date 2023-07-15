class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        int n = events.size();
        int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++){
            auto it = lower_bound(events.begin(), events.begin()+i, events[i][0], 
                    [](auto& a, auto target){return a[1]<target;}
                );
            int idx = it - events.begin();
            for (int j=1; j<=k; j++){
                dp[i+1][j] = max(dp[i][j], dp[idx][j-1] + events[i][2]);
            }
        }
        return dp[n][k];
    }
};
