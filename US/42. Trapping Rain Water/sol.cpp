// method1 dp: speed O(n), space O(n)
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int ret = 0;
//         vector<int> max_left(n);
//         vector<int> max_right(n);
//         for (int i=1; i < n; i++){
//             max_left[i] = max(max_left[i-1], height[i-1]);
//         }
//         for (int i = n-2; i>=0; i--){
//             max_right[i] = max(max_right[i+1], height[i+1]);
//         }
//         for (int i = 1; i < n-1; i++){
//             int minval = min(max_left[i], max_right[i]);
//             if (height[i] < minval){
//                 ret += (minval - height[i]);
//             }
//         }
//         return ret;
//     }
// };

// method2 double pointer: speed O(n), space O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ret = 0;
        int max_left = 0;
        int max_right = 0;
        int left = 1;
        int right = n - 2;
        for (int i_ = 1; i_ < n-1; i_++){
            if (height[left - 1] < height[right+1]){
                max_left = max(max_left, height[left-1]);
                if (max_left > height[left]){
                    ret += (max_left - height[left]);
                }
                left++;
            }else{
                max_right = max(max_right, height[right+1]);
                if (max_right > height[right]){
                    ret += (max_right - height[right]);
                }
                right--;
            }
        }
        return ret;
    }
};
