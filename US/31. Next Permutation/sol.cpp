class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // STL based approach
        // next_permutation(nums.begin(), nums.end());

        // self written version
        int l = nums.size();
        int i = l-2;
        while (i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        if (i>=0){
            int j = l-1;
            while (nums[i] >= nums[j]){
                j--;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }else{
            reverse(nums.begin(), nums.end());
        }
    }
};
