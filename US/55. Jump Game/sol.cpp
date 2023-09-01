class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        while (i < nums.size()-1){
            int steps = nums[i];
            if (steps == 0){
                cout<<"i="<<i<<endl;
                return false;
            }
            int maxnext = 0;
            int nexti = i+1;
            for (int j=1; j <= steps; j++){
                if (i + j >= nums.size()-1){
                    return true;
                }
                if (nums[i+j] >= maxnext){
                    maxnext = nums[i+j];
                    nexti = i+j;
                }
            }
            if (nexti + maxnext < i + steps) {
                i += steps;
            }else{
                i = nexti;
            }
        }
        return true;
    }
};
