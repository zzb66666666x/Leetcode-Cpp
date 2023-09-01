class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size()==0){
            return move(ret);
        }
        int left = nums[0];
        int right = nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i-1] + 1 < nums[i]){
                if(left == right){
                    ret.push_back(to_string(left));
                }else{
                    stringstream ss;
                    ss << left << "->" << right;
                    ret.push_back(move(ss.str()));
                }
                left = nums[i];
                right = left;
            }else{
                right = nums[i];
            }
        }
        if(left == right){
            ret.push_back(to_string(left));
        }else{
            stringstream ss;
            ss << left << "->" << right;
            ret.push_back(move(ss.str()));
        }
        return move(ret);
    }
};
