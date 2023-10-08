class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int candidate1 = 0, candidate2 = 1, count1 = 0, count2 = 0;
        int n = nums.size();
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        if (count(nums.begin(), nums.end(), candidate1) > n / 3) 
            result.push_back(candidate1);
        if (count(nums.begin(), nums.end(), candidate2) > n / 3) 
            result.push_back(candidate2);
        return result;
    }
};
