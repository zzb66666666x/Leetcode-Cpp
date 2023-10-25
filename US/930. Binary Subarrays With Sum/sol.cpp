class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> preS(n+1);
        for (int i=1; i<=n; i++){
            preS[i] = preS[i-1] + nums[i-1];
        }
        int ret = 0;
        for (int right = 1; right<=n; right++){
            int target = preS[right] - goal;
            if (target < 0){
                continue;
            }
            auto it1 = lower_bound(preS.begin(), preS.begin()+right, target);
            if (it1 != preS.end()){
                if (*it1 != target){
                    continue;
                }else{
                    auto it2 = upper_bound(preS.begin(), preS.begin()+right, target);
                    ret += (it2 - it1);
                }
            }
        }
        return ret;
    }
};
