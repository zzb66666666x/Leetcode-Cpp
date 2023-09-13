class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // O(n^2) method, dp[i] means the longest subseq so far
        // vector<int> dp(n, 1);
        // for (int i=1; i<n; i++){
        //     for (int j=0; j<i; j++){
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());

        // O(nlogn) method, greedy
        vector<int> dp;
        for (auto i: nums){
            cout<<i<<endl;
            auto p = lower_bound(dp.begin(), dp.end(), i);
            if (p == dp.end()){
                dp.emplace_back(i);
            }else{
                *p = i;
            }
        }
        return dp.size();
    }
};
