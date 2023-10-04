class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int lower = *min_element(nums.begin(), nums.end());
        int upper = *max_element(nums.begin(), nums.end());
        while (lower <= upper) {
            int middle = (lower + upper) / 2;
            int count = 0;
            bool visited = false;
            for (int x : nums) {
                if (x <= middle && !visited) {
                    count++;
                    visited = true;
                } else {
                    visited = false;
                }
            }
            if (count >= k) {
                upper = middle - 1;
            } else {
                lower = middle + 1;
            }
        }
        return lower;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/house-robber-iv/solutions/2441849/da-jia-jie-she-iv-by-leetcode-solution-n93j/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
