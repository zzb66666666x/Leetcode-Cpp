// https://leetcode.cn/problems/jump-game-vi/

// method1: with priority queue
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        priority_queue<pair<int, int>> heap;
        heap.emplace(nums[0], 0);
        for (int i=1; i<n; i++){
            while (heap.size() && heap.top().second + k < i){
                heap.pop();
            }
            dp[i] = nums[i] + heap.top().first;
            heap.emplace(dp[i], i);
        }
        return dp[n-1];
    }
};
