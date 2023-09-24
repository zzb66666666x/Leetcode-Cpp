class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        function<int(vector<int>&,int,int,int)> qfind = [&](vector<int>& nums, int left, int right, int k) -> int{
            if (left == right)
                return nums[left];
            int i = left, j = left;
            int pivot = nums[right];
            // cout<< left << " " <<right<< " "<<k<<" "<<pivot<<endl;
            for (; nums[i]>pivot; i++, j++){}
            while (j < right){
                if (nums[j] > pivot){
                    swap(nums[i], nums[j]);
                    i++;
                }
                j++;
            }
            swap(nums[i], nums[right]);
            if (i == k){
                return nums[k];
            }else if (i < k){
                // skip same elements with pivot
                int newleft=i+1;
                while(newleft < k && nums[newleft]==nums[newleft-1]){newleft++;}
                return qfind(nums, newleft, right, k);
            }else{
                // skip same elements with pivot
                int newright = i-1;
                while(newright > k && nums[newright]==nums[newright+1]){newright--;}
                return qfind(nums, left, i-1, k);
            }
        };
        return qfind(nums, 0, nums.size()-1, k-1);
    }
};
