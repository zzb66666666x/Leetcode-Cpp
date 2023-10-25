class Solution {
public:
    int minOperations(vector<int>& nums) {
        int target = nums.size() - 1;
        unordered_set<int> s(nums.begin(), nums.end());
        int ret = nums.size() - s.size();
        vector<int> unums(s.begin(), s.end());
        sort(unums.begin(), unums.end());
        int left = 0;
        int max_window = 0;
        for(int right=0; right < unums.size(); right++){
            while (unums[right] - unums[left] > target)
                left++;
            max_window = max(max_window, right-left+1);
        }
        return ret + (unums.size() - max_window);
    }
};
