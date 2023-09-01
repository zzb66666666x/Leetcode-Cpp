class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
                return a[0]<b[0];
            }
        );
        vector<int> dp(pairs.size(), 0);
        int right = pairs[0][1];
        dp[0] = 1;
        for (int i=1; i<pairs.size(); i++){
            cout<<right<<endl;
            auto& pair = pairs[i];
            if (pair[0]>right){
                right = pair[1];
                dp[i] = dp[i-1] + 1;
            }else if (pair[1] < right){
                right = pair[1];
                dp[i] = dp[i-1];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[pairs.size()-1];
    }
};

// [-1, 0],[1,10],[2,3],[4,5],[7,8]
// [-1, 0],[1,10],[1,3],[4,5],[7,8]
