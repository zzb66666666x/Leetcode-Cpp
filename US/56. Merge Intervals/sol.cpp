class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b) {return a[0]<b[0];});
        vector<vector<int>> ret;
        vector<int> merge = {intervals[0][0], intervals[0][1]};
        for (auto & interval : intervals){
            if (interval[0] <= merge[1]){
                merge[1] = max(merge[1], interval[1]);
            }else{
                ret.push_back(merge);
                merge[0] = interval[0];
                merge[1] = interval[1];
            }
        }
        ret.push_back(move(merge));
        return ret;
    }
};
