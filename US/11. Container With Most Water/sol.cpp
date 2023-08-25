class Solution {
public:
    int maxArea(vector<int>& height) {
        int pl = 0;
        int pr = height.size() - 1;
        int maxval = (pr - pl) * min(height[pl], height[pr]);
        while (pr > pl){
            if (height[pl] > height[pr]){
                pr -- ;
                maxval = max(maxval, ((pr - pl) * min(height[pl], height[pr])));
            }else{
                pl ++ ;
                maxval = max(maxval, ((pr - pl) * min(height[pl], height[pr])));
            }
        }
        return maxval;
    }
};
