class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preS(n+1, 0);
        unordered_map<int, vector<int>> m;
        for (int i=1; i<=n; i++){
            preS[i] = preS[i-1] + nums[i-1];
        }
        for (int i=0; i<=n ; i++){
            int val = preS[i];
            m[val].push_back(i);
        }
        int ret = 0;
        for (int right = 1; right <= n; right++){
            int target = preS[right] - k;
            if (m.count(target) > 0){
                auto& idx = m[target];
                auto it = lower_bound(idx.begin(), idx.end(), right);
                if (it != idx.begin()){
                    ret += (it - idx.begin());
                }
            }
        }
        return ret;
    }
};
