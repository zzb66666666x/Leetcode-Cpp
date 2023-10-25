/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // find peak
        int l = 0, r = n-1;
        int peak_idx = -1;
        int peak_val = -1;
        unordered_map<int, int> m;
        while (l <= r){
            int mid = (l + r) / 2;
            int midval = mountainArr.get(mid);
            if (l == r){
                peak_idx = l;
                peak_val = midval;
                break;
            }
            int midright = mountainArr.get(mid+1);
            if (midval > midright){
                r = mid;
            }else{
                l = mid+1;
            }   
        }
        if (target > peak_val){
            return -1;
        }
        if (target == peak_val){
            return peak_idx;
        }
        // left
        l = 0, r = peak_idx-1;
        while (l <= r){
            int mid = (l + r) / 2;
            int midval = mountainArr.get(mid);
            if (midval == target){
                return mid;
            }
            if (l == r){
                break;
            }
            if (midval < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        // go to the right
        l = peak_idx+1, r = n-1;
        while (l <= r){
            int mid = (l + r) / 2;
            int midval = mountainArr.get(mid);
            if(midval == target){
                return mid;
            }
            if (l == r){
                break;
            }
            if (midval < target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }
};
